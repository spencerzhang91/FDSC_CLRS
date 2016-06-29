/* 1.2.7.c */
/* calculate n! in both iterative way and recursive way */
#include <stdio.h>
int factorial_R(int n);
int factorial_I(int n);

int main(void)
{
	int n = 10;
	printf("[R]The factorial of %d is %d\n", n, factorial_R(n));
	printf("[I]The factorial of %d is %d\n", n, factorial_I(n));
	
	return 0;
}

int factorial_R(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial_R(n - 1);
}

int factorial_I(int n)
{
	int res = 1;
	for (int i = n; i > 0; i--)
		res *= i;
	return res;
}
