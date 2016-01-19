/* C implementation of non in-place heap sort algorithm, using MinHeap ADT */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "MinHeap.h"

void heapsort(int **array, int len);
void display(int *array, int len);

int main(void)
{
    int numbers[10] = {1,22,3,7,100,53,17,65,8,9};
    display(numbers, 10);
    heapsort(&numbers, 10);
    display(numbers, 10);

    return 0;
}

void heapsort(int **array, int len)
{
    MinHeap heap = Create(len);
    for (int i = 0; i < len; i++)
        Insert(heap, (*array)[i]);
    int j = 0;
    while (!IsEmpty(heap) && j <= len)
        (*array)[j++] = Delete(heap);
}

void display(int *array, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    puts("");
}