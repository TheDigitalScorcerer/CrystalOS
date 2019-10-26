#ifndef MEMORY_H
#define MEMORY_H 1

#define NULL ((void *)0)
#define INITMEM_MALLOC 65536

char memory[INITMEM_MALLOC];

struct block
{
    unsigned long size;
    unsigned char free;
    struct block* next;
};

struct block *freeList = (struct block*)(void*)memory;

void split_malloc(struct block *fitting_slot, unsigned long size);
void initialise_malloc();
void *malloc(unsigned long size);
void merge_malloc();
void free(void* ptr);

#endif