#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(int *argc, int *argv)
{
    if (fork() == 0)
    {
        printf("I'm childish\n");
    }
    else
    {
        printf("Hello world %d\n", getpid());
    }
}