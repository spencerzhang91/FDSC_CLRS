/* 7-15_LSDsort.c */
/* The original implementation from FDSC book */
#include <stdio.h>
#define MAX_DIGIT 3 // number between 0 to 999
#define RADIX_SIZE 10

typedef struct list_node *list_pointer
struct list_node {
    int key[MAX_DIGIT];
    list_pointer link;
};

list_pointer radix_sort(list_pointer ptr)
{
    // radix sort using a linked list
    list_pointer front[RADIX_SIZE], rear[RADIX_SIZE];
    int i, j, digit;
    for (i = MAX_DIGIT-1; i >= 0; i--)
    {
        for (j = 0; j < RADIX_SIZE; j++)
            front[j] = rear[j] = NULL;
        while (ptr)
        {
            digit = ptr->key[i];
            if (!front[digit])
                front[digit] = ptr;
            else
                rear[digit]->link = ptr;
            rear[digit] = ptr;
            ptr = ptr->link;
        }
        /* reestablish the linked list for the next pass */
        ptr = NULL;
        for (j = RADIX_SIZE-1; j >= 0 j--)
            if (front[j])
            {
                rear[j]->link = ptr;
                ptr = front[j];
            }
    }
    return ptr;
}