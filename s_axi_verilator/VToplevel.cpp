// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VToplevel.h for the primary calling header

#include "VToplevel.h"
#include "VToplevel__Syms.h"

//==========

void VToplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VToplevel::eval\n"); );
    VToplevel__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/IP/top_level.v", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VToplevel::_eval_initial_loop(VToplevel__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/IP/top_level.v", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VToplevel::_sequent__TOP__2(VToplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VToplevel::_sequent__TOP__2\n"); );
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr;
    IData/*31:0*/ __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_scalar00;
    QData/*63:0*/ __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_A;
    // Body
    __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_scalar00 
        = vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00;
    __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_A 
        = vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A;
    __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr 
        = vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr;
    if (((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
         & (0x10U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr)))) {
        __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_scalar00 
            = ((vlTOPp->s_axi_control_wdata & vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask) 
               | (vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00 
                  & (~ vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask)));
    }
    vlTOPp->Toplevel__DOT__A_wr_addr = (0xffU & ((3U 
                                                  == (IData)(vlTOPp->Toplevel__DOT__A_wr_state))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + (IData)(vlTOPp->Toplevel__DOT__A_wr_addr))
                                                  : (IData)(vlTOPp->Toplevel__DOT__A_wr_addr)));
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wstate 
        = vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wnext;
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate 
        = vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rnext;
    vlTOPp->Toplevel__DOT__counter = ((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start)
                                       ? ((IData)(1U) 
                                          + vlTOPp->Toplevel__DOT__counter)
                                       : vlTOPp->Toplevel__DOT__counter);
    if (((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
         & (0x18U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr)))) {
        __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_A 
            = ((0xffffffff00000000ULL & __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_A) 
               | (IData)((IData)(((vlTOPp->s_axi_control_wdata 
                                   & vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask) 
                                  | ((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A) 
                                     & (~ vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask))))));
    }
    if (((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
         & (0x1cU == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr)))) {
        __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_A 
            = ((0xffffffffULL & __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_A) 
               | ((QData)((IData)(((vlTOPp->s_axi_control_wdata 
                                    & vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask) 
                                   | ((IData)((vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A 
                                               >> 0x20U)) 
                                      & (~ vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask))))) 
                  << 0x20U));
    }
    vlTOPp->Toplevel__DOT__A_wr_state = ((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start)
                                          ? (IData)(vlTOPp->Toplevel__DOT__A_wr_next)
                                          : (IData)(vlTOPp->Toplevel__DOT__A_wr_state));
    if (((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ier) 
         & (IData)(vlTOPp->Toplevel__DOT__ap_done))) {
        __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr 
            = (1U | (IData)(__Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr));
    } else {
        if ((((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
              & (0xcU == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr))) 
             & (IData)(vlTOPp->s_axi_control_wstrb))) {
            __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr 
                = ((2U & (IData)(__Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr)) 
                   | (1U & ((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr) 
                            ^ vlTOPp->s_axi_control_wdata)));
        }
    }
    if ((((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ier) 
          >> 1U) & (IData)(vlTOPp->Toplevel__DOT__ap_done))) {
        __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr 
            = (2U | (IData)(__Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr));
    } else {
        if ((((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
              & (0xcU == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr))) 
             & (IData)(vlTOPp->s_axi_control_wstrb))) {
            __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr 
                = ((1U & (IData)(__Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr)) 
                   | (2U & ((0xfffffffeU & (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr)) 
                            ^ (0xfffffffeU & vlTOPp->s_axi_control_wdata))));
        }
    }
    if (vlTOPp->Toplevel__DOT__inst_control_axi__DOT__ar_hs) {
        vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata = 0U;
        if ((0x20U & (IData)(vlTOPp->s_axi_control_araddr))) {
            vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata = 0U;
        } else {
            if ((0x10U & (IData)(vlTOPp->s_axi_control_araddr))) {
                vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata 
                    = ((8U & (IData)(vlTOPp->s_axi_control_araddr))
                        ? ((4U & (IData)(vlTOPp->s_axi_control_araddr))
                            ? ((2U & (IData)(vlTOPp->s_axi_control_araddr))
                                ? 0U : ((1U & (IData)(vlTOPp->s_axi_control_araddr))
                                         ? 0U : (IData)(
                                                        (vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A 
                                                         >> 0x20U))))
                            : ((2U & (IData)(vlTOPp->s_axi_control_araddr))
                                ? 0U : ((1U & (IData)(vlTOPp->s_axi_control_araddr))
                                         ? 0U : (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A))))
                        : ((4U & (IData)(vlTOPp->s_axi_control_araddr))
                            ? 0U : ((2U & (IData)(vlTOPp->s_axi_control_araddr))
                                     ? 0U : ((1U & (IData)(vlTOPp->s_axi_control_araddr))
                                              ? 0U : vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00))));
            } else {
                if ((8U & (IData)(vlTOPp->s_axi_control_araddr))) {
                    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata 
                        = ((4U & (IData)(vlTOPp->s_axi_control_araddr))
                            ? ((2U & (IData)(vlTOPp->s_axi_control_araddr))
                                ? 0U : ((1U & (IData)(vlTOPp->s_axi_control_araddr))
                                         ? 0U : (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr)))
                            : ((2U & (IData)(vlTOPp->s_axi_control_araddr))
                                ? 0U : ((1U & (IData)(vlTOPp->s_axi_control_araddr))
                                         ? 0U : (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ier))));
                } else {
                    if ((4U & (IData)(vlTOPp->s_axi_control_araddr))) {
                        vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata 
                            = ((2U & (IData)(vlTOPp->s_axi_control_araddr))
                                ? 0U : ((1U & (IData)(vlTOPp->s_axi_control_araddr))
                                         ? 0U : (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_gie)));
                    } else {
                        if ((2U & (IData)(vlTOPp->s_axi_control_araddr))) {
                            vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata = 0U;
                        } else {
                            if ((1U & (IData)(vlTOPp->s_axi_control_araddr))) {
                                vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata = 0U;
                            } else {
                                vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata 
                                    = ((0xfffffffeU 
                                        & vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata) 
                                       | (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start));
                                vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata 
                                    = ((0xfffffffdU 
                                        & vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata) 
                                       | ((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_done) 
                                          << 1U));
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A 
        = __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_A;
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr 
        = __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_isr;
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00 
        = __Vdly__Toplevel__DOT__inst_control_axi__DOT__int_scalar00;
    vlTOPp->m00_axi_wdata = vlTOPp->Toplevel__DOT__A_wr_addr;
    vlTOPp->s_axi_control_bvalid = (2U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wstate));
    vlTOPp->s_axi_control_wready = (1U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wstate));
    vlTOPp->s_axi_control_arready = (0U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate));
    vlTOPp->s_axi_control_rvalid = (1U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate));
    vlTOPp->m00_axi_awvalid = (1U == (IData)(vlTOPp->Toplevel__DOT__A_wr_state));
    vlTOPp->m00_axi_wvalid = (2U == (IData)(vlTOPp->Toplevel__DOT__A_wr_state));
    vlTOPp->m00_axi_bready = (3U == (IData)(vlTOPp->Toplevel__DOT__A_wr_state));
    vlTOPp->s_axi_control_rdata = vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata;
    vlTOPp->m00_axi_awaddr = (vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A 
                              + ((QData)((IData)(vlTOPp->Toplevel__DOT__A_wr_addr)) 
                                 << 2U));
    if (vlTOPp->Toplevel__DOT__ap_done) {
        vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_done = 1U;
    } else {
        if (((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__ar_hs) 
             & (0U == (0x3fU & (IData)(vlTOPp->s_axi_control_araddr))))) {
            vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_done = 0U;
        }
    }
    if ((((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
          & (8U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr))) 
         & (IData)(vlTOPp->s_axi_control_wstrb))) {
        vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ier 
            = (3U & vlTOPp->s_axi_control_wdata);
    }
    if ((((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
          & (4U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr))) 
         & (IData)(vlTOPp->s_axi_control_wstrb))) {
        vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_gie 
            = (1U & vlTOPp->s_axi_control_wdata);
    }
    if (((((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs) 
           & (0U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr))) 
          & vlTOPp->s_axi_control_wdata) & (IData)(vlTOPp->s_axi_control_wstrb))) {
        vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start = 1U;
    } else {
        if (vlTOPp->Toplevel__DOT__ap_done) {
            vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start = 0U;
        }
    }
    vlTOPp->ap_interrupt = ((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_gie) 
                            & (0U != (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr)));
    vlTOPp->Toplevel__DOT__ap_done = ((IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start) 
                                      & ((0U == vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00) 
                                         | (vlTOPp->Toplevel__DOT__counter 
                                            == (vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00 
                                                << 2U))));
    if (((IData)(vlTOPp->s_axi_control_awvalid) & (IData)(vlTOPp->s_axi_control_awready))) {
        vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr 
            = (0x3fU & (IData)(vlTOPp->s_axi_control_awaddr));
    }
    vlTOPp->s_axi_control_awready = (0U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wstate));
}

