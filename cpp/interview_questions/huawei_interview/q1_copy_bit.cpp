/*
Question 1:
Implement a copy bit function that copies a bit from a 'src' int to a 'dst' int at the specified position 'pos'
For example, src = 7 dst = 12, res = 4
            0111(7) --> 1100 res --> 0100
You can implement the copy_bit function using bitwise operators in C++. Here's how you can do it:
*/

#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <string>

// Function to copy the bit from position 'pos' in int 'src' to position 'pos' in int 'dst'
int copy_bit1(int src, int dst, int pos)
{
    // Mask to isolate the bit at position 'pos' in 'src'
    int mask = 1 << pos;

    // Extract the bit at position 'pos' from 'src'
    int bit = (src & mask) >> pos;

    // Clear the bit at position 'pos' in 'dst'
    dst &= ~(1 << pos);

    // Set the bit at position 'pos' in 'dst' with the extracted bit value
    dst |= (bit << pos);
    return dst;
}

int copy_bit(int src, int dst, int pos){
    //check if set in src
    if((src & (1 << pos)) != 0){
        //set bit in dst
        dst |= (1 << pos);
    }else{
        dst &= ~(1 << pos);
    }
    return dst;
}

int main()
{
    int src = 0b101010; // Source integer
    int dst = 0b110011; // Destination integer
    int pos = 3;        // Position of the bit to be copied

    std::cout << "Before copying bit:" << std::endl;
    std::cout << "Source integer (src): " << std::bitset<6>(src) << std::endl;
    std::cout << "Destination integer (dst): " << std::bitset<6>(dst) << std::endl;

    // Copy bit from position 'pos' in 'src' to position 'pos' in 'dst'
    int res = copy_bit1(src, dst, pos);

    std::cout << "\nAfter copying bit:" << std::endl;
    std::cout << "Destination integer (dst): " << std::bitset<6>(res) << std::endl;

    return 0;
}
