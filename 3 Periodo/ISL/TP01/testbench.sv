module gc2bcd_testbench;
	//Entrada (4 bits)
	reg [3:0] gray_in;

	//Saida (4 bits)
	wire [3:0] bcd_out;

	//Unit Under Test (UUT): instância do módulo gray2bcd
	gray2bcd uut(gray_in, bcd_out);

	initial
		begin
			$dumpfile("dump.vcd"); $dumpvars; //Requisito do EPWave
			$display("gray <-> bcd"); //Printa cabeçalho

			//Bits de cada entrada (código de Gray)
			gray_in = 4'b0000; #1;
			gray_in = 4'b0001; #1;
			gray_in = 4'b0011; #1;
			gray_in = 4'b0010; #1;
			gray_in = 4'b0110; #1;
			gray_in = 4'b0111; #1;
			gray_in = 4'b0101; #1;
			gray_in = 4'b0100; #1;
			gray_in = 4'b1100; #1;
			gray_in = 4'b1101; #1;
			gray_in = 4'b1111; #1;
			gray_in = 4'b1110; #1;
			gray_in = 4'b1010; #1;
			gray_in = 4'b1011; #1;
			gray_in = 4'b1001; #1;
			gray_in = 4'b1000; #1;
		end

endmodule