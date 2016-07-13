#include <stdio.h>
#include <stdlib.h>
#define LEN 10

void insertionSort(int *array, int len);
void showArray(int *array, int len);

int main(void)
{
    int list[LEN] = {15,23,51,1,9,7,3,5,13,11};
    showArray(list, LEN);
    insertionSort(list, LEN);
    showArray(list, LEN);

    return 0;
}

void insertionSort(int *array, int len)
{
    // This function performs insertion sort on a fixed length int array.
    for (int i = 1; i < len; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && (array[j] < key))
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void showArray(int *array, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
}