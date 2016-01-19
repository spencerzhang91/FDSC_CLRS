/* C implementation of non in-place heap sort algorithm, using MinHeap ADT */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "MinHeap.h"
void heapsort(int **array, int len)
{
    MinHeap heap = Create(len);
    for (int i = 0; i < len; i++)
        Insert(heap, (*array)[i]);
    int j = 0;
    while (!IsEmpty(heap) && j <= len)
        (*array)[j++] = Delete(heap);
}