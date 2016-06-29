// 7-7_merge_1.c
// merge in-place
#include <stdio.h>
#include <stdlib.h>
#define S 10

void merge(int list[], int sorted[], int i, int m, int n);
void print(int *list, int len);

int main(void)
{
    int array[S] = {1,2,4,6,9,3,5,8,10,20};
    int sorted[S];
    merge(array, sorted, 0, 4, 9);
    print(sorted, S);

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

void print(int *list, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", list[i]);
    puts("");
}