/* 7-5_InsertionSort.c */
#include <stdio.h>
#define SIZE 5

typedef struct {
    int key;
    // any other possible fields
} element;

void insertion_sort(element list[], int n);

int main(void)
{
    element list[SIZE] = {{5},{3},{2},{6},{1}};
    insertion_sort(list, SIZE);

    return 0;
}

void insertion_sort(element list[], int n)
{
    // perform a insertion sort on the list
    int i, j;
    element next;
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next.key < list[j].key; j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
}