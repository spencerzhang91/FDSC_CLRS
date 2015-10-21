/* C implementation of Linked List based Stack ADT */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define MAX_STACK_SIZE 100

struct Node {
	ElementType data;
	struct Node *next;
};

typedef struct {
	struct Node *head;
	int maxsize;
	int cursize;
} Snode;

typedef Snode *Stack;

Stack CreateStack(int size);
bool IsFull(Stack S);
bool IsEmpty(Stack S);
void push(Stack S, ElementType item);
ElementType pop(Stack S);
void display(Stack S);

int main(void) // test funtion
{
	Stack newlist = CreateStack(MAX_STACK_SIZE);
	display(newlist);
	push(newlist, 3);
	push(newlist, 10);
	display(newlist);
	for (int i = 0; i < 10; i++)
		push(newlist, i);
	display(newlist);
	printf("%d\n", pop(newlist));
	for (int j = 0; j < 5; j++)
		printf("%d ", pop(newlist));
	putchar('\n');
	display(newlist);
	return 0;
}

Stack CreateStack(int size)
{
	Stack newS = (Stack)calloc(size, sizeof(Snode));
	newS->head = (struct Node *)calloc(size, sizeof(struct Node));
	newS->head->next = NULL;
	newS->cursize = 0;
	newS->maxsize = size;
	return newS;
}

bool IsFull(Stack S)
{
	return S->cursize == S->maxsize;
}

bool IsEmpty(Stack S)
{
	return S->cursize == 0;
}

void push(Stack S, ElementType item)
{
	if (IsFull(S))
	{
		fprintf(stderr, "The stack is full.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = item;
		temp->next = S->head;
		S->head = temp;
		S->cursize++;
	}
}

ElementType pop(Stack S)
{
	if (IsEmpty(S))
	{
		fprintf(stderr, "The stack is empty.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = S->head->data;
		S->head = S->head->next;
		S->cursize--;
		return res;
	}
}

void display(Stack S)
{
	Stack temp = (Stack)malloc(sizeof(Stack));
	temp->head = (struct Node *)malloc(sizeof(struct Node));
	temp->head = S->head;
	while (temp->head->next != NULL)
	{
		printf("%d ", temp->head->data);
		temp->head = temp->head->next;
	}
	putchar('\n');
}
