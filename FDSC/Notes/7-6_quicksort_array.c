/* 7-6_quicksort_array.c
Actually I have to look up meterial about this algorithm in book DSAP to 
get more specific conduction. Array based implementation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SWAP(a, b, t) ((t)=(a));((a)=(b));((b)=(t))
#define SIZE 10
typedef struct {
    int key;
    // other fields
} element;

void quicksort(element list[], int a, int b);
void display(element list[], int size);

int main(void)
{
    element array[SIZE] = {{17}, {10}, {4}, {8}, {21},
                           {15}, {7}, {32}, {86}, {41}};
    display(array, SIZE);
    quicksort(array, 0, 9);
    display(array, SIZE);
    return 0;
}

void quicksort(element list[], int a, int b)
{
    /* sort list[a], ..., list[b] into nondecreasing order on the
    key field. list[a].key is arbitrarily chosen as the pivot key. It
    is assumed that list[a].key <= lsit[b+1].key
    */
    int pivot, left, right;
    element temp;
    if (a < b)
    {
        left = a; right = b - 1;
        pivot = list[b].key;
        while (left <= right)
        {
            /* search ofr keys from the a and b sublists, swapping
            out-of-order elements until the a and b boundaries cross
            or meet. */
            while (list[left].key < pivot)
                left++; 
            while (list[right].key > pivot)
                right--;
            if (left <= right)
            {
                SWAP(list[left], list[right], temp);
                left++; right--;
            }
        }
        SWAP(list[b], list[left], temp);
        quicksort(list, a, left-1);
        quicksort(list, left+1, b);
    }
}

void display(element list[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", list[i].key);
    puts("");
}
