#include "VToplevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <stdio.h>

// Keep track of time: https://www.veripool.org/wiki/verilator/Manual-verilator#CONNECTING-TO-C
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char **argv, char **env) {
  int i = 0;
  int clk;
  Verilated::commandArgs(argc, argv);

  // init top verilog instance
  VToplevel *top = new VToplevel;

  // get cycles to simulate
  int n_cycles = 500;

  VerilatedVcdC *tfp;
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open(argv[1]);

  // initialize simulation inputs and eval once to avoid zero-time reset bug
  // (https://github.com/verilator/verilator/issues/2661)

  top->ap_clk = 0;
  top->s_axi_control_awvalid = 0;
  top->s_axi_control_awaddr = 0;
  top->s_axi_control_wvalid = 0;
  top->s_axi_control_wdata = 0;
  top->s_axi_control_wstrb = 0;
  top->s_axi_control_bready = 0;
  top->s_axi_control_arvalid = 0;
  top->s_axi_control_araddr = 0;
  top->s_axi_control_rready = 0;

  top->eval();

  // 0 => write scalar00
  // 1 => write ap_start
  // 2 => wait for cycle div by 20
  // 3 => check if kernel is done
  int transaction_id = 0;

  bool done;
  printf("Starting simulation\n");
  while (!done && i < n_cycles) {
    printf("cycle %d, transaction %d\n", i, transaction_id);

    top->s_axi_control_bready = 1;

    top->s_axi_control_awvalid = 0;
    top->s_axi_control_wvalid = 0;
    top->s_axi_control_wstrb = 0xf;

    if (transaction_id == 0) {
      if (top->s_axi_control_bvalid) {
        transaction_id++;
      } else {
        // address 0x10 (scalar00)
        top->s_axi_control_awvalid = 1;
        top->s_axi_control_awaddr = 0x10;
        // data
        top->s_axi_control_wvalid = 1;
        top->s_axi_control_wdata = 30;
      }
    } else if (transaction_id == 1) {
      // this transaction has been acked, move on to next one
      if (top->s_axi_control_bvalid) {
        transaction_id++;
      } else {
        // address 0x00
        top->s_axi_control_awvalid = 1;
        top->s_axi_control_awaddr = 0x00;

        top->s_axi_control_wvalid = 1;
        top->s_axi_control_wdata = 1; // trying to set bit 0 = 1 which means go
        // if (top->s_axi_control_awready)
      }
    }

    top->s_axi_control_arvalid = 0;
    top->s_axi_control_rready = 1; // always ready to receive reads

    if (transaction_id == 2 && i % 20 == 0) {
      transaction_id = 3;
    }

    // check if child is done
    if (transaction_id == 3) {
      if (top->s_axi_control_rvalid) {
        done = (top->s_axi_control_rdata == 0b10);
        printf("read %d\n", top->s_axi_control_rdata);
        transaction_id = 2;
      } else {
        top->s_axi_control_arvalid = 1;
        top->s_axi_control_araddr = 0x00;
      }
    }

    // dump variables into VCD file and toggle clock
    for (clk = 0; clk < 2; clk++) {
      tfp->dump(2 * i + clk);
      top->ap_clk = !top->ap_clk;
      top->eval();
    }
    // done = top->done;
    // // Do nothing for a few cycles to avoid zero-time reset bug
    // if (ignore_cycles == 0) {
    //   top->go = 1;
    // } else {
    //   ignore_cycles--;
    // }
    // // dump variables into VCD file and toggle clock
    // for (clk = 0; clk < 2; clk++) {
    //   if (trace && ignore_cycles == 0) {
    //     tfp->dump(2 * i + clk);
    //   }
    //   top->clk = !top->clk;
    //   top->eval();
    // }

    // // Time passes
    // main_time++;

    if (Verilated::gotFinish())
      exit(0);

    i++;
  }

  printf("Simulated %i cycles\n", i);
  top->final();
  tfp->close();
  // if (trace) {
  // }

  exit(0);
}
