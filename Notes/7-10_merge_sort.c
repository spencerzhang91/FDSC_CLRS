/* 7-9_merge_pass & 7-10_merge_sort
Perform one pass of the merge sort. It merges adjacent pairs of subfiles from
list into sorted.
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void merge(int list[], int sorted[], int i, int m, int n);
void merge_pass(int list[], int sorted[], int n, int length);
void merge_sort(int list[], int n);
void print(int *list, int len);

int main(void)
{
    int unsorted[SIZE] = {2, 31, 7, 10, 81, 45, 23, 73, 19, 4};
    merge_sort(unsorted, SIZE);
    print(unsorted, SIZE);

    return 0;
}

void merge(int list[], int sorted[], int i, int m, int n)
{
    /* merge two sorted files: list[i],...,list[m], and list[m+1],...,list[n].
    These files are sorted to obtain a sorted list: sorted[i],...,sorted[n].
    */
    int j, k, t;
    j = m + 1; // index for the second sublist
    k = i;     // index for the sorted list
    while (i <=m && j <= n)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > m)
    // sorted[k],...,sorted[n] = list[j],...,list[n]
        for (t = j; t <= n; t++)
            sorted[k+t-j] = list[t];
    else
    // sorted[k],...,sorted[n] = list[i],...,list[m]
        for (t = i; t <= m; t++)
            sorted[k+j-1] = list[t];
}

void merge_pass(int list[], int sorted[], int n, int length)
{
    // n is the length of the list and length the length of subfile.
    int i, j;
    for (i = 0; i <= n - 2 * length; i += 2 * length)
        merge(list, sorted, i, i+length-1, i+2*length-1);
    if (i + length < n)
        merge(list, sorted, i, i+length-1, n-1);
    else
        for (j = i; j < n; j++)
            sorted[j] = list[j];
}

void merge_sort(int list[], int n)
{
    // perform a merge sort on the file
    int length = 1; // current length being merged
    int extra[SIZE];
    while (length < n)
    {
        merge_pass(list, extra, n, length);
        length *= 2;
        merge_pass(extra, list, n, length);
        length *= 2;
    }
}

void print(int *list, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", list[i]);
    puts("");
}