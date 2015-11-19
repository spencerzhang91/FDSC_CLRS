/* excercise 5.6.4.c */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
    /* other fields */
} element;

element heap[MAX_ELEMENTS]; // here define it as global variable
int n = 0;

void delete_priority(element del, int *n);
void change_priority(element origin, element newp, int *n);
int inheap(element item, int n);
void insert_max_heap(element item, int *n);
element delete_max_heap(int *n);
void traverse(void);

int main(void)
{
    // create a max heap first
    for (int j = 1; j < 11; j++)
    {
        element temp;
        temp.key = j;
        insert_max_heap(temp, &n);
    }
    traverse();
    element origin = {3};
    element newp = {33};
    change_priority(origin, newp, &n);
    traverse();
    element del = {7};
    delete_priority(del, &n);
    traverse();
    
    return 0;
}

void delete_priority(element del, int *n)
{
    if (!inheap(del, *n))
    {
        printf("The element you want to delete is not in the heap.\n");
        return;
    }
    change_priority(del, heap[1], n);
    delete_max_heap(n);
}

void change_priority(element origin, element newp, int *n)
{
    /* origin: the assumed element to be in the heap;
       newp: new key to replace origin if origin in heap, otherwise add it in;
       n: the number of elements of the heap.
    */
    int parent, child;
    int index = inheap(origin, *n);
    parent = index; child = parent * 2;
    if (!index)
    {
        printf("Origin not in the heap, inserting...\n");
        insert_max_heap(origin, n);
    }
    else
    {
        if (newp.key > heap[index/2].key)
        {
            while ((newp.key > heap[index/2].key) && (index != 1))
            {
                heap[index] = heap[index/2];
                index /= 2;
            }
            heap[index] = newp;
        }
        else
        {
            while (child <= *n)
            {
                if ((child < *n) && (heap[child].key < heap[child+1].key))
                    child++;
                if (newp.key >= heap[child].key)
                    break;
                heap[parent] = heap[child];
                child *= 2;
            }
            heap[parent] = newp;
        }
    }
}

int inheap(element item, int n)
{
    for (int i = 1; i <= n; i++)
        if (item.key == heap[i].key)
            return i;
    return false;
}

void insert_max_heap(element item, int *n)
{
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.\n");
        exit(EXIT_FAILURE);
    }
    int i = ++(*n); // this is equal to i = *n + 1; (*n) += 1;
    while ((item.key > heap[i/2].key) && (i != 1))
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

void traverse(void)
{
    for (int i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    puts("\n");
}

element delete_max_heap(int *n)
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
