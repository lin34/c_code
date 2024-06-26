#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <stdbool.h>

// attach a shared memory block
// associated with file name
// create it if it doesn't exist
char *attach_memory_block(char *filename, int size);
bool detach_memory_block(char *block);
bool destroy_memory_block(char *filename);

// all of the programs will share these values
#define BLOCK_SIZE 4096
#define FILENAME "writeshmem.c"

#endif