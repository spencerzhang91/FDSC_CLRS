/* deletion of min heap */
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
    /* other fields */
} element;

element heap[MAX_ELEMENTS];
int n = 0;

element heap[MAX_ELEMENTS];
int n = 0;

void insert_min_heap(element item, int *n)
{
    /* insert item into a min heap of current size *n */
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.\n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key < heap[i/2].key))
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}