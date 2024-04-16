#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////
// 1) Macro (10 points)
//    Create a macro (named C_TO_F) to convert from degrees Celsius to Fahrenheit
//    Macro should work for integer or floating point types
//    Note: degF = degC * (9/5) + 32
// Answer: TODO
#define C_TO_F(degC) (degC * (9 / 5) + 32)

////////////////////////////////////////////////////////////////////////////////
// 2) Function Debug (5 points)
// The following function should compute and return the square of the value
// pointed to by x.  Correct any mistakes in the implementation.

uint16_t computeSquareADC(volatile uint8_t *x)
{
  uint16_t retval = (*x) * (*x);
  return retval;
}

////////////////////////////////////////////////////////////////////////////////
// 3) Bit Manipulation (10 points)
//    Write a function that swaps the highest bits in each nibble of the byte
//    pointed to by the pointer b. (e.g., bits: 1 _ _ _ 0 _ _ _ -> 0 _ _ _ 1 _ _ _)
//    The bits designated by '_' in the example above should not be swapped.

void swapBits(uint8_t *b)
{
  // Answer: TODO
  // one byte is 2 nibbles 1000 0001 --> 0000 1001 or 129 to 9
  // set operation A000 B000 anytinh XOR with 0 is the same bit
  uint8_t bitA = (*b >> 7) & 1;
  uint8_t bitB = (*b >> 3) & 1;
  // if bits are not the same, flip the bits at positions 7 and 3
  // xor allows us to toggle a bit
  if (bitA != bitB)
  {
    *b ^= 1 << 3;
    *b ^= 1 << 7;
  }
  return;
}

////////////////////////////////////////////////////////////////////////////////
// 4) State Machine (20 points)
//
//    Complete the function below to implement the state machine shown in the
//    diagram below for an electronic gumball vending machine.
//     * The initial state of the state machine should be IDLE
//     * The state machine should maintain and manage its state
//     * The function should return the current state of the state machine
//     * Unexpected or invalid input should not cause a state transition
//     * GENERIC_FAULT may be received in any state and should put the machine
//       into the FAULT state
//
//
//          COIN      +---------+
//   +--------------->|         |   BUTTON
//   |                |  READY  | ---------+
//   |    COIN_RETURN |         |          |
//   |   +----------- +---------+          |
//   |   |                                 |
//   |   V                                 V
// +---------+                        +---------+
// |         |     VEND_COMPLETE      |         |
// |  IDLE   |<-----------------------| VENDING |
// |         |                        |         |
// +---------+                        +---------+
//
//                                 +---------+
//                                 |         |
//                GENERIC_FAULT    |  FAULT  |
//             +------------------>|         |
//                                 +---------+
//

////////////////////////////////////////////////////////////////////////////////
// 5) Interpolation (20 points)
// Given two arrays of n > 1 values arrX[] (sorted ascending) and arrY[]
// (sorted ascending), write an interpolation function that satisfies the
// following:
//
// * Interpolation(arrX[i]) returns arrY[i], for 0 <= i < n
// * Interpolation(val) returns the linearly interpolated value
//   of val if arrX[0] <= val <= arrX[n-1]. That is: val shall be found between
//   arrX[i-1] and arrX[i] and the return value shall be the interpolation of
//   arrY[i-1] and arrY[i].
// * Interpolation(val) returns -1 for any other case.
//
//           |                   /
//   arrY[i] |------------------+
//           |                / |
//           |              /   |
//    return |------------O     |
//           |          / |     |
//           |        /   |     |
//           |      /     |     |
// arrY[i-1] |----+       |     |
//           |  / |       |     |
//           |/___|_______|_____|______
//            arrX[i-1]  val   arrX[i]

// #define ARR_SIZE () //Fill this out
// float arrX[ARR_SIZE] = {};
// float arrY[ARR_SIZE] = {};
float interpolate(float val)
{
  // Answer: TODO
  return 0.0f;
}

int main()
{
  // Usage Examples

  // Q1
  // printf("Q1 Usage Example: %s\n", (C_TO_F(0) == 32) ? "PASS" : "FAIL");
  printf("Q1 Usage Example: %s\n", (C_TO_F(0) == 32) ? "PASS" : "FAIL");
  printf("Q1 Usage Example: %f\n", (C_TO_F(5.5)));
  int x = 20;
  printf("Q2 Usage Example: %d\n", computeSquareADC(&x));
  int y = 129;
  swapBits(&y);
  printf("Q2 Usage Example: %d\n", y);
  // Q4
  // printf("Q4 Usage Example: %s\n", (updateStateMachine(COIN) == READY) ? "PASS" : "FAIL");

  state = IDLE;
  printf("Q4 Usage Example: %s\n", (updateStateMachine(COIN) == READY) ? "PASS" : "FAIL");
  printf("Q4 Usage Example: %s\n", (updateStateMachine(BUTTON) == VENDING) ? "PASS" : "FAIL");
  return 0;
}