/* C implementation of Stack ADT */
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef struct {
	int key;
	// can be extended
} element;

element stack[MAXSIZE];
int top = -1;
void addone(int *num);
void push(int *top, element item);
void pop(int *top, element item);

int main(void)
{
	int number = 0;
	addone(&number);
	printf("%d\n", number);

    return 0;
}


void push(int *top, element item)
{
	/* push an item to the global stack */
	if (*top >= MAXSIZE)
	{
		//stack_full();
		return;
	}
	stack[++*top] = item;
}

void pop(int *top, element item)
{
	/* pop an item from the global stack */
	if (*top == -1)
		return; //stack_empty(); // returns an error key
	return;// stack[(*top)--];
}

void addone(int *num)
{
	(*num)++;
}
