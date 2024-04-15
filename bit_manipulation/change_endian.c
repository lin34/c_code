#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

uint32_t swapEndian(uint32_t n){
    uint32_t b0, b1, b2, b3, res;
    b0 = (n & 0x000000ff) << 24u;
    b1 = (n & 0x0000ff00) << 8u;
    b2 = (n & 0x00ff0000) >> 8u;
    b3 = (n & 0xff000000) >> 24u;
    res = b0 | b1 | b2 | b3;
    printf("original: %x \n", n);
    printf("swapped  : %x \n", res);
    return res;
}

int main(){
    uint32_t input = 0x12345678;
    uint32_t expected = 0x78563412;
    int res = swapEndian(input);
    assert(res == expected);
}