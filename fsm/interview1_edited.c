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
  uint16_t val = (uint16_t)(*x);
  return val * val;
}

////////////////////////////////////////////////////////////////////////////////
// 3) Bit Manipulation (10 points)
//    Write a function that swaps the highest bits in each nibble of the byte
//    pointed to by the pointer b. (e.g., bits: 1 _ _ _ 0 _ _ _ -> 0 _ _ _ 1 _ _ _)
//    The bits designated by '_' in the example above should not be swapped.

void swapBits(uint8_t *b)
{
  // Extract bit 7 and bit 3
  uint8_t bit7 = (*b >> 7) & 0x01;
  uint8_t bit3 = (*b >> 3) & 0x01;

  // Clear original bit 7 and bit 3
  *b &= ~(1 << 7); // clear bit 7
  *b &= ~(1 << 3); // clear bit 3

  // Set new swapped values
  *b |= (bit3 << 7);
  *b |= (bit7 << 3);
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

typedef enum
{
  IDLE,
  READY,
  VENDING,
  FAULT
} state_E;

state_E state = IDLE;

typedef enum
{
  COIN,
  COIN_RETURN,
  BUTTON,
  VEND_COMPLETE,
  GENERIC_FAULT
} input_E;

void idleStateHandler(input_E input)
{
  if (input == COIN)
  {
    state = READY;
  }
  else if (input == GENERIC_FAULT)
  {
    state = FAULT;
  }
}

void readyStateHandler(input_E input)
{
  if (input == BUTTON)
  {
    state = VENDING;
  }
  else if (input == COIN_RETURN)
  {
    state = IDLE;
  }
  else if (input == GENERIC_FAULT)
  {
    state = FAULT;
  }
}

void vendingStateHandler(input_E input)
{
  if (input == VEND_COMPLETE)
  {
    state = IDLE;
  }
  else if (input == GENERIC_FAULT)
  {
    state = FAULT;
  }
}

state_E updateStateMachine(input_E input)
{
  if (state == IDLE)
  {
    idleStateHandler(input);
  }
  else if (state == READY)
  {
    readyStateHandler(input);
  }
  else if (state == VENDING)
  {
    vendingStateHandler(input);
  }

  return state;
}

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

#define ARR_SIZE (5) // Fill this out
float arrX[ARR_SIZE] = {0, 1, 2, 3, 4};
float arrY[ARR_SIZE] = {0, 2, 4, 8, 16};
float interpolate(float val)
{
  if ((val < arrX[0]) || (val > arrX[ARR_SIZE - 1]))
  {
    return -1;
  }
  // val must exist within arrX
  // Find which interval it exists in
  int low_ind = 0;
  for (int i = 0; i < ARR_SIZE - 1; i++)
  {
    if (val == arrX[i])
    {
      return arrY[i];
    }
    low_ind = i;
    if ((val >= arrX[i]) && val < arrX[i + 1])
    {
      break;
    }
  }
  // interpolate between
  float m = (arrY[low_ind + 1] - arrY[low_ind]) / (arrX[low_ind + 1] - arrX[low_ind]);
  float deltaX = val - arrX[low_ind];
  return arrY[low_ind] + m * deltaX;
}

int main()
{
  // Usage Examples

  // Q1
  // printf("Q1 Usage Example: %s\n", (C_TO_F(0) == 32) ? "PASS" : "FAIL");
  printf("Q1 Usage Example: %s\n", (C_TO_F(0) == 32) ? "PASS" : "FAIL");
  printf("Q1 Usage Example: %f\n", (C_TO_F(5.5)));
  uint8_t x = 20;
  printf("Q2 Usage Example: %d\n", computeSquareADC(&x));
  uint8_t test1 = 0b10000000; // bit 7 set
  uint8_t test2 = 0b00001000; // bit 3 set
  uint8_t test3 = 0b10001000; // both bits set
  uint8_t test4 = 0b00000000; // neither set
  uint8_t test5 = 0b11110111; // all bits set

  swapBits(&test1);
  printf("Question 3 Test1: 0x%02X\n", test1); // Expect 0x08
  swapBits(&test2);
  printf("Question 3 Test2: 0x%02X\n", test2); // Expect 0x80
  swapBits(&test3);
  printf("Question 3 Test3: 0x%02X\n", test3); // Expect 0x88 (no change)
  swapBits(&test4);
  printf("Question 3 Test4: 0x%02X\n", test4); // Expect 0x00
  swapBits(&test5);
  printf("Question 3 Test5: %s\n", test5 == 0x7F ? "PASS" : "FAIL"); // Expect 0x7F (bits 7 and 3 swapped)
  // Q4
  // printf("Q4 Usage Example: %s\n", (updateStateMachine(COIN) == READY) ? "PASS" : "FAIL");

  state = IDLE;
  printf("Q4 Usage Example: %s\n", (updateStateMachine(COIN) == READY) ? "PASS" : "FAIL");
  printf("Q4 Usage Example: %s\n", (updateStateMachine(BUTTON) == VENDING) ? "PASS" : "FAIL");
  float tests[] = {-1, 0, 0.5, 1, 1.5, 2, 2.5, 3.5, 4, 5};
  int n_tests = sizeof(tests) / sizeof(tests[0]);

  for (int i = 0; i < n_tests; i++)
  {
    float input = tests[i];
    float result = interpolate(input);
    printf("Question 5 interpolate(%.2f) = %.2f\n", input, result);
  }
  return 0;
}