/* quick sort algorithm */
#include <stdio.h>
#define SIZE 11

void display(int list[], int n);
void swap(int *a, int *b);
void qsort(int list[], int start, int end);
void quick_sort(int list[], int n);

int main(void)
{
    int array[SIZE] = {10, 7, 11, 19, 4, 3, 42, 91, 5, 33, 8};
    display(array, SIZE);
    quick_sort(array, SIZE);
    display(array, SIZE);

    return 0;
}

void qsort(int list[], int start, int end)
{
    /* For a list has N elements, start = 0 and end = N - 1 */
    if (start >= end)
        return;
    int i, j, pivot;
    i = start; j = end - 1; pivot = end;
    while (i < j)
    {
        for (; list[i] < list[pivot]; i++)
            continue;
        for (; list[j] > list[pivot]; j--)
            continue;
        if (i < j)
        {
            swap(&list[i], &list[j]);
            i++; j--;
        }
    }
    swap(&list[i], &list[pivot]);
    qsort(list, start, i - 1);
    qsort(list, i + 1, end);
}

void quick_sort(int list[], int n)
{
    qsort(list, 0, n - 1);
}

void display(int list[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}