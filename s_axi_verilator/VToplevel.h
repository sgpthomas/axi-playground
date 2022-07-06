// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOPLEVEL_H_
#define _VTOPLEVEL_H_  // guard

#include "verilated_heavy.h"

//==========

class VToplevel__Syms;
class VToplevel_VerilatedVcd;


//----------

VL_MODULE(VToplevel) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(ap_clk,0,0);
    VL_OUT8(ap_interrupt,0,0);
    VL_IN8(s_axi_control_awvalid,0,0);
    VL_OUT8(s_axi_control_awready,0,0);
    VL_IN8(s_axi_control_wvalid,0,0);
    VL_OUT8(s_axi_control_wready,0,0);
    VL_IN8(s_axi_control_wstrb,3,0);
    VL_OUT8(s_axi_control_bvalid,0,0);
    VL_IN8(s_axi_control_bready,0,0);
    VL_OUT8(s_axi_control_bresp,1,0);
    VL_IN8(s_axi_control_arvalid,0,0);
    VL_OUT8(s_axi_control_arready,0,0);
    VL_OUT8(s_axi_control_rvalid,0,0);
    VL_IN8(s_axi_control_rready,0,0);
    VL_OUT8(s_axi_control_rresp,1,0);
    VL_OUT8(m00_axi_awvalid,0,0);
    VL_IN8(m00_axi_awready,0,0);
    VL_OUT8(m00_axi_awlen,7,0);
    VL_OUT8(m00_axi_wvalid,0,0);
    VL_IN8(m00_axi_wready,0,0);
    VL_OUT8(m00_axi_wstrb,3,0);
    VL_OUT8(m00_axi_wlast,0,0);
    VL_IN8(m00_axi_bvalid,0,0);
    VL_OUT8(m00_axi_bready,0,0);
    VL_OUT8(m00_axi_arvalid,0,0);
    VL_IN8(m00_axi_arready,0,0);
    VL_OUT8(m00_axi_arlen,7,0);
    VL_IN8(m00_axi_rvalid,0,0);
    VL_OUT8(m00_axi_rready,0,0);
    VL_IN8(m00_axi_rlast,0,0);
    VL_IN16(s_axi_control_awaddr,11,0);
    VL_IN16(s_axi_control_araddr,11,0);
    VL_IN(s_axi_control_wdata,31,0);
    VL_OUT(s_axi_control_rdata,31,0);
    VL_OUT(m00_axi_wdata,31,0);
    VL_IN(m00_axi_rdata,31,0);
    VL_OUT64(m00_axi_awaddr,63,0);
    VL_OUT64(m00_axi_araddr,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ Toplevel__DOT__ap_done;
    CData/*3:0*/ Toplevel__DOT__A_wr_state;
    CData/*3:0*/ Toplevel__DOT__A_wr_next;
    CData/*7:0*/ Toplevel__DOT__A_wr_addr;
    CData/*1:0*/ Toplevel__DOT__inst_control_axi__DOT__wstate;
    CData/*1:0*/ Toplevel__DOT__inst_control_axi__DOT__wnext;
    CData/*5:0*/ Toplevel__DOT__inst_control_axi__DOT__waddr;
    CData/*0:0*/ Toplevel__DOT__inst_control_axi__DOT__w_hs;
    CData/*1:0*/ Toplevel__DOT__inst_control_axi__DOT__rstate;
    CData/*1:0*/ Toplevel__DOT__inst_control_axi__DOT__rnext;
    CData/*0:0*/ Toplevel__DOT__inst_control_axi__DOT__ar_hs;
    CData/*0:0*/ Toplevel__DOT__inst_control_axi__DOT__int_ap_start;
    CData/*0:0*/ Toplevel__DOT__inst_control_axi__DOT__int_ap_done;
    CData/*0:0*/ Toplevel__DOT__inst_control_axi__DOT__int_gie;
    CData/*1:0*/ Toplevel__DOT__inst_control_axi__DOT__int_ier;
    CData/*1:0*/ Toplevel__DOT__inst_control_axi__DOT__int_isr;
    IData/*31:0*/ Toplevel__DOT__counter;
    IData/*31:0*/ Toplevel__DOT__inst_control_axi__DOT__wmask;
    IData/*31:0*/ Toplevel__DOT__inst_control_axi__DOT__rdata;
    IData/*31:0*/ Toplevel__DOT__inst_control_axi__DOT__int_scalar00;
    QData/*63:0*/ Toplevel__DOT__inst_control_axi__DOT__int_A;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx1;
    CData/*4:0*/ __Vtableidx2;
    CData/*0:0*/ __Vclklast__TOP__ap_clk;
    CData/*0:0*/ __Vm_traceActivity[3];
    static CData/*3:0*/ __Vtable1_Toplevel__DOT__A_wr_next[128];
    static CData/*1:0*/ __Vtable2_Toplevel__DOT__inst_control_axi__DOT__wnext[32];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VToplevel__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VToplevel);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VToplevel(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VToplevel();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(VToplevel__Syms* __restrict vlSymsp);
    void __Vconfigure(VToplevel__Syms* symsp, bool first);
  private:
    static QData _change_request(VToplevel__Syms* __restrict vlSymsp);
    static QData _change_request_1(VToplevel__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(VToplevel__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VToplevel__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VToplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VToplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VToplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VToplevel__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VToplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
