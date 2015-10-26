/* Excercise 1.3.3.c Implementation of Bag ADT */
#include <stdio.h>
#define ElementType int
#define MAXNUM 100;

struct bag {
	ElementType *items;
	int currentnum;
	int totoalnum;
};
typedef struct bag *Bag;

Bag Create(int len);
void Insert(Bag B, ElementType item);
void Remove(Bag B, ElementType item);
bool Is_In(Bag B, ElementType item);

int main(void)
{
	return 0;
}

Bag Create(int len)
{
	Bag B = (Bag)malloc(sizeof(struct bag));
	B->items = (ElementType *)malloc(len*sizeof(ElementType));
	B->currentnum = 0;
	B->totoalnum = len;
	return B;
}

void Insert(Bag B, ElementType item)
{

}

void Remove(Bag B, ElementType item)
{

}

bool Is_In(Bag B, ElementType item)
{

}