#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////
// 1) Macro (10 points) --> correct
//    Create a macro (named C_TO_F) to convert from degrees Celsius to Fahrenheit
//    Macro should work for integer or floating point types
//    Note: degF = degC * (9/5) + 32
// Answer: TODO
#define C_TO_F(degC) (degC * (9.0/5.0) + 32.0)

////////////////////////////////////////////////////////////////////////////////
// 2) Function Debug (5 points)
// The following function should compute and return the square of the value 
// pointed to by x.  Correct any mistakes in the implementation.

uint32_t computeSquareADC(volatile uint32_t *x)
{
    uint32_t retval = (*x) * (*x);
    return retval;
}


////////////////////////////////////////////////////////////////////////////////
// 3) Bit Manipulation (10 points)
//    Write a function that swaps the highest bits in each nibble of the byte
//    pointed to by the pointer b. (e.g., bits: 1 _ _ _ 0 _ _ _ -> 0 _ _ _ 1 _ _ _)
//    The bits designated by '_' in the example above should not be swapped.
 
void swapBits(uint8_t* b)
{
    // Answer: TODO
    //one byte is 2 nibbles 1000 0001 --> 0000 1001 or 129 to 9
    //use bit masking
    bool nib1_set = ((*b & (1 << 7)));
    bool nib2_set = ((*b & (1 << 3)));
    if(nib1_set){
      *b |= (1 << 3);
    }
    else{
      *b &= ~(1 << 3);
    }
    if(nib2_set){
      *b |= (1<<7);
    }
    else{
      *b &= ~(1<<7);
    }

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
  if(input == COIN)
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
  if(input == BUTTON)
  {
    state = VENDING;
  }
  else if(input ==COIN_RETURN)
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
  if(input == VEND_COMPLETE)
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
    if(state == IDLE)
    {
      idleStateHandler(input);
    }
    else if(state == READY)
    {
      readyStateHandler(input);
    }
    else if(state == VENDING)
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
 
#define ARR_SIZE (6) //Fill this out
float arrX[ARR_SIZE] = {0,1,2,3,4,6};
float arrY[ARR_SIZE] = {0,1,2,3,4,5};
float interpolate(float val)
{
  //check bounds
  if(val < arrX[0] || val > arrX[ARR_SIZE - 1]){
    return -1; //unable to interpolate
  }
    for(int i = 0; i < ARR_SIZE; i++){
      if(val == arrX[i]){
        return arrY[i];
      }
    }
    for(int i = 0; i < ARR_SIZE - 1; i++){
      if(arrX[i+1] > val){//range bound found
        float ans = arrY[i] + (val - arrX[i])*(arrY[i+1] - arrY[i])/(arrX[i+1] - arrX[i]);
        return ans;
      }
    }
    
    return 0.0f;
    
}
 
int main()
{
    // Usage Examples

    // Q1
    // printf("Q1 Usage Example: %s\n", (C_TO_F(0) == 32) ? "PASS" : "FAIL");
    printf("Q1 Usage Example: %s\n", (C_TO_F(0) == 32) ? "PASS" : "FAIL");
    printf("Q1 Usage Example: %f\n", (C_TO_F(5.5)));
    uint32_t x = 20;
    printf("Q2 Usage Example: %d: %s\n", computeSquareADC(&x), (computeSquareADC(&x) == 400 ? "PASS": "FAIL"));
    uint8_t y = 129;
    swapBits(&y);
    printf("Q3 Usage Example: %d: %s\n", y, (y == 9) ? "PASS" : "FAIL");
// Q4
    // printf("Q4 Usage Example: %s\n", (updateStateMachine(COIN) == READY) ? "PASS" : "FAIL");


    state = IDLE;
    printf("Q4 Usage Example: %s\n", (updateStateMachine(COIN) == READY) ? "PASS" : "FAIL");
    printf("Q4 Usage Example: %s\n", (updateStateMachine(BUTTON) == VENDING) ? "PASS" : "FAIL");
    float ans1 = interpolate(0.5);
    float ans2 = interpolate(5);
    float ans3 = interpolate(3);
    printf("Q5 Usage Example: %f: %s\n",ans1, (ans1 == 0.5) ? "PASS" : "FAIL");
    printf("Q5 Usage Example: %f: %s\n",ans2, (ans2 == 4.5) ? "PASS" : "FAIL");
    printf("Q5 Usage Example: %f: %s\n",ans3, (ans3 == 3) ? "PASS" : "FAIL");
     return 0;
}