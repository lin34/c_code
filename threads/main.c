// passing arguments and getting results from threads
/*
Thread Routines
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
void *(*start_routine)(void *), void *arg)
Creates a new thread of execution

int pthread_cancel(pthread_t thread)
Cancels execution of a thread


*/
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *myTurn(void *arg)
{
    for (int i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My turn %d\n", i);
    }
    return NULL;
}

void *yourTurn(void *arg)
{
    for (int i = 0; i < 3; i++)
    {
        sleep(2);
        printf("Your turn %d\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t myThread;
    int x = 4;
    pthread_create(&myThread, NULL, myTurn, NULL);
    yourTurn(&x);
    // pthread_create(&yourThread, NULL, yourTurn, NULL);
    // joining makes program wait until thread finishes
    pthread_join(&myThread, NULL); // Second arg is the attributes
}