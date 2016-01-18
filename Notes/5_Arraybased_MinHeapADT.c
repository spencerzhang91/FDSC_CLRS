/* Implementation of array based min heap ADT */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
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

int main(void)
{
    printf("%d", INT_MIN);

    return 0;
}

MinHeap Create(int size)
{
    /* create a emtpy min heap with capacity of size */
    MinHeap heap = (MinHeap)malloc(sizeof(struct HeapStruct));
    heap->elements = (ElementType *)malloc((size+1) * sizeof(ElementType));
    heap->size = 0;
    heap->capacity = size;
    heap->elements[0] = INT_MIN;   // sentinel

    return heap;
}

void Insert(MinHeap heap, ElementType item)
{
    int i;
    if (IsFull(heap))
    {
        printf("The min heap is full.\n");
        return;
    }
    i = ++(heap->size);
    while (item < heap->elements[i/2]) // because sentinel exists
    {
        heap->elements[i] = heap->elements[i/2];
        i /= 2;
    }
    heap->elements[i] = item;
}

ElementType Delete(MinHeap heap)
{
    /* delete and return the min element from the heap, which is the root */
    int parent, child;
    ElementType MinItem, temp;
    if (IsEmpty(heap))
    {
        printf("The min heap is empty.\n");
        exit(EXIT_FAILURE);
    }
    MinItem = heap->elements[1];
    temp = heap->elements[(heap->size)--];
    parent = 1; child = 2;
    while (child <= heap->size)
    {
        if ((child <= heap->size) &&
            (heap->elements[child] > heap->elements[child+1]))
            child++;
        if (temp <= heap->elements[child]) break;
        heap->elements[parent] = heap->elements[child];
        parent = child;
        child *= 2;
    }
    heap->elements[parent] = temp;
    return MinItem;
}

bool IsFull(MinHeap heap)
{
    return (heap->size >= heap->capacity);
}

bool IsEmpty(MinHeap heap)
{
    return (heap->size == 0);
}