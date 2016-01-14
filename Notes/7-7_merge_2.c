// 7-7_merge_2.c 
#include <stdio.h>
#include <stdlib.h>
#define S1 5
#define S2 5

int *merge(int list1[], int list2[], int n, int m);
void print(int *list, int len);

int main(void)
{
    int array1[S1] = {1,2,4,6,9};
    int array2[S2] = {3,5,8,10,20};
    int *res;
    res = merge(array1, array2, S1, S2);
    print(res, S1+S2);

    return 0;
}

int *merge(int list1[], int list2[], int n, int m)
{
    /* merge two sorted lists list1 & list2 with length n and m, 
    return a sorted merged mlist with length n+m
    */
    int i = 0, j = 0, k = 0;
    int *sorted = (int *)malloc(sizeof(int)*(m + n));
    while (i < n && j < m)
    {
        if (list1[i] <= list2[j])
            sorted[k++] = list1[i++];
        else
            sorted[k++] = list2[j++];
    }
    while (i < n)
        sorted[k++] = list1[i++];
    while (j < m)
        sorted[k++] = list2[j++];
    return sorted;
}

void print(int *list, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", list[i]);
    puts("");
}