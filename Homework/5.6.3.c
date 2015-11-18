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

void change_priority(element origin, int newp, int *n)
{
    /* origin: the assumed element to be in the heap;
       newp: new key to replace origin if origin in heap, otherwise add it in;
       n: the number of elements of the heap */

}

bool inheap(element item, int *n)
{
    for (int i = 1; i <= *n; i++)
        if (item == heap[i])
            return true;
    return false;
}