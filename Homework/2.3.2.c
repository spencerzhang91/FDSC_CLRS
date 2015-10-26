/* Excercise 2.3.2.c polynomial multiplication */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef PolyNode *Polynomial;
struct PolyNode {
	int coef;
	int expo;
	Polynomial next;
};

void printpoly(Polynomial P);
void readpoly(void);
void mult(Polynomial P1, Polynomial P2);
void attach(int coef, int expo, Polynomial *prear);

int main(void)
{
	Polynomial P1 = readpoly(void);
	Polynomial P2 = readpoly(void);
	Polynomial PM;
	PM = mult(P1, P2);
	printpoly(PM);

	return 0;
}

void printpoly(Polynomial P)
{
	int flag = 0;
	Polynomial temp = P;
	if (!temp)
		printf("0 0\n");
	else
	{
		while (temp)
		{
			if (!flag)
				flag = 1;
			else
				printf(" ");
			printf("%d %d", temp->coef, temp->expo);
			temp = temp->next;
		}
	}
	printf("\n");
}

void readpoly(void)
{
	int coef, expo, N;
	Polynomial P, rear, t;

	scanf("%d", &N);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->next = NULL;
	rear = P;
	while (N--)
	{
		scanf("%d %d", &coef, &expo);
		attach(coef, expo, &rear);
	}
	t = P;
	P = P->next;
	free(t);
}

void mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, rear, t1, t2, t;
	int c, e;
	if (!P1 || !P2)
		return NULL;
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	rear = P;
	while (t2)
	{
		attach(t1->coef * t2->coef, t1->expo + t2->expo, &rear);
		t2 = t2->next;
	}
	t1 = t1->next;
	while (t1)
	{
		t2 = P2;
		rear = P;
		while (t2)
		{
			e = t1->expo + t2->expo;
			c = t2->coef * t2->coef;
			while (rear->next && rear->next->expo > e)
				rear = rear->next;
			if (rear->next && rear->next->expo == e)
			{
				if (rear->next->coef + c)
					rear->next->coef += c;
				else
				{
					t = rear->next;
					rear->next = t->next;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expo = e;
				t->next = rear->next;
				rear->next = t;
				rear = rear->next;
			}
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	t2 = P;
	P = P->next;
	free(t2);
	return P;
}

void attach(int coef, int expo, Polynomial *prear)
{
	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->expo = expo;
	P->next = NULL;
	(*prear)->next = P;
	*prear = P;
}