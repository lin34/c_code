// set a bit
x |= 0x00000001 << 3
     // clear a bit
     x &= ~(0x1 << 3)

          // A binary pattern that modifies another binary pattern
          // by using bitwise operations
          x = 0b0000100001010001;
x &= ~0b0000000100000000;
res = 0b0000100001010001;
// result
// toggle use the xor operator
// whatever the bit was before becomes the opposite
// The following is equivalent

x ^= 0b00001000;
if (x & (0x1 << 3))
    x &= ~(0x1 << 3);
else
    x |= (0x1 << 3);