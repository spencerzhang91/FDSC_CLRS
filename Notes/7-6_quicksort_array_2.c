// 7-6_quicksort_array_2.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SWAP(a, b, t) ((t)=(a));((a)=(b));((b)=(t))
#define SIZE 10

void quicksort(int list[], int a, int b);
void display(int list[], int size);

int main(void)
{
    int array[SIZE] = {17,10,4,8,21,15,7,32,86,41};
    display(array, SIZE);
    quicksort(array, 0, 9);
    display(array, SIZE);

    return 0;
}

void quicksort(int list[], int a, int b)
{
    /* Trivially modified version of 7-6_quicksort_array.c
    using list[a] as pivot instead of list[b] */
    int pivot, left, right;
    int temp;
    if (a < b)
    {
        pivot = list[a];
        left = a + 1; right = b;
        while (left <= right)
        {
            while (list[left] < pivot)
                left++;
            while (list[right] > pivot)
                right--;
            if (left <= right)
            {
                SWAP(list[left], list[right], temp);
                left++; right--;
            }
        }
        SWAP(list[a], list[right], temp);
        quicksort(list, a, right-1);
        quicksort(list, right+1, b);
    }
}

void display(int list[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);
    puts("");
}