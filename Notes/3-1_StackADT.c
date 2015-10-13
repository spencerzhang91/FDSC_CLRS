/* C implementation of Stack ADT */
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef struct {
	int key;
	// can be extended
} element;

element stack[MAXSIZE];  					// global array
int top = -1;								// global variable

void addone(int *num);
void push(int *top, element item);
void stack_full(void);
element stack_empty(void);
element pop(int *top);

int main(void)
{
	element n1 = {3};
	element n2 = {4};
	element n3 = {5};
	element n4 = {6};
	push(&top, n1);
	push(&top, n2);
	element temp;
	temp = pop(&top);
	printf("poped item value %d\n", temp.key);

    return 0;
}


void push(int *top, element item)
{
	/* push an item to the global stack */
	if (*top >= MAXSIZE)
	{
		stack_full();
		return;
	}
	stack[++*top] = item;
}

element pop(int *top)
{
	/* pop an item from the global stack */
	if (*top == -1)
		return stack_empty(); 				// returns an error key
	return stack[(*top)--];
}

void addone(int *num)
{
	(*num)++;
}

void stack_full(void)
{
	fprintf(stderr, "%s\n", "Stack is full.");
}

element stack_empty(void)
{
	fprintf(stderr, "%s\n", "Stack is empty.");
	element error_item = {1};
	return error_item;
}
