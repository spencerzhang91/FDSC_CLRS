#include <stdio.h>
#define MAX(a, b) ((a)>(b))? (a): (b)
#define SWAP(x, y, t) (t)=(x);(x)=(y);(y)=(t)
#define N 10

void max_heapify1(int array[], int n, int i);
void max_heapify2(int array[], int n, int i);
void display(int array[], int len);
void create_maxheap(int array[], int n);
void heapsort(int array[], int n);

int main(void)
{
    int A[11] = {0, 2, 1, 7, 8, 45, 11, 23, 9, 74, 4};
    display(A, 11);
    create_maxheap(A, N);
    // display(A, 11);
    heapsort(A, N);
    display(A, 11);

    return 0;
}


void max_heapify1(int array[], int n, int i)
{
    /* n is the total nodes in the heap
     * i is the start node to call this function
     * n is also the last suffix of array, though total length of array
     is n + 1 (first element of the array is not used.)
     */
    while (i <= n/2)
    {
        int temp;
        if (i*2+1 <= n)
        {
            int child = MAX(array[i*2], array[i*2+1]);
            if (child > array[i])
            {
                if (array[i*2] == child)
                {
                    SWAP(array[i], array[i*2], temp);
                    i *= 2;
                }
                else if (array[i*2+1] == child)
                {
                    SWAP(array[i], array[i*2+1], temp);
                    i = 2*i+1;
                }
            }
            else break;
        }
        else if (i*2 <= n)
        {
            if (array[i] < array[i*2])
            {
                SWAP(array[i], array[i*2], temp);
                i *= 2;
            }
            else break;
        }
    }
}


void max_heapify2(int array[], int n, int i)
{
    /* n is the total nodes in the heap
     * i is the start node to call this function
     * n is also the last suffix of array, though total length of array
     is n + 1 (first element of the array is not used.)
     */
    if (i > n/2) return;

    int temp, child;
    if (i*2+1 <= n)
        child = MAX(array[i*2], array[i*2+1]);
    else
        child = array[i*2];
    if (child > array[i])
    {
        if (array[i*2] == child)
        {
            SWAP(array[i], array[i*2], temp);
            max_heapify2(array, n, i*2);
        }
        else if (array[i*2+1] == child)
        {
            SWAP(array[i], array[i*2+1], temp);
            max_heapify2(array, n, i*2+1);
        }
    }
}


void display(int array[], int len)
{
    int i = 0;
    for (; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


void create_maxheap(int array[], int n)
{
    int i = n / 2;
    while (i > 0)
    {
        max_heapify2(array, n, i);
        i--;
    }
}


void heapsort(int array[], int n)
{
    /* n is the total nodes in the heap
     * i is the start node to call this function
     * n is also the last suffix of array, though total length of array
     is n + 1 (first element of the array is not used.)
     */
    create_maxheap(array, n);
    for (int i = n; i > 1; i--)
    {
        int temp;
        SWAP(array[1], array[i], temp);
        //printf("i: %d -> %-5d", i, array[i]);
        //display(array, 11);
        max_heapify2(array, i-1, 1); // max_heapify1 ok but max_heapify2 bug
        //printf("             ");
        //display(array, 11);
        //printf("\n");
        /* decrement array size by 1, the biggest sorted item is put there
        so that when calls max_heapify from root, the sorted part remain
        untouched. */
    }
}