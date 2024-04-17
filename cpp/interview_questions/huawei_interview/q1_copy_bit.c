/*
You can implement the copy_bit function using bitwise operators in C++. Here's how you can do it:
*/

#include <iostream>

// Function to copy the bit from position 'pos' in int 'src' to position 'pos' in int 'dst'
void copy_bit(int &dst, int src, int pos)
{
    // Mask to isolate the bit at position 'pos' in 'src'
    int mask = 1 << pos;

    // Extract the bit at position 'pos' from 'src'
    int bit = (src & mask) >> pos;

    // Clear the bit at position 'pos' in 'dst'
    dst &= ~(1 << pos);

    // Set the bit at position 'pos' in 'dst' with the extracted bit value
    dst |= (bit << pos);
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
    copy_bit(dst, src, pos);

    std::cout << "\nAfter copying bit:" << std::endl;
    std::cout << "Destination integer (dst): " << std::bitset<6>(dst) << std::endl;

    return 0;
}
