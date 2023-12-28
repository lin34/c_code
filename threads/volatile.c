#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// volatile tells computer to not optimize variable
volatile bool done = false;

void *tfunc(void *arg)
{
    sleep(1);
    done = true;
    return NULL;
}

int main()
{
    pthread_t t1;
    pthread_create(&t1, NULL, tfunc, NULL);
    printf("Waiting...\n");
    // With compiler optimizations, this will wait forever
    // done is replaced with true. does not know thread will change it
    // when not used with volatile
    while (!done)
    {
    }
    printf("Ok. Moving on. \n");
}