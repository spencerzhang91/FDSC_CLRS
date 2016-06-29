/* 7-5_selection_Sort.c */
// C implementation of selection sort, both array and linked list
#include <stdio.h>
#define SIZE 11

void selection_sort(int array[], int n);
void display(int list[], int n);
void swap(int *a, int *b);

int main(void)
{
    int array[SIZE] = {10, 7, 11, 19, 4, 3, 42, 91, 5, 33, 8};
    display(array, SIZE);
    selection_sort(array, SIZE);
    display(array, SIZE);

    return 0;
}

void selection_sort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        swap(&array[min], &array[i]);
    }
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