/* 7-6_quicksort_linked.c
Actually I have to look up meterial about this algorithm in book DSAP to 
get more specific conduction. 
It's an implementation using linked list based queue, so that 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedQueue.h"

void quicksort(int array[]);
static int array_len(int array[]);

int main(void)
{

    return 0;
}

void quicksort(int array[])
{
    /* This implementation uses a queue ADT, very much alike 7-6_quicksort.py
    It's also a recursive approach. */
    if ((int length = array_len(array)) < 2)
        return;
    // devide
    int pivot = array[0];
    Queue L = CreateQueue(length / 2 + 1);
    Queue E = CreateQueue(length / 2 + 1);
    Queue G = CreateQueue(length / 2 + 1);
    // yet done
}