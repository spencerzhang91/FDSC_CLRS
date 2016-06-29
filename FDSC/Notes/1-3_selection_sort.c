/* selection sort algorithm */
/* code list 1-3 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int list[], int n);
int main(void)
{
    int i, n;
    int list[MAXSIZE];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);
    if (n < 1 || n > MAXSIZE)
    {
        fprintf(stderr, "Improper value of n \n");
        exit(1);
    }
    for (i = 0; i < n; i++)                             /* randomly generate numbers */
    {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }
    sort(list, n);
    printf("\nSorted array: \n");
    for (i = 0; i < n; i++)                             /* print out sorted numbers */
        printf("%d ", list[i]);
    printf("\n");
    
    return 0;
}

void sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (list[min] > list[j])
                min = j;
        SWAP(list[i], list[min], temp);
    }
}
