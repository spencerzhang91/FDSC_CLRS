/* Additional Excerices of chapter 2 */
/* Total 10 problems, 1 of ten*/
/* Exercise 2.8.1.c */
#include <stdio.h>
#define ElementType int
#define N 5

void invert(ElementType *source, ElementType *target);
void display(ElementType *array, int n);

int main(void)
{
    ElementType list[N] = {1,2,3,4,5};
    ElementType result[N];
    invert(list, result);
    display(list, N);
    display(result, N);

    return 0;
}

void invert(ElementType *source, ElementType *target)
{
    int j = N-1, i = 0;
    for (; i < N; i++, j--)
    	target[i] = source[j];
}

void display(ElementType *array, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	putchar('\n');
}