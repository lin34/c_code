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
