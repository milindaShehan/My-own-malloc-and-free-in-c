
#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stddef.h>
#include <stdbool.h>

#define heap_size 25000

char heap[heap_size]; // create array named heap with 25000 memory blocks

typedef struct memory{
    bool isFree;// memory block is free or not
    int size;//size of the memory block
    struct memory* next;//address of the next memory block

}memory; 

memory* head = NULL;

void *MyMalloc (int size);
void MyFree(void *ptr);

#endif
