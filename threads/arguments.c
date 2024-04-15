#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *myTurn(void *arg)
{
    int *x = (int *)arg;
    for (int i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My turn %d %d\n", i, *x);
        (*x)++;
    }
    return NULL;
}

void *yourTurn(void *arg)
{
    int *iptr = (int *)malloc(sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        sleep(2);
        printf("Your turn %d\n", i);
        (*iptr)++;
    }
    return iptr;
}

int main()
{
    pthread_t myThread1, myThread2;
    int x = 5;
    int *iptr;
    pthread_create(&myThread1, NULL, myTurn, &x);
    pthread_create(&myThread2, NULL, yourTurn, NULL);
    // pthread_create(&yourThread, NULL, yourTurn, NULL);
    // joining makes program wait until thread finishes
    pthread_join(myThread1, NULL); // Second arg is the attributes
    // Thread2 returns a int *, and we want a pointer to this
    //  passes a reference to a pointer to pthread_join
    // copies the return value of the thread into memory
    pthread_join(myThread2, (void *)&iptr);
    printf("final value myTurn %d\n", x);
    printf("final value yourTurn %d\n", *iptr);
}