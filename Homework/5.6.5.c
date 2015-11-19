/* excercise 5.6.5.c */
/* search time O(n) complexity */
typedef struct {
    int key;
    /* other fields */
} element;

element heap[MAX_ELEMENTS]; // here define it as global variable
int n = 0;
int inheap(element item, int n)
{
    for (int i = 1; i <= n; i++)
        if (item.key == heap[i].key)
            return i;
    return false;
}