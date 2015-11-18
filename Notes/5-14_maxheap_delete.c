/* deletion of max heap */
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
    /* other fields */
} element;

element heap[MAX_ELEMENTS];
int n = 0;

void delete_max_heap(int *n)
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