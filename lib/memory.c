#include "memory.h"

void initialise_malloc(){
    freeList->size = INITMEM_MALLOC - sizeof(struct block); 
    freeList->free = 1;
    freeList->next = NULL;
}

void split(struct block *fitting_slot, unsigned long size){
    struct block *new = (void*)(/*(void*)*/fitting_slot + size + sizeof(struct block));
    new->size=(fitting_slot->size)-size-sizeof(struct block);
    new->free = 1;
    new->next = fitting_slot->next;
    fitting_slot->size = size;
    fitting_slot->free = 0;
    fitting_slot->next = new;
}

void *malloc(unsigned long size){
    struct block *curr, *prev;
    void *result;
    if (!(freeList->size)) {
        initialize();
        //printf("Memory initialized\n");
    }
    curr = freeList;
    while ((((curr->size) < size) || ((curr->free) == 0)) && (curr->next!=NULL)) {
        prev=curr;
        curr=curr->next;
        //printf("One block checked\n");
    }
    if ((curr->size) == size) {
        curr->free = 0;
        result = (void*)(++curr);
        //printf("Exact fitting block allocated\n");
        return result;
    }
    else if ((curr->size) > (size+sizeof(struct block))) {
        split(curr, size);
        result=(void*)(++curr);
        //printf("Fitting block allocated with a split\n");
        return result;
    }
    else {
        result = NULL;
        //printf("Sorry. No sufficient memory to allocate\n");
        return result;
    }
}

void merge() {
    struct block *curr, *prev;
    curr = freeList;
    while ((curr->next) != NULL) {
        if ((curr->free) && (curr->next->free)) {
            curr->size += (curr->next->size)+sizeof(struct block);
            curr->next = curr->next->next;
        }
        prev = curr;
        curr = curr->next;
    }
}

void free(void* ptr) {
    if(((void*)memory <= ptr) && (ptr <= (void*)(memory + INITMEM_MALLOC))) {
        struct block* curr = ptr;
        --curr;
        curr->free = 1;
        merge();
    }
    // else invalid
}

void *calloc(unsigned long items, unsigned long item_size) {
    char* ptr;
    ptr = malloc(items * item_size);
    for (unsigned long i = 0; i < items * item_size; i++)
    {
        ptr[i] = 0;
    }
    return (void*)ptr;
}

// Could be buggy
void *realloc(void* ptr, unsigned long size) {
    void* newPtr = malloc(size);
    memcpy(ptr, newPtr, ((struct block*)ptr)->size);
    free(ptr);
    return newPtr;
}

void* memcpy(void* src, void* dst, unsigned long size) {
    char *src_c = src;
    char *dst_c = dst;
    for (unsigned long i = 0; i < size; i++)
    {
        dst_c[i] = src_c[i];
    }
}

unsigned char memcmp(void* left, void* right, unsigned long size) {
    char *left_c = left;
    char *right_c = right;
    for (unsigned long i = 0; i < size; i++)
    {
        if (left_c[i] != right_c[i])
        {
            return 0;
        }
    }
    return 1;
}