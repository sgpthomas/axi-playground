`default_nettype none
// `timescale 1ns / 1ps

module Toplevel
  #(parameter integer C_S_AXI_ADDR_WIDTH = 12,
    parameter integer C_S_AXI_DATA_WIDTH = 32,
    parameter integer M00_AXI_ADDR_WIDTH = 64,
    parameter integer M00_AXI_DATA_WIDTH = 32 /* original 512 */)
   (
    // system signals
    input wire                             ap_clk,
    output wire                            ap_interrupt,

    //////////// AXI4-lite slave interface //////////////
    //////////// this is the thing that let's us be
    //////////// called from software
    // write address channel
    input wire                             s_axi_control_awvalid,
    output wire                            s_axi_control_awready,
    input wire [C_S_AXI_ADDR_WIDTH-1:0]    s_axi_control_awaddr,

    // write data channel
    input wire                             s_axi_control_wvalid,
    output wire                            s_axi_control_wready,
    input wire [C_S_AXI_DATA_WIDTH-1:0]    s_axi_control_wdata,
    input wire [C_S_AXI_DATA_WIDTH/8-1:0]  s_axi_control_wstrb, // ?? is this needed

    // write response channel
    output wire                            s_axi_control_bvalid,
    input wire                             s_axi_control_bready,
    output wire [2-1:0]                    s_axi_control_bresp,

    // read address channel
    input wire                             s_axi_control_arvalid,
    output wire                            s_axi_control_arready,
    input wire [C_S_AXI_ADDR_WIDTH-1:0]    s_axi_control_araddr,

    // read data channel
    output wire                            s_axi_control_rvalid,
    input wire                             s_axi_control_rready,
    output wire [C_S_AXI_DATA_WIDTH-1:0]   s_axi_control_rdata,
    output wire [2-1:0]                    s_axi_control_rresp,

    //////////// AXI4-lite master interface //////////////
   // write address channel
    output wire                            m00_axi_awvalid,
    input wire                             m00_axi_awready,
    output wire [M00_AXI_ADDR_WIDTH-1:0]   m00_axi_awaddr,
    output wire [8-1:0]                    m00_axi_awlen,

    // write data channel
    output wire                            m00_axi_wvalid,
    input wire                             m00_axi_wready,
    output wire [M00_AXI_DATA_WIDTH-1:0]   m00_axi_wdata,
    output wire [M00_AXI_DATA_WIDTH/8-1:0] m00_axi_wstrb,
    output wire                            m00_axi_wlast,

    // write response channel
    input wire                             m00_axi_bvalid,
    output wire                            m00_axi_bready,

    // read address channel
    output wire                            m00_axi_arvalid,
    input wire                             m00_axi_arready,
    output wire [M00_AXI_ADDR_WIDTH-1:0]   m00_axi_araddr,
    output wire [8-1:0]                    m00_axi_arlen,

    // read data channel
    input wire                             m00_axi_rvalid,
    output wire                            m00_axi_rready,
    input wire [M00_AXI_DATA_WIDTH-1:0]    m00_axi_rdata,
    input wire                             m00_axi_rlast

    // end
    );

   localparam ARESET = 1'b0;
   localparam ACLK_EN = 1'b1;

   wire                                    ap_start;
   wire                                    ap_done;
   wire [31:0]                             scalar00;
   wire [63:0]                             A;

   // AXI4-Lite slave control interface
   Control_axi_interface
     #(.ADDR_WIDTH (C_S_AXI_ADDR_WIDTH),
       .DATA_WIDTH (C_S_AXI_DATA_WIDTH))
   inst_control_axi
     (.ACLK(ap_clk),
      .ARESET(ARESET),
      .ACLK_EN(ACLK_EN),
      .AWVALID(s_axi_control_awvalid),
      .AWREADY(s_axi_control_awready),
      .AWADDR(s_axi_control_awaddr),
      .WVALID(s_axi_control_wvalid),
      .WREADY(s_axi_control_wready),
      .WDATA(s_axi_control_wdata),
      .WSTRB(s_axi_control_wstrb),
      .BVALID(s_axi_control_bvalid),
      .BREADY(s_axi_control_bready),
      .BRESP(s_axi_control_bresp),
      .ARVALID(s_axi_control_arvalid),
      .ARREADY(s_axi_control_arready),
      .ARADDR(s_axi_control_araddr),
      .RVALID(s_axi_control_rvalid),
      .RREADY(s_axi_control_rready),
      .RDATA(s_axi_control_rdata),
      .RRESP(s_axi_control_rresp),
      .interrupt(ap_interrupt),
      .ap_start(ap_start),
      .ap_done(ap_done),
      .scalar00(scalar00),
      .A(A));

   //------------------------Application logic-----------------
   assign ap_done = (ap_start && (A_wr_data == scalar00 | counter == (scalar00 << 4)));
   reg [31:0]                              counter;
   always @(posedge ap_clk) begin
      if (ARESET)
        counter <= 32'd0;
      else begin
         if (ap_start)
           counter <= counter + 32'd1;
         else
           counter <= counter;
      end
   end

   //------------------------write to A-----------------
   localparam A_WR_RESET = 4'd0;
   localparam A_WR_IDLE = 4'd1;
   localparam A_WR_DATA = 4'd2;
   localparam A_WR_RESP = 4'd3;

   reg [3:0] A_wr_state = A_WR_RESET;
   reg [3:0] A_wr_next = 'b0;
   reg [M00_AXI_DATA_WIDTH-1:0] A_wr_data = 'b0;
   reg [7:0] A_wr_addr = 'b0;

   always @(posedge ap_clk) begin
      if (ARESET)
        A_wr_state <= A_WR_RESET;
      else if (ap_start)
        A_wr_state <= A_wr_next;
      else
        A_wr_state <= A_wr_state;
   end

   always @(*) begin
      case (A_wr_state)
        A_WR_IDLE:
           if (m00_axi_awready)
             A_wr_next = A_WR_DATA;
           else
             A_wr_next = A_WR_IDLE;
        A_WR_DATA:
           if (m00_axi_wready)
             A_wr_next = A_WR_RESP;
           else
             A_wr_next = A_WR_DATA;
        A_WR_RESP:
          if (m00_axi_bvalid)
            A_wr_next = A_WR_IDLE;
          else
            A_wr_next = A_WR_RESP;
        default:
          A_wr_next = A_WR_IDLE;
      endcase
   end

   always @(posedge ap_clk) begin
      if (ARESET)
        A_wr_addr <= 'b0;
      else if (A_wr_state == A_WR_RESP)
        A_wr_addr <= A_wr_addr + 1;
      else
        A_wr_addr <= A_wr_addr;
   end

   // write address channel
   assign m00_axi_awvalid = (A_wr_state == A_WR_IDLE);
   assign m00_axi_awaddr = A + ({{56{1'b0}}, A_wr_addr} << 2);
   assign m00_axi_awlen = 'b0;

   assign m00_axi_wvalid = (A_wr_state == A_WR_DATA);
   assign m00_axi_wdata = {{24{1'b0}}, A_wr_addr};
   assign m00_axi_wstrb = {M00_AXI_DATA_WIDTH/8{1'd1}};
   assign m00_axi_wlast = 'b1;

   assign m00_axi_bready = (A_wr_state == A_WR_RESP);

   // we're not doing any reading so keep these low
   assign m00_axi_arvalid = 'b0;
   assign m00_axi_araddr = 'b0;
   assign m00_axi_arlen = 'b0;
   assign m00_axi_rready = 'b0;

endmodule
`default_nettype wire
