/* 7-5-1_ShellSort.c */
// Shell sort is an augmented version of insertion sort
#include <stdio.h.>
#define SIZE 11

void shell_sort(int list[], int n);
void display(int list[], int n);

int main(void)
{
    int array[SIZE] = {10, 7, 11, 19, 4, 3, 42, 91, 5, 33, 8};
    display(array, SIZE);
    shell_sort(array, SIZE);
    display(array, SIZE);

    return 0;
}

void shell_sort(int list[], int n)
{
    int i, j, step, next;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i += step)
        {
            next = list[i];
            for (j = i - step; j >= 0 && next < list[j]; j -= step)
                list[j+step] = list[j];
            list[j+step] = next;
        }
}

void display(int list[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}
