/* 7-8_merge_pass.c
Perform one pass of the merge sort. It merges adjacent pairs of subfiles from
list into sorted.
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void merge_pass(int list[], int sorted[], int n, int length);

int main(void)
{
    int unsorted[SIZE] = {2, 31, 7, 10, 81, 45, 23, 73, 19, 4};
    int sorted[SIZE];
    merge_pass(unsorted, sorted, SIZE, 1);

    return 0;
}

void merge_pass(int list[], int sorted[], int n, int length)
{
    // n is the length of the list and length the length of subfile.
    int i, j;
    for (i = 0; i <= n - 2 * length; i += 2 * length)
        merge(list, sorted, i, i + length - 1, i + 2 * length - 1);
    if (i + length < n)
        merge(list, sorted, i, i + length - 1, n - 1);
    else
        for (j = i; j < n; j++)
            sorted[j] = list[j];
}