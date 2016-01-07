/* 7-6_quicksort_linked.c
Actually I have to look up meterial about this algorithm in book DSAP to 
get more specific conduction. 
It's an implementation using linked list based queue, so that 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedQueue.h"
#define SIZE 10

void quicksort(Queue Q);

int main(void)
{
    int array[SIZE] = {1, 10, 4, 8, 21, 15, 7, 32, 86, 41};
    Queue numbers = ConstructQ(array, SIZE);
    displayQ(numbers);
    quicksort(numbers);
    displayQ(numbers);
    return 0;
}

void quicksort(Queue Q)
{
    /* This implementation uses queue ADT, just like 7-6_quicksort.py
    It's also a recursive approach. */
    if ((int length = Q->cursize) < 2)
        return;
    // devide
    int pivot = first(Q);
    Queue L = CreateQueue(length / 2 + 1);
    Queue E = CreateQueue(length / 2 + 1);
    Queue G = CreateQueue(length / 2 + 1);
    while (!QisEmpty(Q))
    {
        if (first(Q) < pivot)
            enqueue(L, dequeue(Q));
        else if (first(Q) > pivot)
            enqueue(G, dequeue(Q));
        else
            enqueue(E, dequeue(Q));
    }
    // conquer
    quicksort(L);
    quicksort(G);
    // concatenate results
    while (!QisEmpty(L))
        enqueue(Q, dequeue(L));
    while (!QisEmpty(E))
        enqueue(Q, dequeue(E));
    while (!QisEmpty(Q))
        enqueue(Q, dequeue(G));
}