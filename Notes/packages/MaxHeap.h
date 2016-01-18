/* C implementation of array based Max Heap ADT */
#ifndef _ARRAYMAXHEAP_H
#define _ARRAYMAXHEAP_H
#define MAXSIZE 100
#define ElementType int

typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *elements;      // array
    int size;                   // current size
    int capacity;               // max element number
};

MaxHeap Create(int size);
void Insert(MaxHeap heap, ElementType item);
ElementType Delete(MaxHeap heap);
bool IsFull(MaxHeap heap);
bool IsEmpty(MaxHeap heap);