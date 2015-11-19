/* Implementation of array based max heap ADT */
#include <stdlib.h>
#define MAXSIZE 100
#define MINDATA 10000

typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *elements;      // array
    int size;                   // current size
    int capacity;               // max element number
}

MinHeap Create(int MAXSIZE)
{
    /* create a emtpy max heap with capacity of MAXSIZE */
    MaxHeap H = (MaxHeap)malloc( sizeof(struct HeapStruct));
    H->elements = (ElementType)malloc((MAXSIZE+1) * sizeof(ElementType));
    H->size = 0;
    H->capacity = MAXSIZE;
    H->elements[0] = MINDATA;   // sentinel

    return H;
}