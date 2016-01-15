// 7-9_merge_pass & 7-10_merge_sort
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAXSIZE 1000

void merge(int list[], int sorted[], int i, int m, int n);
void merge_pass(int list[], int sorted[], int n, int length);
void merge_sort(int list[], int n);
void print(int *list, int len);

int main(void)
{
    int unsorted[SIZE] = {2, 31, 7, 10, 81, 45, 23, 73, 19, 4};
    print(unsorted, SIZE);
    merge_sort(unsorted, SIZE);
    print(unsorted, SIZE);

    return 0;
}

void merge(int list[], int sorted[], int i, int m, int n)
{
    /* merge two sorted files: list[i],...,list[m], and list[m+1],...,list[n].
    These files are sorted to obtain a sorted list: sorted[i],...,sorted[n].
    */
    int t;
    int j = m + 1;
    int k = i;
    while (i <= m && j <= n)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    while (i <= m)
    	sorted[k++] = list[i++];
    while (j <= n)
    	sorted[k++] = list[j++];
}

void merge_pass(int list[], int sorted[], int n, int length)
{
    // n is the length of the list and length the length of subfile.
    int i, j;
    for (i = 0; i <= (n - 2 * length); i += (2 * length))
        merge(list, sorted, i, i+length-1, i+2*length-1);
    if (i + length < n)
        merge(list, sorted, i, i+length-1, n-1);
    else
        for (j = i; j < n; j++)
            sorted[j] = list[j];
}

void merge_sort(int list[], int n)
{
    /* Perform one pass of the merge sort. It merges adjacent pairs
	 of subfiles from list into sorted. n is the list length. 
	*/ 
    int length = 1; // current length being merged
    int extra[MAXSIZE];
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
