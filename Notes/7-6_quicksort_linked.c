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
    int array[SIZE] = {17, 10, 4, 8, 21, 15, 7, 32, 86, 41};
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
    int length = Q->cursize; 
    if (length < 2)
        return;
    // devide
    int pivot = first(Q);
    Queue L = CreateQueue(length);
    Queue E = CreateQueue(length);
    Queue G = CreateQueue(length);
    printf("A\n");
    while (!QIsEmpty(Q))
    {
        if (first(Q) < pivot)
        {
            enqueue(L, dequeue(Q));
            puts("B");
        } 
        else if (first(Q) > pivot)
        {
            enqueue(G, dequeue(Q));
            puts("C");
        }
        else
        {
            enqueue(E, dequeue(Q));
            puts("D");
        }    
    }
    // conquer
    printf("E\n");
    quicksort(L);
    printf("F\n");
    quicksort(G);
    // concatenate results
    printf("G\n");
    while (!QIsEmpty(L))
    {
        enqueue(Q, dequeue(L));
        puts("H");
    }
    while (!QIsEmpty(E))
    {
        enqueue(Q, dequeue(E));
        puts("I");
    }
    while (!QIsEmpty(G))  // got you! the bug is: !QIsEmpty(Q)
    {
        puts("J1"); 
        enqueue(Q, dequeue(G));
        puts("J");
    }
    printf("k\n");
}
