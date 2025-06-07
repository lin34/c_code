#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdio.h>

// clang threads.c
void *myturn(void *arg)
{
    int *iptr = (int *)arg;
    for (int i = 1; i < 8; i++)
    {
        sleep(1);
        printf("my turn %d\n", i, *iptr);
        (*iptr)++;
    }
    return NULL;
}

void *yourturn()
{
    for (int i = 1; i < 5; i++)
    {
        printf("your turn %d\n", i);
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_t newthread;
    int v = 5;
    pthread_create(&newthread, NULL, myturn, &v);
    yourturn();

    // wait until the thread is done befor we exit.
    pthread_join(newthread, NULL);
    printf("thread's done: value: %d", v);
}
