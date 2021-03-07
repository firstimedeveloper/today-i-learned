# Data representation - int
Mar 7

## Encoding integers

### Unsigned and Two's complement
ie. Changing a 4 bit binary --> integer
Unsigned - `1111` becomes `8+4+2+1`, so -5.
Two's Complement - `1111` becomes `-8+4+2+1`, so -1.

For Two's Complement, the most significant bit (leftmost bit) becomes the sign bit.

[twos-complement-example](images/twos-complement-example.png)

[int-range-example](int-range-example.png)
for W = 16

Notice that the range is asymmetric. The absolute value for the min value is max + 1. This is important in situations where you cast an unsigned to int, or vice versa.

One thing to note is that the bit representation for `int` and `unsigned int` are the same. The data is reinterpreted.

## Expanding and Truncating int
- Expanding (ie. short int to int)
	- Unsigned: Zeros added to the left n times, where n is the number of additional bits to add.
	- Signed: Copy the most significant bit n times, where n is the number of additional bits to add. So if the value is negative, 1 would be copied n times, and 0 if positive.
	- For both cases, the value of the integer isn't affected.

- Truncating (ie. unsigned to unsigned short)
	- Unsigned: mod operation
	- Signed: similar to mod	
	- The value may change if the original value exeeds the max/min value for the new data type.

