## 48 bits for addresses instead of 64
At 42 school, recreating the printf function is one of the first individual projects that we are required to complete. For anyone unfamiliar, `printf` is a function that prints a string with formatting options (hence the `f` at the end of the function). One of the format options include `%p` which prints out the value of a pointer in hex. 

A pointer is a variable that 'points' to an address in memory. Using the system printf function, the address looks something like `0x7fffe9ebf984` depending on your system. The `0x` indicates that this is a hexadecimal value. 

Using hex values is especially convenient when dealing with these addresses because each hexadecimal digit corresponds to a group of 4 bits. 

Many current day computers are 32 or 64 bit computers. These numbers refer to the virtual address length of these computers. (As a side, these are usually, but not necessarily the same as the word length).

In 32 bit machines, the virtual address size is 32 bits. Meaning, in terms of hex, the address can be represented with 8 digits(4x8=32). This translates to about 4 gigabytes of physcial memory.

Change the 32 bit to 64, the number of hex digits becomes 16 (4x16=64), and translates to 16 exbibytes of memory, which is hard to even fathom.

Current day chipmakers only make use of the least significant 12 digits out of the 16 digits that can potentially be used. 12x4=48 which is why the lenght of the addresses is only 12 bytes long even for 64 bit machines.

One way to print pointer values in c is to use the datatype `uintptr_t` that can be used to store pointer data. This datatype is the same size as a pointer, so 

helpful link = https://stackoverflow.com/questions/30401128/why-there-are-two-different-lengths-for-addresses-in-32-and-64-bit
