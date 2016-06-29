// bubble sort algorithm: the most simple sorting algorithm.
#include <stdio.h>
#define SIZE 11

void bubble_sort(int list[], int n);
void display(int list[], int n);
void swap(int *a, int *b);

int main(void)
{
    int array[SIZE] = {10, 7, 11, 19, 4, 3, 42, 91, 5, 33, 8};
    display(array, SIZE);
    bubble_sort(array, SIZE);
    display(array, SIZE);

    return 0;
}

void bubble_sort(int list[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (list[i] > list[j])
                swap(&list[i], &list[j]);
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