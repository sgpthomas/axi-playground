// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VToplevel__Syms.h"


void VToplevel::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VToplevel::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start));
            tracep->chgBit(oldp+1,(vlTOPp->Toplevel__DOT__ap_done));
            tracep->chgIData(oldp+2,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00),32);
            tracep->chgQData(oldp+3,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A),64);
            tracep->chgIData(oldp+5,(vlTOPp->Toplevel__DOT__counter),32);
            tracep->chgCData(oldp+6,(vlTOPp->Toplevel__DOT__A_wr_state),4);
            tracep->chgCData(oldp+7,(vlTOPp->Toplevel__DOT__A_wr_addr),8);
            tracep->chgCData(oldp+8,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wstate),2);
            tracep->chgCData(oldp+9,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr),6);
            tracep->chgCData(oldp+10,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate),2);
            tracep->chgIData(oldp+11,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata),32);
            tracep->chgBit(oldp+12,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_done));
            tracep->chgBit(oldp+13,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_gie));
            tracep->chgCData(oldp+14,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ier),2);
            tracep->chgCData(oldp+15,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr),2);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+16,(vlTOPp->Toplevel__DOT__A_wr_next),4);
            tracep->chgCData(oldp+17,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wnext),2);
            tracep->chgIData(oldp+18,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask),32);
            tracep->chgBit(oldp+19,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs));
            tracep->chgBit(oldp+20,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__ar_hs));
        }
        tracep->chgBit(oldp+21,(vlTOPp->ap_clk));
        tracep->chgBit(oldp+22,(vlTOPp->ap_interrupt));
        tracep->chgBit(oldp+23,(vlTOPp->s_axi_control_awvalid));
        tracep->chgBit(oldp+24,(vlTOPp->s_axi_control_awready));
        tracep->chgSData(oldp+25,(vlTOPp->s_axi_control_awaddr),12);
        tracep->chgBit(oldp+26,(vlTOPp->s_axi_control_wvalid));
        tracep->chgBit(oldp+27,(vlTOPp->s_axi_control_wready));
        tracep->chgIData(oldp+28,(vlTOPp->s_axi_control_wdata),32);
        tracep->chgCData(oldp+29,(vlTOPp->s_axi_control_wstrb),4);
        tracep->chgBit(oldp+30,(vlTOPp->s_axi_control_bvalid));
        tracep->chgBit(oldp+31,(vlTOPp->s_axi_control_bready));
        tracep->chgCData(oldp+32,(vlTOPp->s_axi_control_bresp),2);
        tracep->chgBit(oldp+33,(vlTOPp->s_axi_control_arvalid));
        tracep->chgBit(oldp+34,(vlTOPp->s_axi_control_arready));
        tracep->chgSData(oldp+35,(vlTOPp->s_axi_control_araddr),12);
        tracep->chgBit(oldp+36,(vlTOPp->s_axi_control_rvalid));
        tracep->chgBit(oldp+37,(vlTOPp->s_axi_control_rready));
        tracep->chgIData(oldp+38,(vlTOPp->s_axi_control_rdata),32);
        tracep->chgCData(oldp+39,(vlTOPp->s_axi_control_rresp),2);
        tracep->chgBit(oldp+40,(vlTOPp->m00_axi_awvalid));
        tracep->chgBit(oldp+41,(vlTOPp->m00_axi_awready));
        tracep->chgQData(oldp+42,(vlTOPp->m00_axi_awaddr),64);
        tracep->chgCData(oldp+44,(vlTOPp->m00_axi_awlen),8);
        tracep->chgBit(oldp+45,(vlTOPp->m00_axi_wvalid));
        tracep->chgBit(oldp+46,(vlTOPp->m00_axi_wready));
        tracep->chgIData(oldp+47,(vlTOPp->m00_axi_wdata),32);
        tracep->chgCData(oldp+48,(vlTOPp->m00_axi_wstrb),4);
        tracep->chgBit(oldp+49,(vlTOPp->m00_axi_wlast));
        tracep->chgBit(oldp+50,(vlTOPp->m00_axi_bvalid));
        tracep->chgBit(oldp+51,(vlTOPp->m00_axi_bready));
        tracep->chgBit(oldp+52,(vlTOPp->m00_axi_arvalid));
        tracep->chgBit(oldp+53,(vlTOPp->m00_axi_arready));
        tracep->chgQData(oldp+54,(vlTOPp->m00_axi_araddr),64);
        tracep->chgCData(oldp+56,(vlTOPp->m00_axi_arlen),8);
        tracep->chgBit(oldp+57,(vlTOPp->m00_axi_rvalid));
        tracep->chgBit(oldp+58,(vlTOPp->m00_axi_rready));
        tracep->chgIData(oldp+59,(vlTOPp->m00_axi_rdata),32);
        tracep->chgBit(oldp+60,(vlTOPp->m00_axi_rlast));
        tracep->chgBit(oldp+61,(((IData)(vlTOPp->s_axi_control_awvalid) 
                                 & (IData)(vlTOPp->s_axi_control_awready))));
        tracep->chgCData(oldp+62,(((0U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate))
                                    ? ((IData)(vlTOPp->s_axi_control_arvalid)
                                        ? 1U : 0U) : 
                                   ((1U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate))
                                     ? (((IData)(vlTOPp->s_axi_control_rready) 
                                         & (IData)(vlTOPp->s_axi_control_rvalid))
                                         ? 0U : 1U)
                                     : 0U))),2);
        tracep->chgCData(oldp+63,((0x3fU & (IData)(vlTOPp->s_axi_control_araddr))),6);
    }
}

void VToplevel::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
