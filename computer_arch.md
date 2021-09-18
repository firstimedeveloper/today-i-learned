21-09-18
---
## Instructions
Instructions are stored in memory in a binary format. In MIPS architecture, each instruction is 4 bytes (32 bits) long. In CISC computers, each instructions can vary from 1 byte to 15 bytes. These variable sizes can lead to more efficent use of space, and faster code. However a lot of work has to be done to figure out the size of the instruction, and the location of the next instruction. In comparison, in MIPS or other RISC computers, the size of each instruction is predetermined which means that there will be 'wasted' bits in some instructons. However, the overall computer architecher is much simpler which by itself is a great advantage.
### MIPS I-format Instructions

In binary format:\
op|rs|rt|constant or address\
 6| 5| 5| 				  16

The instruction `addi $t0, $t1, 0x123` is represented as follows:

binary: 0010 0001 0010 1000 0000 0001 0010 0011\
hex: 0x21280123

001000|01001|01000|0000000100100011\
'-----------------------------------'\
opcode| reg9| reg8| immediate value\
'-----------------------------------'\
    6b|   5b|   5b|             16b

You can notice that the immediate value can only be 16 bits long.

### MIPS R-format (3-register, R-type) Instructions
In binary format:\
op|rs|rt|rd|shamt|funct\
 6| 5| 5| 5|    5|    6

op: operation code (opcode)\
rs: first source register number\
rt: second source register number\
rd: destination register number\
shamt: shift amount (00000 for now)\
shamt is wasted in arithmetic instructions.
funct: function code (extends opcode)\
You can notice that the opcode can have 2^6=64 different types of instructions in the CPU. However, since this number may not be enough. So the `funct` in the LSB can be used to 'extend' the opcode. For example, add and sub has the same opcode, but they are distinguished from the funct.


### Register Spill
Register spill is one of the main causes of performance loss when compiling programs. Because the number of registers is limited, it is imperitive for the compiler to reuse registers as much as possible and reduce register spills.

### Addition
`addi $t0, $t1, $t2` can be used to add the values in registers t1 and t2 and save the resulting value into register t0.
`addi $t0, $t1, 0x123` is a shorthand for 'add immediate'.the value in register t1 and the value `0x123` will be added and the resulting value will be put into register t0. 

### li (load immediate value) 
li sets the value of the register. This is a pseudo-instruction, and is included for the convenience of the programmer.
```
li $t1, 100
li $t2, 0x10
add $t3, $t1, $t2

# The following code is the same as the code above.
addi $t1, $zero, 100
addi $t2, $zero, 0x10
add $t3, $t1, $t2
```

### Multiplication
`mul $d, $r, $s` can be used to multiply the values in register r and s and save the result into register d.

`mult $r, $s` can be used to multiply values in the r and s register. However, since multiplication of two 32 bit values (since we are usign a 32 bit system) can exceed 32 bits, special registers called `HI` and `LO` are used.

Then, the instructions, `mfhi $d` and `mflo $d` can be used to move the results into register d.

If the result of the multiplication is greater than 32 bits, the overflowed bits will be stored in `HI`.

### Division
`div $r, $s` can be used to divide the value in register r by the value in register s. The result will go into register `LO` and the remainder into `HI`.

The instructions `mflo` and `mfhi` can subsequently be used to make use of the resulting values.
