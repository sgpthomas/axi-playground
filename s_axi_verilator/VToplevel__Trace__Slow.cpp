// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VToplevel__Syms.h"


//======================

void VToplevel::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VToplevel::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VToplevel::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VToplevel::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VToplevel::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+22,"ap_clk", false,-1);
        tracep->declBit(c+23,"ap_interrupt", false,-1);
        tracep->declBit(c+24,"s_axi_control_awvalid", false,-1);
        tracep->declBit(c+25,"s_axi_control_awready", false,-1);
        tracep->declBus(c+26,"s_axi_control_awaddr", false,-1, 11,0);
        tracep->declBit(c+27,"s_axi_control_wvalid", false,-1);
        tracep->declBit(c+28,"s_axi_control_wready", false,-1);
        tracep->declBus(c+29,"s_axi_control_wdata", false,-1, 31,0);
        tracep->declBus(c+30,"s_axi_control_wstrb", false,-1, 3,0);
        tracep->declBit(c+31,"s_axi_control_bvalid", false,-1);
        tracep->declBit(c+32,"s_axi_control_bready", false,-1);
        tracep->declBus(c+33,"s_axi_control_bresp", false,-1, 1,0);
        tracep->declBit(c+34,"s_axi_control_arvalid", false,-1);
        tracep->declBit(c+35,"s_axi_control_arready", false,-1);
        tracep->declBus(c+36,"s_axi_control_araddr", false,-1, 11,0);
        tracep->declBit(c+37,"s_axi_control_rvalid", false,-1);
        tracep->declBit(c+38,"s_axi_control_rready", false,-1);
        tracep->declBus(c+39,"s_axi_control_rdata", false,-1, 31,0);
        tracep->declBus(c+40,"s_axi_control_rresp", false,-1, 1,0);
        tracep->declBit(c+41,"m00_axi_awvalid", false,-1);
        tracep->declBit(c+42,"m00_axi_awready", false,-1);
        tracep->declQuad(c+43,"m00_axi_awaddr", false,-1, 63,0);
        tracep->declBus(c+45,"m00_axi_awlen", false,-1, 7,0);
        tracep->declBit(c+46,"m00_axi_wvalid", false,-1);
        tracep->declBit(c+47,"m00_axi_wready", false,-1);
        tracep->declBus(c+48,"m00_axi_wdata", false,-1, 31,0);
        tracep->declBus(c+49,"m00_axi_wstrb", false,-1, 3,0);
        tracep->declBit(c+50,"m00_axi_wlast", false,-1);
        tracep->declBit(c+51,"m00_axi_bvalid", false,-1);
        tracep->declBit(c+52,"m00_axi_bready", false,-1);
        tracep->declBit(c+53,"m00_axi_arvalid", false,-1);
        tracep->declBit(c+54,"m00_axi_arready", false,-1);
        tracep->declQuad(c+55,"m00_axi_araddr", false,-1, 63,0);
        tracep->declBus(c+57,"m00_axi_arlen", false,-1, 7,0);
        tracep->declBit(c+58,"m00_axi_rvalid", false,-1);
        tracep->declBit(c+59,"m00_axi_rready", false,-1);
        tracep->declBus(c+60,"m00_axi_rdata", false,-1, 31,0);
        tracep->declBit(c+61,"m00_axi_rlast", false,-1);
        tracep->declBus(c+65,"Toplevel C_S_AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"Toplevel C_S_AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+67,"Toplevel M00_AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"Toplevel M00_AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+22,"Toplevel ap_clk", false,-1);
        tracep->declBit(c+23,"Toplevel ap_interrupt", false,-1);
        tracep->declBit(c+24,"Toplevel s_axi_control_awvalid", false,-1);
        tracep->declBit(c+25,"Toplevel s_axi_control_awready", false,-1);
        tracep->declBus(c+26,"Toplevel s_axi_control_awaddr", false,-1, 11,0);
        tracep->declBit(c+27,"Toplevel s_axi_control_wvalid", false,-1);
        tracep->declBit(c+28,"Toplevel s_axi_control_wready", false,-1);
        tracep->declBus(c+29,"Toplevel s_axi_control_wdata", false,-1, 31,0);
        tracep->declBus(c+30,"Toplevel s_axi_control_wstrb", false,-1, 3,0);
        tracep->declBit(c+31,"Toplevel s_axi_control_bvalid", false,-1);
        tracep->declBit(c+32,"Toplevel s_axi_control_bready", false,-1);
        tracep->declBus(c+33,"Toplevel s_axi_control_bresp", false,-1, 1,0);
        tracep->declBit(c+34,"Toplevel s_axi_control_arvalid", false,-1);
        tracep->declBit(c+35,"Toplevel s_axi_control_arready", false,-1);
        tracep->declBus(c+36,"Toplevel s_axi_control_araddr", false,-1, 11,0);
        tracep->declBit(c+37,"Toplevel s_axi_control_rvalid", false,-1);
        tracep->declBit(c+38,"Toplevel s_axi_control_rready", false,-1);
        tracep->declBus(c+39,"Toplevel s_axi_control_rdata", false,-1, 31,0);
        tracep->declBus(c+40,"Toplevel s_axi_control_rresp", false,-1, 1,0);
        tracep->declBit(c+41,"Toplevel m00_axi_awvalid", false,-1);
        tracep->declBit(c+42,"Toplevel m00_axi_awready", false,-1);
        tracep->declQuad(c+43,"Toplevel m00_axi_awaddr", false,-1, 63,0);
        tracep->declBus(c+45,"Toplevel m00_axi_awlen", false,-1, 7,0);
        tracep->declBit(c+46,"Toplevel m00_axi_wvalid", false,-1);
        tracep->declBit(c+47,"Toplevel m00_axi_wready", false,-1);
        tracep->declBus(c+48,"Toplevel m00_axi_wdata", false,-1, 31,0);
        tracep->declBus(c+49,"Toplevel m00_axi_wstrb", false,-1, 3,0);
        tracep->declBit(c+50,"Toplevel m00_axi_wlast", false,-1);
        tracep->declBit(c+51,"Toplevel m00_axi_bvalid", false,-1);
        tracep->declBit(c+52,"Toplevel m00_axi_bready", false,-1);
        tracep->declBit(c+53,"Toplevel m00_axi_arvalid", false,-1);
        tracep->declBit(c+54,"Toplevel m00_axi_arready", false,-1);
        tracep->declQuad(c+55,"Toplevel m00_axi_araddr", false,-1, 63,0);
        tracep->declBus(c+57,"Toplevel m00_axi_arlen", false,-1, 7,0);
        tracep->declBit(c+58,"Toplevel m00_axi_rvalid", false,-1);
        tracep->declBit(c+59,"Toplevel m00_axi_rready", false,-1);
        tracep->declBus(c+60,"Toplevel m00_axi_rdata", false,-1, 31,0);
        tracep->declBit(c+61,"Toplevel m00_axi_rlast", false,-1);
        tracep->declBus(c+68,"Toplevel ARESET", false,-1, 0,0);
        tracep->declBus(c+69,"Toplevel ACLK_EN", false,-1, 0,0);
        tracep->declBit(c+1,"Toplevel ap_start", false,-1);
        tracep->declBit(c+2,"Toplevel ap_done", false,-1);
        tracep->declBus(c+3,"Toplevel scalar00", false,-1, 31,0);
        tracep->declQuad(c+4,"Toplevel A", false,-1, 63,0);
        tracep->declBus(c+6,"Toplevel counter", false,-1, 31,0);
        tracep->declBus(c+70,"Toplevel A_WR_RESET", false,-1, 3,0);
        tracep->declBus(c+71,"Toplevel A_WR_IDLE", false,-1, 3,0);
        tracep->declBus(c+72,"Toplevel A_WR_DATA", false,-1, 3,0);
        tracep->declBus(c+73,"Toplevel A_WR_RESP", false,-1, 3,0);
        tracep->declBus(c+7,"Toplevel A_wr_state", false,-1, 3,0);
        tracep->declBus(c+17,"Toplevel A_wr_next", false,-1, 3,0);
        tracep->declBus(c+74,"Toplevel A_wr_data", false,-1, 31,0);
        tracep->declBus(c+8,"Toplevel A_wr_addr", false,-1, 7,0);
        tracep->declBus(c+65,"Toplevel inst_control_axi ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"Toplevel inst_control_axi DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+22,"Toplevel inst_control_axi ACLK", false,-1);
        tracep->declBit(c+68,"Toplevel inst_control_axi ARESET", false,-1);
        tracep->declBit(c+69,"Toplevel inst_control_axi ACLK_EN", false,-1);
        tracep->declBit(c+24,"Toplevel inst_control_axi AWVALID", false,-1);
        tracep->declBit(c+25,"Toplevel inst_control_axi AWREADY", false,-1);
        tracep->declBus(c+26,"Toplevel inst_control_axi AWADDR", false,-1, 11,0);
        tracep->declBit(c+27,"Toplevel inst_control_axi WVALID", false,-1);
        tracep->declBit(c+28,"Toplevel inst_control_axi WREADY", false,-1);
        tracep->declBus(c+29,"Toplevel inst_control_axi WDATA", false,-1, 31,0);
        tracep->declBus(c+30,"Toplevel inst_control_axi WSTRB", false,-1, 3,0);
        tracep->declBit(c+31,"Toplevel inst_control_axi BVALID", false,-1);
        tracep->declBit(c+32,"Toplevel inst_control_axi BREADY", false,-1);
        tracep->declBus(c+33,"Toplevel inst_control_axi BRESP", false,-1, 1,0);
        tracep->declBit(c+34,"Toplevel inst_control_axi ARVALID", false,-1);
        tracep->declBit(c+35,"Toplevel inst_control_axi ARREADY", false,-1);
        tracep->declBus(c+36,"Toplevel inst_control_axi ARADDR", false,-1, 11,0);
        tracep->declBit(c+37,"Toplevel inst_control_axi RVALID", false,-1);
        tracep->declBit(c+38,"Toplevel inst_control_axi RREADY", false,-1);
        tracep->declBus(c+39,"Toplevel inst_control_axi RDATA", false,-1, 31,0);
        tracep->declBus(c+40,"Toplevel inst_control_axi RRESP", false,-1, 1,0);
        tracep->declBit(c+23,"Toplevel inst_control_axi interrupt", false,-1);
        tracep->declBit(c+1,"Toplevel inst_control_axi ap_start", false,-1);
        tracep->declBit(c+2,"Toplevel inst_control_axi ap_done", false,-1);
        tracep->declBus(c+3,"Toplevel inst_control_axi scalar00", false,-1, 31,0);
        tracep->declQuad(c+4,"Toplevel inst_control_axi A", false,-1, 63,0);
        tracep->declBus(c+75,"Toplevel inst_control_axi ADDR_AP_CTRL", false,-1, 5,0);
        tracep->declBus(c+76,"Toplevel inst_control_axi ADDR_GIE", false,-1, 5,0);
        tracep->declBus(c+77,"Toplevel inst_control_axi ADDR_IER", false,-1, 5,0);
        tracep->declBus(c+78,"Toplevel inst_control_axi ADDR_ISR", false,-1, 5,0);
        tracep->declBus(c+79,"Toplevel inst_control_axi ADDR_SCALAR00_DATA_0", false,-1, 5,0);
        tracep->declBus(c+80,"Toplevel inst_control_axi ADDR_SCALAR00_CTRL", false,-1, 5,0);
        tracep->declBus(c+81,"Toplevel inst_control_axi ADDR_A_0", false,-1, 5,0);
        tracep->declBus(c+82,"Toplevel inst_control_axi ADDR_A_1", false,-1, 5,0);
        tracep->declBus(c+83,"Toplevel inst_control_axi WRIDLE", false,-1, 1,0);
        tracep->declBus(c+84,"Toplevel inst_control_axi WRDATA", false,-1, 1,0);
        tracep->declBus(c+85,"Toplevel inst_control_axi WRRESP", false,-1, 1,0);
        tracep->declBus(c+86,"Toplevel inst_control_axi WRRESET", false,-1, 1,0);
        tracep->declBus(c+83,"Toplevel inst_control_axi RDIDLE", false,-1, 1,0);
        tracep->declBus(c+84,"Toplevel inst_control_axi RDDATA", false,-1, 1,0);
        tracep->declBus(c+85,"Toplevel inst_control_axi RDRESET", false,-1, 1,0);
        tracep->declBus(c+87,"Toplevel inst_control_axi ADDR_BITS", false,-1, 31,0);
        tracep->declBus(c+9,"Toplevel inst_control_axi wstate", false,-1, 1,0);
        tracep->declBus(c+18,"Toplevel inst_control_axi wnext", false,-1, 1,0);
        tracep->declBus(c+10,"Toplevel inst_control_axi waddr", false,-1, 5,0);
        tracep->declBus(c+19,"Toplevel inst_control_axi wmask", false,-1, 31,0);
        tracep->declBit(c+62,"Toplevel inst_control_axi aw_hs", false,-1);
        tracep->declBit(c+20,"Toplevel inst_control_axi w_hs", false,-1);
        tracep->declBus(c+11,"Toplevel inst_control_axi rstate", false,-1, 1,0);
        tracep->declBus(c+63,"Toplevel inst_control_axi rnext", false,-1, 1,0);
        tracep->declBus(c+12,"Toplevel inst_control_axi rdata", false,-1, 31,0);
        tracep->declBit(c+21,"Toplevel inst_control_axi ar_hs", false,-1);
        tracep->declBus(c+64,"Toplevel inst_control_axi raddr", false,-1, 5,0);
        tracep->declBit(c+1,"Toplevel inst_control_axi int_ap_start", false,-1);
        tracep->declBit(c+13,"Toplevel inst_control_axi int_ap_done", false,-1);
        tracep->declBit(c+14,"Toplevel inst_control_axi int_gie", false,-1);
        tracep->declBus(c+15,"Toplevel inst_control_axi int_ier", false,-1, 1,0);
        tracep->declBus(c+16,"Toplevel inst_control_axi int_isr", false,-1, 1,0);
        tracep->declBus(c+3,"Toplevel inst_control_axi int_scalar00", false,-1, 31,0);
        tracep->declQuad(c+4,"Toplevel inst_control_axi int_A", false,-1, 63,0);
    }
}

