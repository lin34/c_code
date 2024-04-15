#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define BIG 1000000000UL
uint32_t counter = 0;

void *count_to_big(void *arg)
{
    for (uint32_t i = 0; i < BIG; i++)
    {
        counter++;
    }
    return NULL;
}

int main()
{
    pthread_t count1, count2;
    pthread_create(&count1, NULL, count_to_big, NULL);
    pthread_create(&count2, NULL, count_to_big, NULL);
    // This represents a software bug called a race condition
    // counter++ has 2 threads doing the following:
    // int temp = counter
    // counter = temp + 1; --> with 2 threads, counter will
    // only be incremented by 1 instead of 2 since it reads
    // the same value! The two threads are "racing" for read/write access

    // A solution to this is to make the operation with an atomic

    pthread_join(count1, NULL);
    pthread_join(count2, NULL);
    printf("Done. Counter %u\n", counter);
}