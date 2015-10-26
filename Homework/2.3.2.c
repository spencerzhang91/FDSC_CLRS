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

}

void readpoly(void)
{

}

void mult(Polynomial P1, Polynomial P2)
{

}