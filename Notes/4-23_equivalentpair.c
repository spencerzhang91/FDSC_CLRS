/* 4-23 find equivalent class from equivalent pairs */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 24
#define ISFULL(ptr) (!(ptr))

typedef struct Node *Linked;
struct Node {
	int data;
	Linked next;
};

int main(void)
{
	int out[MAXSIZE];
	Linked seq[MAXSIZE];
	Linked x, y, top;
	int i, j, n;
	printf("Enter the size (<= %d): \n", MAXSIZE);
	scanf("%d", &n);
	/* initialize out and seq */
	for (i = 0; i < n; i++)
	{
		out[i] = true;
		seq[i] = NULL;
	}
	/* phase 1: input the equivalence pairs */
	printf("Enter a pair of numbers (-1 -1 to quit): \n");
	scanf("%d %d", &i, &j);
	while (i >= 0)
	{
		x = (Linked)malloc(sizeof(struct Node));
		if (ISFULL(x))
		{
			fprintf(stderr, "The memory is full.\n");
			exit(1);
		}
		x->data = j; x->next = seq[i]; seq[i] = x;
		x = (Linked)malloc(sizeof(struct Node));
		if (ISFULL(x))
		{
			fprintf(stderr, "The memory is full.\n");
			exit(1);
		}
		x->data = i; x->next = seq[j]; seq[j] = x;
		printf("Enter a pair of numbers (-1 -1 to quit): \n");
		scanf("%d %d", &i, &j);	
	}
	
	/* phase 2: output the equivalence classes */
	for (i = 0; i < n; i++)
		if (out[i])
		{
			printf("New class: %5d", i);
			out[i] = false;
			x = seq[i];
			top = NULL;
			for (;;)
			{
				while (x)
				{
					j = x->data;
					if (out[j])
					{
						printf("%5d", j);
						out[j] = false;
						/* next three lines are reversing link field */
						y = x->next;
						x->next = top;
						top = x; x = y;
					}
					else
						x = x->next;
				}
				if (!top) break;
				x = seq[top->data];
				top = top->next;
			}
		}
}
