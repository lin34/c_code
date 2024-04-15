#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define BIG 1000000000UL
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_to_big(void *arg)
{
    for (uint32_t i = 0; i < BIG; i++)
    {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    // lets make the race condition atomic
    pthread_t count1, count2;
    pthread_create(&count1, NULL, count_to_big, NULL);
    pthread_create(&count2, NULL, count_to_big, NULL);

    pthread_join(count1, NULL);
    pthread_join(count2, NULL);
    printf("Done. Counter %u\n", counter);
}