module gray2bcd(
	input [3:0] gray,
	output reg [3:0] bcd);

	//Sempre que alterar a entrada
	always@(gray)
		begin
			//Converta a entrada gray na saida bcd
			bcd[3] = gray[3];
			bcd[2] = (~gray[3] & gray[2]) | (gray[3] & ~gray[2]);
			bcd[1] = (~gray[3] & gray[2] & ~gray[1]) | (~gray[3] & ~gray[2] & gray[1]) | (gray[3] & ~gray[2] & ~gray[1]) | (gray[3] & gray[2] & gray[1]);
			bcd[0] = (~gray[3] & gray[2] & ~gray[1] & ~gray[0]) | (~gray[3] & ~gray[2] & gray[1] & ~gray[0]) | (~gray[3] & ~gray[2] & ~gray[1] & gray[0]) | (~gray[3] & gray[2] & gray[1] & gray[0]) | (gray[3] & ~gray[2] & ~gray[1] & ~gray[0]) | (gray[3] & gray[2] & gray[1] & ~gray[0]) | (gray[3] & gray[2] & ~gray[1] & gray[0]) | (gray[3] & ~gray[2] & gray[1] & gray[0]);

			$display("%b <-> %b", gray, bcd);
		end
endmodule