.PHONY: send

s_axi_verilator: src/IP/*.v testbench.cpp
	verilator --cc --trace src/IP/top_level.v --build --top-module Toplevel --exe testbench.cpp --Mdir s_axi_verilator -Isrc/IP/

test.vcd: s_axi_verilator
	./s_axi_verilator/VToplevel test.vcd

send:
	rsync -r --progress src sgt43@havarti.cs.cornell.edu:/scratch/sgt43/s_axi/
