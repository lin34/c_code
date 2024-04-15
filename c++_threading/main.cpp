#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0, mask = 1;
    for (int i = 0; i < 32; i++)
    {
        ans <<= 1;
        if (n & mask)
        {
            ans |= 1;
        }
        mask <<= 1;
    }
    return ans;
}

int main()
{
    uint32_t input = 0b00000010100101000001111010011100;
    uint32_t expected = 0b00111001011110000010100101000000;
    uint32_t res = reverseBits(input);
    assert(res == expected);

    printf("all reverse_bits tests pass\n");
}