/* C implementation of merge sort algorithm */
/* dirver's license application code is like: 粤Abc#********/
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MAXLEN 6

void Msort(ElementType *A, ElementType *temp, int left, int right);
void MergeSort(ElementType *A, int N);
void Merge(ElementType *A, ElementType *temp, int lpos, int rpos, int rend);
void display(ElementType *array, int len);

int main(void)
{
    ElementType array[MAXLEN] = {10, 4, 2, 14, 44, 1};
    display(array, MAXLEN);
    MergeSort(array, MAXLEN);
    display(array, MAXLEN);

    return 0;
}

void Msort(ElementType *A, ElementType *temp, int left, int right)
{
    int center;
    if (left < right)
    {
        center = (left + right) / 2;
        Msort(A, temp, left, center);
        Msort(A, temp, center+1, right);
        Merge(A, temp, left, center+1, right);
    }
}

void MergeSort(ElementType *A, int N)
{
    ElementType *temp;
    temp = (ElementType *)malloc(N * sizeof(ElementType));
    if (temp != NULL)
    {
        Msort(A, temp, 0, N-1);
        free(temp);
    }
    else
        printf("No space for temp array.\n");
}

void Merge(ElementType *A, ElementType *temp, int lpos, int rpos, int rend)
{
    /* lpos::= start of left half, rpos::= start of right half */
    int i, lend, numelements, temppos;
    lend = rpos -1;
    temppos = lpos;
    numelements = rend - lpos + 1;
    /* main loop */
    while (lpos <= lend && rpos <= rend)
    {
        if (A[lpos] <= A[rpos])
            temp[temppos++] = A[lpos++];
        else
            temp[temppos++] = A[rpos++];
    }
    while (lpos <= lend)
        temp[temppos++] = A[lpos++];
    while (rpos <= rend)
        temp[temppos++] = A[rpos++];
    /* copy temp array back to A */
    for (i = 0; i < numelements; i++, rend--)
        A[rend] = temp[rend];
}

void display(ElementType *array, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
}