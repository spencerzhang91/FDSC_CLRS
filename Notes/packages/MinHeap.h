/* C implementation of array based MinHeap ADT */
#ifndef _ARRAYMINHEAP_H
#define _ARRAYMINHEAP_H
#define MAXSIZE 100
#define ElementType int

typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *elements;      // array
    int size;                   // current size
    int capacity;               // max element number
};

MinHeap Create(int size);
void Insert(MinHeap heap, ElementType item);
ElementType Delete(MinHeap heap);
bool IsFull(MinHeap heap);
bool IsEmpty(MinHeap heap);

#endif