// Demonstrates memory manipulation functions in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int arr1[] = {1, 2};
    int arr2[] = {1, 2};
    if (memcmp(arr1, arr2, sizeof(arr1)))
    {
        printf("Arrays are the same\n");
    }
    else
    {
        printf("Arrays are not the same\n");
    }
    memset(arr1, 0, 2 * sizeof(int));
    return 0;
}