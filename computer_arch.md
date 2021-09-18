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