VL_INLINE_OPT void VToplevel::_combo__TOP__4(VToplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VToplevel::_combo__TOP__4\n"); );
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask 
        = ((0xff000000U & ((- (IData)((1U & ((IData)(vlTOPp->s_axi_control_wstrb) 
                                             >> 3U)))) 
                           << 0x18U)) | ((0xff0000U 
                                          & ((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlTOPp->s_axi_control_wstrb) 
                                                            >> 2U)))) 
                                             << 0x10U)) 
                                         | ((0xff00U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlTOPp->s_axi_control_wstrb) 
                                                               >> 1U)))) 
                                                << 8U)) 
                                            | (0xffU 
                                               & (- (IData)(
                                                            (1U 
                                                             & (IData)(vlTOPp->s_axi_control_wstrb))))))));
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->s_axi_control_bready) 
                             << 4U) | (((IData)(vlTOPp->s_axi_control_wvalid) 
                                        << 3U) | (((IData)(vlTOPp->s_axi_control_awvalid) 
                                                   << 2U) 
                                                  | (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wstate))));
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wnext 
        = vlTOPp->__Vtable2_Toplevel__DOT__inst_control_axi__DOT__wnext
        [vlTOPp->__Vtableidx2];
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->m00_axi_bvalid) 
                             << 6U) | (((IData)(vlTOPp->m00_axi_wready) 
                                        << 5U) | (((IData)(vlTOPp->m00_axi_awready) 
                                                   << 4U) 
                                                  | (IData)(vlTOPp->Toplevel__DOT__A_wr_state))));
    vlTOPp->Toplevel__DOT__A_wr_next = vlTOPp->__Vtable1_Toplevel__DOT__A_wr_next
        [vlTOPp->__Vtableidx1];
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rnext 
        = ((0U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate))
            ? ((IData)(vlTOPp->s_axi_control_arvalid)
                ? 1U : 0U) : ((1U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate))
                               ? (((IData)(vlTOPp->s_axi_control_rready) 
                                   & (IData)(vlTOPp->s_axi_control_rvalid))
                                   ? 0U : 1U) : 0U));
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__ar_hs 
        = ((IData)(vlTOPp->s_axi_control_arvalid) & (IData)(vlTOPp->s_axi_control_arready));
    vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs 
        = ((IData)(vlTOPp->s_axi_control_wvalid) & (IData)(vlTOPp->s_axi_control_wready));
}

