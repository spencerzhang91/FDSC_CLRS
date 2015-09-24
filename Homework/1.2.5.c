/* 1.2.4.c */
/* Pigeon hole principle */
#include <stdio.h>
#define MAX 10

void pigeon(int *list, int len, int (* fp)(int num));
int square(int root);

int main(void)
{
	int args[MAX] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7};
	pigeon(args, MAX, square);
	
	return 0;
}

void pigeon(int *list, int len, int (* fp)(int num))
{
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = i + 1; j < len; j++)
		{
			if ((*fp)(list[i]) == (*fp)(list[j]))
				printf("a = %d, b = %d\n", list[i], list[j]);
			else
				continue;
		}
}

int square(int root)
{
	return root * root;
}
