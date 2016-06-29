/* Excercise 1.3.3.c Implementation of Bag ADT */
#include <stdio.h>
#define ElementType int
#define MAXNUM 100;

struct bag {
	ElementType *items;
	int currentnum;
	int volume;
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
	B->volume = len;
	return B;
}

void Insert(Bag B, ElementType item)
{
	if (B->currentnum < B->volume)
    {
        B->items[B->currentnum] = item;
        B->currentnum++;
    }
    else
        printf("The set is full.\n");
}

void Remove(Bag B, ElementType item)
{
	for (int i = 0; i < D->currentnum; i++)
    {
        if (D[i] == item)
        {
            for (int j = i; j < D->currentnum -1; j++)
                D[j] = D[j+1];
            D[j] = NULL;
        }
    }
    printf("The element is not in the set.\n");
}

bool Is_In(Bag B, ElementType item)
{
	or (int i = 0; i < B->currentnum; i++)
        if (B->items[i] == item)
            return true;
    return false;
}