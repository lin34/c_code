/*
A semaphore is an unsigned integer used to coordinate two threads
It is a synchronization primative. It's operations are atomic.
The main two operations are {wait() , decrement} and {post ,inc}
*/
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>
#include <semaphore.h>
#include "shared_memory.h"

#define NUM_ITERATIONS 10

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage - %s [stuff to write]", argv[0]);
        return -1;
    }

    // grab the shared memory block
    char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
    if (block == NULL)
    {
        printf("ERROR: couldn't get block\n");
        return -1;
    }

    print
}