void VToplevel::_eval(VToplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VToplevel::_eval\n"); );
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->ap_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__ap_clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    // Final
    vlTOPp->__Vclklast__TOP__ap_clk = vlTOPp->ap_clk;
}

VL_INLINE_OPT QData VToplevel::_change_request(VToplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VToplevel::_change_request\n"); );
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VToplevel::_change_request_1(VToplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VToplevel::_change_request_1\n"); );
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VToplevel::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VToplevel::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ap_clk & 0xfeU))) {
        Verilated::overWidthError("ap_clk");}
    if (VL_UNLIKELY((s_axi_control_awvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_control_awvalid");}
    if (VL_UNLIKELY((s_axi_control_awaddr & 0xf000U))) {
        Verilated::overWidthError("s_axi_control_awaddr");}
    if (VL_UNLIKELY((s_axi_control_wvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_control_wvalid");}
    if (VL_UNLIKELY((s_axi_control_wstrb & 0xf0U))) {
        Verilated::overWidthError("s_axi_control_wstrb");}
    if (VL_UNLIKELY((s_axi_control_bready & 0xfeU))) {
        Verilated::overWidthError("s_axi_control_bready");}
    if (VL_UNLIKELY((s_axi_control_arvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_control_arvalid");}
    if (VL_UNLIKELY((s_axi_control_araddr & 0xf000U))) {
        Verilated::overWidthError("s_axi_control_araddr");}
    if (VL_UNLIKELY((s_axi_control_rready & 0xfeU))) {
        Verilated::overWidthError("s_axi_control_rready");}
    if (VL_UNLIKELY((m00_axi_awready & 0xfeU))) {
        Verilated::overWidthError("m00_axi_awready");}
    if (VL_UNLIKELY((m00_axi_wready & 0xfeU))) {
        Verilated::overWidthError("m00_axi_wready");}
    if (VL_UNLIKELY((m00_axi_bvalid & 0xfeU))) {
        Verilated::overWidthError("m00_axi_bvalid");}
    if (VL_UNLIKELY((m00_axi_arready & 0xfeU))) {
        Verilated::overWidthError("m00_axi_arready");}
    if (VL_UNLIKELY((m00_axi_rvalid & 0xfeU))) {
        Verilated::overWidthError("m00_axi_rvalid");}
    if (VL_UNLIKELY((m00_axi_rlast & 0xfeU))) {
        Verilated::overWidthError("m00_axi_rlast");}
}
#endif  // VL_DEBUG
