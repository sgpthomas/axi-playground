`default_nettype none
// `timescale 1ns / 1ps

module Control_axi_interface
  #(parameter integer ADDR_WIDTH = 12,
    parameter integer DATA_WIDTH = 32)
   (// system signals
    input wire                    ACLK,
    input wire                    ARESET,
    input wire                    ACLK_EN,

    // write address channel
    input wire                    AWVALID,
    output wire                   AWREADY,
    input wire [ADDR_WIDTH-1:0]   AWADDR,

    // write data channel
    input wire                    WVALID,
    output wire                   WREADY,
    input wire [DATA_WIDTH-1:0]   WDATA,
    input wire [DATA_WIDTH/8-1:0] WSTRB,

    // write response channel
    output wire                   BVALID,
    input wire                    BREADY,
    output wire [2-1:0]           BRESP,

    // read address channel
    input wire                    ARVALID,
    output wire                   ARREADY,
    input wire [ADDR_WIDTH-1:0]   ARADDR,

    // read data channel
    output wire                   RVALID,
    input wire                    RREADY,
    output wire [DATA_WIDTH-1:0]  RDATA,
    output wire [2-1:0]           RRESP,

    // control signals
    output wire                   interrupt,
    output wire                   ap_start,
    input wire                    ap_done,

    // kernel arguments
    output wire [31:0]            scalar00,
    output wire [63:0]            A
    // end
    );

   //------------------------Address Info-------------------
   // 0x00 : Control signals
   //        bit 0  - ap_start (Read/Write/COH)
   //        bit 1  - ap_done (Read/COR)
   //        bit 2  - ap_idle (Read)
   //        others - reserved
   // 0x04 : Global Interrupt Enable Register
   //        bit 0  - Global Interrupt Enable (Read/Write)
   //        others - reserved
   // 0x08 : IP Interrupt Enable Register (Read/Write)
   //        bit 0  - Channel 0 (ap_done)
   //        bit 1  - Channel 1 (ap_ready)
   //        others - reserved
   // 0x0c : IP Interrupt Status Register (Read/TOW)
   //        bit 0  - Channel 0 (ap_done)
   //        bit 1  - Channel 1 (ap_ready)
   //        others - reserved
   // 0x10 : Data signal of scalar00
   //        bit 31~0 - scalar00[31:0] (Read/Write)
   // 0x14 : reserved
   // 0x18 : Address of A, bits [31:0]
   // 0x1c : Address of A, bits [63:32]
   // (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

   //------------------------Parameters----------------------
   localparam
     ADDR_AP_CTRL         = 6'h00, // defines application control interface
     ADDR_GIE             = 6'h04, // global interrupt enable register
     ADDR_IER             = 6'h08, // IP interrupt enable register
     ADDR_ISR             = 6'h0c, // interrupt status register
     ADDR_SCALAR00_DATA_0 = 6'h10, // data signal of scalar00[31:0] (read/write)
     ADDR_SCALAR00_CTRL   = 6'h14, // control signal
     ADDR_A_0             = 6'h18, // address of A
     ADDR_A_1             = 6'h1c,

     // write fsm states
     WRIDLE               = 2'd0,
     WRDATA               = 2'd1,
     WRRESP               = 2'd2,
     WRRESET              = 2'd3,

     // read fsm states
     RDIDLE               = 2'd0,
     RDDATA               = 2'd1,
     RDRESET              = 2'd2,

     ADDR_BITS            = 6;

   //------------------------Local signal-------------------
   reg [1:0]                            wstate = WRRESET; // write fsm state
   reg [1:0]                            wnext; // next state for write fsm
   reg [ADDR_BITS-1:0]                  waddr; // write address
   wire [31:0]                          wmask; // valid bits for write data

   wire                                 aw_hs; // address write hand shake
   wire                                 w_hs; // write hand shake

   reg [1:0]                            rstate = RDRESET; // read fsm state
   reg [1:0]                            rnext; // next fsm state for read fsm
   reg [31:0]                           rdata; // read data
   wire [ADDR_BITS-1:0]                 raddr; // read address
   wire                                 ar_hs; // address read hand shake

   // internal registers
   reg                                  int_ap_start = 1'b0;
   reg                                  int_ap_done = 1'b0;
   reg                                  int_gie = 1'b0;
   reg [1:0]                            int_ier = 2'b0;
   reg [1:0]                            int_isr = 2'b0;
   // generated
   reg [31:0]                           int_scalar00 = 32'b0;
   reg [63:0]                           int_A = 'd0;

   //------------------------AXI write fsm------------------
   assign AWREADY = (wstate == WRIDLE); // ready to receive addresses when write fsm is idle
   assign WREADY = (wstate == WRDATA); // ready to get data in write fsm state 2
   assign BRESP = 2'b00; // keep this low (???)
   assign BVALID = (wstate == WRRESP); // done performing write, respond on response channel
   // write strobing nonsense (see if I can remove this)
   assign wmask   = { {8{WSTRB[3]}}, {8{WSTRB[2]}}, {8{WSTRB[1]}}, {8{WSTRB[0]}} };
   assign aw_hs = AWVALID & AWREADY; // write address can be performed when valid and ready are high for that channel
   assign w_hs = WVALID & WREADY;

   // wstate (transition fsm to wnext)
   always @(posedge ACLK) begin
      if (ARESET)
        wstate <= WRRESET;
      else if (ACLK_EN)
        wstate <= wnext;
   end

   // wnext
   always @(*) begin
      case (wstate)
        WRIDLE:
          if (AWVALID)
            wnext = WRDATA;
          else
            wnext = WRIDLE;
        WRDATA:
          if (WVALID)
            wnext = WRRESP;
          else
            wnext = WRDATA;
        WRRESP:
          if (BREADY)
            wnext = WRIDLE;
          else
            wnext = WRRESP;
        default:
          wnext = WRIDLE;
      endcase
   end

   // waddr
   always @(posedge ACLK) begin
      if (ARESET)
        waddr <= 'b0;
      else if (ACLK_EN) begin
         if (aw_hs)
           waddr <= AWADDR[ADDR_BITS-1:0];
      end
   end

   //------------------------AXI read fsm-------------------
   assign ARREADY = (rstate == RDIDLE); // addr ready when read fsm is idle
   assign RVALID = (rstate == RDDATA); // valid when in read data state

   assign raddr = ARADDR[ADDR_BITS-1:0];
   assign RDATA = rdata; // output data
   assign RRESP = 2'b00; // OKAY

   assign ar_hs = ARVALID & ARREADY;

   // rstate
   always @(posedge ACLK) begin
      if (ARESET)
        rstate <= RDRESET;
      else if (ACLK_EN)
        rstate <= rnext;
   end

   // rnext
   always @(*) begin
      case (rstate)
        RDIDLE:
           if (ARVALID)
             rnext = RDDATA;
           else
             rnext = RDIDLE;
        RDDATA:
          if (RREADY & RVALID) // can't I just look at ready here?
            rnext = RDIDLE;
          else
            rnext = RDDATA;
        default:
          rnext = RDIDLE;
      endcase
   end

   // rdata
   always @(posedge ACLK) begin
      if (ACLK_EN) begin
         if (ar_hs) begin
            rdata <= 32'd0;
            case (raddr)
              ADDR_AP_CTRL: begin
                 rdata[0] <= int_ap_start;
                 rdata[1] <= int_ap_done;
              end
              ADDR_GIE: begin
                 rdata <= {{31{1'b0}}, int_gie};
              end
              ADDR_IER: begin
                 rdata <= {{30{1'b0}}, int_ier};
              end
              ADDR_ISR: begin
                 rdata <= {{30{1'b0}}, int_isr};
              end
              ADDR_SCALAR00_DATA_0: begin
                 rdata <= int_scalar00[31:0];
              end
              ADDR_A_0: begin
                 rdata <= int_A[31:0];
              end
              ADDR_A_1: begin
                 rdata <= int_A[63:32];
              end
              default: begin
                 rdata <= 32'd0;
              end
            endcase
         end
      end
   end

   //------------------------Register logic-----------------
   assign interrupt = int_gie & (|int_isr);
   assign ap_start = int_ap_start;
   assign scalar00 = int_scalar00;
   assign A = int_A;

   // int_ap_start
   always @(posedge ACLK) begin
      if (ARESET)
        int_ap_start <= 1'b0;
      else if (ACLK_EN) begin
         if (w_hs && waddr == ADDR_AP_CTRL && WDATA[0] && WSTRB[0])
           int_ap_start <= 1'b1;
         else if (ap_done)
           int_ap_start <= 1'b0; // clear on handshake
      end
   end

   // int_ap_done
   always @(posedge ACLK) begin
      if (ARESET)
        int_ap_done <= 1'b0;
      else if (ACLK_EN) begin
         if (ap_done)
           int_ap_done <= 1'b1;
         else if (ar_hs && raddr == ADDR_AP_CTRL)
           int_ap_done <= 1'b0; // clear on read
      end
   end

   // int_gie
   always @(posedge ACLK) begin
      if (ARESET)
        int_gie <= 1'b0;
      else if (ACLK_EN) begin
         if (w_hs && waddr == ADDR_GIE && WSTRB[0])
           int_gie <= WDATA[0];
      end
   end

   // int_ier
   always @(posedge ACLK) begin
      if (ARESET)
        int_ier[0] <= 1'b0;
      else if (ACLK_EN) begin
         if (w_hs && waddr == ADDR_IER && WSTRB[0])
           int_ier <= WDATA[1:0];
      end
   end

   // int_isr[0]
   always @(posedge ACLK) begin
      if (ARESET)
        int_isr[0] <= 1'b0;
      else if (ACLK_EN) begin
         if (int_ier[0] & ap_done)
           int_isr[0] <= 1'b1;
         else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
           int_isr[0] <= int_isr[0] ^ WDATA[0]; // toggle on write
      end
   end

   // int_isr[1]
   always @(posedge ACLK) begin
      if (ARESET)
        int_isr[1] <= 1'b0;
      else if (ACLK_EN) begin
         if (int_ier[1] & ap_done)
           int_isr[1] <= 1'b1;
         else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
           int_isr[1] <= int_isr[1] ^ WDATA[1]; // toggle on write
      end
   end

   // int_scalar00
   always @(posedge ACLK) begin
      if (ARESET)
        int_scalar00[31:0] <= 'd0;
      else if (ACLK_EN) begin
         if (w_hs && waddr == ADDR_SCALAR00_DATA_0)
           int_scalar00[31:0] <= (WDATA[31:0] & wmask) | (int_scalar00[31:0] & ~wmask);
      end
   end

   // int_A[31:0]
   always @(posedge ACLK) begin
      if (ARESET)
        int_A[31:0] <= 0;
      else if (ACLK_EN) begin
         if (w_hs && waddr == ADDR_A_0)
           int_A[31:0] <= (WDATA[31:0] & wmask) | (int_A[31:0] & ~wmask);
      end
   end

   // int_A[63:32]
   always @(posedge ACLK) begin
      if (ARESET)
        int_A[31:0] <= 0;
      else begin
         if (w_hs && waddr == ADDR_A_1)
           int_A[63:32] <= (WDATA[31:0] & wmask) | (int_A[63:32] & ~wmask);
      end
   end

endmodule

`default_nettype wire
