/* excercise 1.2.2 on page 9 -- 1.2.2.c*/
/* Horner's Rule */
#include <stdio.h>
#define N 5

int sumpoly(int *list, int index, int x);
int main(void)
{
    int coefficients[N] = {1,2,3,4,5};
    int x = 1;
    int sum;
    sum = sumpoly(coefficients, 0, x);
    printf("%d", sum);   
    return 0;
}

int sumpoly(int *list, int index, int x)
{
    if (index == N-1)
        return list[N-1];
    else
        return list[index] + x * sumpoly(list, ++index, x);
}
