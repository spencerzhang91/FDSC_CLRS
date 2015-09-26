/* 1.2.8.c */
/* recursive and iterative way to calculate nth fibonacci number */
#include <stdio.h>
#define MAX 100

int fibonacci_I(int n);
int fibonacci_R(int n);

int main(void)
{
	int num;
	int flag = 1;
	while (flag)
	{
		printf("Please enter nth number of fibonacci sequence: ");
		scanf("%d", &num);
		if (num >= 0)
			flag = 0;
		else
			printf("The number should greater or equal to 0!");
	}
	
	printf("Iterative: %d\n", fibonacci_I(num));
	printf("Recursive: %d\n", fibonacci_R(num));
	
	return 0;
}

int fibonacci_I(int n)
{
	int list[MAX] = {0,1};
	for (int i = 2; i <= n; i++)
		list[i] = list[i-1] + list[i-2];
	
	return list[n];		
}

int fibonacci_R(int n)
{
	if (n <= 1)
		return n;
	else
		return fibonacci_R(n - 1) + fibonacci_R(n - 2);
}
