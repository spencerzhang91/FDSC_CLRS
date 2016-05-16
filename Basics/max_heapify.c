#include <stdio.h>
#define MAX(a, b) ((a)>(b))? (a): (b)
#define SWAP(x, y, t) (t)=(x);(x)=(y);(y)=(t)

void max_heapify1(int array[], int n, int i);
void max_heapify2(int array[], int n, int i);
void display(int array[], int n);
void create_maxheap(int array[], int n);

int main(void)
{
    int A[11] = {0, 2, 1, 7, 8, 45, 11, 23, 9, 74, 4};
    display(A, 11);
    max_heapify1(A, 10, 2);
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

    int temp;
    int child = MAX(array[i*2], array[i*2+1]);
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


void display(int array[], int n)
{
    int i = 0;
    for (; i < n; i++)
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