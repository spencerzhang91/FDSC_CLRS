/* C implementation of Array based Stack ADT */
/* A more modern and reusable implementation */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define MAX_STACK_SIZE 100

typedef struct {
    ElementType *array;
    int top;
    int maxsize;
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
        push(newlist, i * i);
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
    Stack newS = (Stack)malloc(sizeof(Stack));
    newS->array = (ElementType *)calloc(size, sizeof(ElementType));
    newS->top = -1;
    newS->maxsize = size;
    return newS;
}

bool IsFull(Stack S)
{
    return S->top - 1 == S->maxsize;
}

bool IsEmpty(Stack S)
{
    return S->top == -1;
}

void push(Stack S, ElementType item)
{
    if (IsFull(S))
    {
        fprintf(stderr, "The stack is full.\n");
        exit(EXIT_FAILURE);
    }
    else
        S->array[++(S->top)] = item;
}

ElementType pop(Stack S)
{
    if (IsEmpty(S))
    {
        fprintf(stderr, "The stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    else
        return S->array[(S->top)--];
}

void display(Stack S)
{
    for (int i = 0; i < S->top + 1; i++)
        printf("%d ", S->array[i]);
    putchar('\n');
}