void VToplevel::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VToplevel::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VToplevel::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VToplevel__Syms* __restrict vlSymsp = static_cast<VToplevel__Syms*>(userp);
    VToplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_start));
        tracep->fullBit(oldp+2,(vlTOPp->Toplevel__DOT__ap_done));
        tracep->fullIData(oldp+3,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_scalar00),32);
        tracep->fullQData(oldp+4,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_A),64);
        tracep->fullIData(oldp+6,(vlTOPp->Toplevel__DOT__counter),32);
        tracep->fullCData(oldp+7,(vlTOPp->Toplevel__DOT__A_wr_state),4);
        tracep->fullCData(oldp+8,(vlTOPp->Toplevel__DOT__A_wr_addr),8);
        tracep->fullCData(oldp+9,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wstate),2);
        tracep->fullCData(oldp+10,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__waddr),6);
        tracep->fullCData(oldp+11,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate),2);
        tracep->fullIData(oldp+12,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rdata),32);
        tracep->fullBit(oldp+13,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ap_done));
        tracep->fullBit(oldp+14,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_gie));
        tracep->fullCData(oldp+15,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_ier),2);
        tracep->fullCData(oldp+16,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__int_isr),2);
        tracep->fullCData(oldp+17,(vlTOPp->Toplevel__DOT__A_wr_next),4);
        tracep->fullCData(oldp+18,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wnext),2);
        tracep->fullIData(oldp+19,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__wmask),32);
        tracep->fullBit(oldp+20,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__w_hs));
        tracep->fullBit(oldp+21,(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__ar_hs));
        tracep->fullBit(oldp+22,(vlTOPp->ap_clk));
        tracep->fullBit(oldp+23,(vlTOPp->ap_interrupt));
        tracep->fullBit(oldp+24,(vlTOPp->s_axi_control_awvalid));
        tracep->fullBit(oldp+25,(vlTOPp->s_axi_control_awready));
        tracep->fullSData(oldp+26,(vlTOPp->s_axi_control_awaddr),12);
        tracep->fullBit(oldp+27,(vlTOPp->s_axi_control_wvalid));
        tracep->fullBit(oldp+28,(vlTOPp->s_axi_control_wready));
        tracep->fullIData(oldp+29,(vlTOPp->s_axi_control_wdata),32);
        tracep->fullCData(oldp+30,(vlTOPp->s_axi_control_wstrb),4);
        tracep->fullBit(oldp+31,(vlTOPp->s_axi_control_bvalid));
        tracep->fullBit(oldp+32,(vlTOPp->s_axi_control_bready));
        tracep->fullCData(oldp+33,(vlTOPp->s_axi_control_bresp),2);
        tracep->fullBit(oldp+34,(vlTOPp->s_axi_control_arvalid));
        tracep->fullBit(oldp+35,(vlTOPp->s_axi_control_arready));
        tracep->fullSData(oldp+36,(vlTOPp->s_axi_control_araddr),12);
        tracep->fullBit(oldp+37,(vlTOPp->s_axi_control_rvalid));
        tracep->fullBit(oldp+38,(vlTOPp->s_axi_control_rready));
        tracep->fullIData(oldp+39,(vlTOPp->s_axi_control_rdata),32);
        tracep->fullCData(oldp+40,(vlTOPp->s_axi_control_rresp),2);
        tracep->fullBit(oldp+41,(vlTOPp->m00_axi_awvalid));
        tracep->fullBit(oldp+42,(vlTOPp->m00_axi_awready));
        tracep->fullQData(oldp+43,(vlTOPp->m00_axi_awaddr),64);
        tracep->fullCData(oldp+45,(vlTOPp->m00_axi_awlen),8);
        tracep->fullBit(oldp+46,(vlTOPp->m00_axi_wvalid));
        tracep->fullBit(oldp+47,(vlTOPp->m00_axi_wready));
        tracep->fullIData(oldp+48,(vlTOPp->m00_axi_wdata),32);
        tracep->fullCData(oldp+49,(vlTOPp->m00_axi_wstrb),4);
        tracep->fullBit(oldp+50,(vlTOPp->m00_axi_wlast));
        tracep->fullBit(oldp+51,(vlTOPp->m00_axi_bvalid));
        tracep->fullBit(oldp+52,(vlTOPp->m00_axi_bready));
        tracep->fullBit(oldp+53,(vlTOPp->m00_axi_arvalid));
        tracep->fullBit(oldp+54,(vlTOPp->m00_axi_arready));
        tracep->fullQData(oldp+55,(vlTOPp->m00_axi_araddr),64);
        tracep->fullCData(oldp+57,(vlTOPp->m00_axi_arlen),8);
        tracep->fullBit(oldp+58,(vlTOPp->m00_axi_rvalid));
        tracep->fullBit(oldp+59,(vlTOPp->m00_axi_rready));
        tracep->fullIData(oldp+60,(vlTOPp->m00_axi_rdata),32);
        tracep->fullBit(oldp+61,(vlTOPp->m00_axi_rlast));
        tracep->fullBit(oldp+62,(((IData)(vlTOPp->s_axi_control_awvalid) 
                                  & (IData)(vlTOPp->s_axi_control_awready))));
        tracep->fullCData(oldp+63,(((0U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate))
                                     ? ((IData)(vlTOPp->s_axi_control_arvalid)
                                         ? 1U : 0U)
                                     : ((1U == (IData)(vlTOPp->Toplevel__DOT__inst_control_axi__DOT__rstate))
                                         ? (((IData)(vlTOPp->s_axi_control_rready) 
                                             & (IData)(vlTOPp->s_axi_control_rvalid))
                                             ? 0U : 1U)
                                         : 0U))),2);
        tracep->fullCData(oldp+64,((0x3fU & (IData)(vlTOPp->s_axi_control_araddr))),6);
        tracep->fullIData(oldp+65,(0xcU),32);
        tracep->fullIData(oldp+66,(0x20U),32);
        tracep->fullIData(oldp+67,(0x40U),32);
        tracep->fullBit(oldp+68,(0U));
        tracep->fullBit(oldp+69,(1U));
        tracep->fullCData(oldp+70,(0U),4);
        tracep->fullCData(oldp+71,(1U),4);
        tracep->fullCData(oldp+72,(2U),4);
        tracep->fullCData(oldp+73,(3U),4);
        tracep->fullIData(oldp+74,(0U),32);
        tracep->fullCData(oldp+75,(0U),6);
        tracep->fullCData(oldp+76,(4U),6);
        tracep->fullCData(oldp+77,(8U),6);
        tracep->fullCData(oldp+78,(0xcU),6);
        tracep->fullCData(oldp+79,(0x10U),6);
        tracep->fullCData(oldp+80,(0x14U),6);
        tracep->fullCData(oldp+81,(0x18U),6);
        tracep->fullCData(oldp+82,(0x1cU),6);
        tracep->fullCData(oldp+83,(0U),2);
        tracep->fullCData(oldp+84,(1U),2);
        tracep->fullCData(oldp+85,(2U),2);
        tracep->fullCData(oldp+86,(3U),2);
        tracep->fullIData(oldp+87,(6U),32);
    }
}
