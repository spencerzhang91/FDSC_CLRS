/* excercise 5.6.6.c */
/* max heap implementation using banary tree data structure, however
I found it very unnecessary to do it. */
#include <stdio.h>
#include <stdbool.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)
struct node {
    int key;
    struct node left;
    struct node right;
    struct node parent;
};

struct node heap[MAX_ELEMENTS];
int n = 0;

int main(void)
{
    return 0;
}

void insert_max_heap(struct node item, int *n)
{
    /* insert item into a max heap of current size *n */
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.\n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap.parent.key))
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

struct node delete(Heap heap)
{
    /* delete struct node with the highest key from heap */
    int parent, child; // variables of key
    struct node item, temp;
    if (HEAP_EMPTY(*n))
    {
        fprintf(stderr, "The heap is empty.\n");
        exit(EXIT_FAILURE);
    }
    /* save value of the struct node with the highest key */
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