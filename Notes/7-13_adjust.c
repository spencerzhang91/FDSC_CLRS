/* 7-13_adjust.c 
adjust an unsorted array to a max heap in place
*/
#include <stdio.h>
#include <limits.h>
#define SWAP(X, Y, T) ((T)=(X));((X)=(Y));((Y)=(T))
void adjust(int list[], int root, int n);
void heapsort(int list[], int n);
void display(int *array, int len);

int main(void)
{
    int list[10] = {1,10,2,39,4,82,111,38,8,24};
    display(list, 10);
    heapsort(list, 10);
    display(list, 10);

    return 0;
}

void adjust(int list[], int root, int n)
{
    /* adjust an unsorted list to a max heap */
    int child, temp;
    temp = list[root];
    child = 2 * root; // left child
    while (child <= n)
    {
        if ((child < n) && (list[child] < list[child+1]))
            child++; // chose the bigger child to compare with root
        if (temp > list[child]) // no need to do further comparision
            break;
        else
        {
            list[child/2] = list[child]; // move to parent
            child *= 2;
        }
    }
    list[child/2] = temp;
}

void heapsort(int list[], int n)
{
    /* perform a heapsort on the array in place */
    int i, j;
    int temp;
    for (i = n/2; i > 0; i--)
        adjust(list, i, n);
    for (i = n-1; i > 0; i--)
    {
        SWAP(list[1], list[i+1], temp);
        adjust(list, 1, i);
    }
}

void display(int *array, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    puts("");
}