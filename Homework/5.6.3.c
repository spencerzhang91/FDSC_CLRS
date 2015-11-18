/* excercise 5.6.3.c */
#include <stdio.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
    /* other fields */
} element;

element heap[MAX_ELEMENTS]; // here define it as global variable
int n = 0;

void change_priority(element origin, element newp, int *n)
{
    /* origin: the assumed element to be in the heap;
       newp: new key to replace origin if origin in heap, otherwise add it in;
       n: the number of elements of the heap.
    */
    if (!inheap(origin, *n))
    {
        printf("Origin not in the heap, inserting...\n");
        insert_max_heap(origin, *n);
    }
    else
    {
        
    }

}

bool inheap(element item, int *n)
{
    for (int i = 1; i <= *n; i++)
        if (item == heap[i])
            return true;
    return false;
}

void insert_max_heap(element item, int *n)
{
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.\n");
        exit(EXIT_FAILURE);
    }
    int i = ++(*n); // this is equal to i = *n + 1; (*n) += 1;
    while (item.key > heap[i/2])
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}