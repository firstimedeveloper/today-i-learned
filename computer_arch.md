21-09-18
---
# Register Spill
Register spill is one of the main causes of performance loss when compiling programs. Because the number of registers is limited, it is imperitive for the compiler to reuse registers as much as possible and reduce register spills.

# li (load immediate value) 
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

# Multiplication
`mul $d, $r, $s` can be used to multiply the values in register r and s and save the result into register d.

`mult $r, $s` can be used to multiply values in the r and s register. However, since multiplication of two 32 bit values (since we are usign a 32 bit system) can exceed 32 bits, special registers called `HI` and `LO` are used.

Then, the instructions, `mfhi $d` and `mflo $d` can be used to move the results into register d.

If the result of the multiplication is greater than 32 bits, the overflowed bits will be stored in `HI`.

# Division
`div $r, $s` can be used to divide the value in register r by the value in register s. The result will go into register `LO` and the remainder into `HI`.

The instructions `mflo` and `mfhi` can subsequently be used to make use of the resulting values.
