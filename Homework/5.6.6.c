/* excercise 5.6.6.c */
/* max heap implementation using banary tree data structure */
#include <stdio.h>
#include <stdbool.h>

typedef ElementType int;
typedef heapnode *Heap;
struct heapnode {
    ElementType value;
    Heap lchild;
    Heap rchild;
    Heap parent;
};

int main(void)
{
    return 0;
}

void insert(Heap heap, ElementType item)
{
    /* insert item into a max heap of current size *n */
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.\n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i/2].key))
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

ElementType delete(Heap heap)
{
    /* delete element with the highest key from heap */
    int parent, child; // variables of key
    element item, temp;
    if (HEAP_EMPTY(*n))
    {
        fprintf(stderr, "The heap is empty.\n");
        exit(EXIT_FAILURE);
    }
    /* save value of the element with the highest key */
    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n)
    {
        /* find the larger child of the current paren */
        if ((child < *n) && (heap[child].key < heap[child+1].key))
            child++;
        /* move to next lower level */
        if (temp.key >= heap[child].key)
            break;
        heap[parent] = heap[child];
        parent =child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}