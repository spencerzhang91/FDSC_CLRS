/* Another implementation of array based max heap ADT */
#include <stdlib.h>
#define MAXSIZE 100
#define MAXDATA 10000

typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *elements;      // array
    int size;                   // current size
    int capacity;               // max element number
}

MaxHeap Create(int MAXSIZE)
{
    /* create a emtpy max heap with capacity of MAXSIZE */
    MaxHeap H = (MaxHeap)malloc( sizeof(struct HeapStruct));
    H->elements = (ElementType)malloc((MAXSIZE+1) * sizeof(ElementType));
    H->size = 0;
    H->capacity = MAXSIZE;
    H->elements[0] = MAXDATA;   // sentinel

    return H;
}

void Insert(MaxHeap H, ElementType item)
{
    int i;
    if (IsFull(H))
    {
        printf("The max heap is full.\n");
        return;
    }
    i = ++H->size;
    for (; H->elements[i/2] < item; i /= 2)
    // when use a large enough sentiel, no need to add(i>1) in for loop
        H->elements[i] = H->elements[i/2];
    H->elements[i] = item;
}

ElementType Delete(MaxHeap H)
{
    /* delete and return the max element from the heap, which is the root */
    int parent, child;
    ElementType MaxItem, temp;
    if (IsEmpty(H))
    {
        printf("The heap is empty.\n");
        return;
    }
    return MaxItem;
}