#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

uint32_t swapEndian(uint32_t n){
    uint32_t b0, b1, res;
    b0 = (n & 0x0000ffff) << 16u;
    b1 = (n & 0xffff0000) >> 16u;
    res = b0 | b1;
    printf("original: %x \n", n);
    printf("swapped  : %x \n", res);
    return res;
}

int main(){
    uint32_t input = 0x12345678;
    uint32_t expected = 0x56781234;
    int res = swapEndian(input);
    assert(res == expected);
}