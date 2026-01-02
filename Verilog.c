alu_v code
module ALU (
    input  [3:0] A,        // 4-bit input A
    input  [3:0] B,        // 4-bit input B
    input  [2:0] ALU_Sel,  // Operation selector
    output reg [3:0] ALU_Out,
    output reg CarryOut
);

always @(*) begin
    CarryOut = 0;
    case (ALU_Sel)
        3'b000: begin  // ADD
            {CarryOut, ALU_Out} = A + B;
        end
        3'b001: begin  // SUB
            {CarryOut, ALU_Out} = A - B;
        end
        3'b010: begin  // AND
            ALU_Out = A & B;
        end
        3'b011: begin  // OR
            ALU_Out = A | B;
        end
        3'b100: begin  // NOT (A)
            ALU_Out = ~A;
        end
        default: begin
            ALU_Out = 4'b0000;
        end
    endcase
end

endmodule

alu_tb code

module ALU_tb;

reg [3:0] A;
reg [3:0] B;
reg [2:0] ALU_Sel;
wire [3:0] ALU_Out;
wire CarryOut;

ALU uut (
    .A(A),
    .B(B),
    .ALU_Sel(ALU_Sel),
    .ALU_Out(ALU_Out),
    .CarryOut(CarryOut)
);

initial begin
    $display("A B SEL | OUT CARRY");
    $display("--------------------");

    A = 4'b0101; B = 4'b0011; ALU_Sel = 3'b000; #10; // ADD
    A = 4'b0101; B = 4'b0011; ALU_Sel = 3'b001; #10; // SUB
    A = 4'b0101; B = 4'b0011; ALU_Sel = 3'b010; #10; // AND
    A = 4'b0101; B = 4'b0011; ALU_Sel = 3'b011; #10; // OR
    A = 4'b0101; B = 4'b0000; ALU_Sel = 3'b100; #10; // NOT

    $finish;
end

endmodule
