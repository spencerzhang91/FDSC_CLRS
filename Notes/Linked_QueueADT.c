/* Linked list based Queue ADT implementation */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define MAXSIZE 10

struct Node{
	ElementType data;
	struct Node *next;
};

typedef struct {
	struct Node *front;
    struct Node *rear;
	int cursize;
	int maxsize;
} Qnode;

typedef Qnode *Queue;

Queue CreateQueue(int maxsize);
bool IsFull(Queue Q);
bool IsEmpty(Queue Q);
void enqueue(Queue Q, ElementType item);
ElementType dequeue(Queue Q);

int main(void) 									// test fucntion
{
	Queue NewQ = CreateQueue(MAXSIZE);
	if (IsFull(NewQ))
		printf("The queue is full.\n");
	if (IsEmpty(NewQ))
		printf("The queue is empty.\n");
	return 0;
}

Queue CreateQueue(int maxsize)
{
	Queue temp = (Queue)malloc(sizeof(Qnode));
	temp->front = temp->rear = NULL;
	temp->maxsize = maxsize;
	return temp;
}

bool IsFull(Queue Q)
{
	return Q->cursize == Q->maxsize;
}

bool IsEmpty(Queue Q)
{
	return Q->front == NULL;
}

void enqueue(Queue Q, ElementType item)
{
	struct Node *rearcell;
	ElementType rearelem = item;
	if (IsFull(Q))
		printf("The queue is full.\n");
	else
	{
		rearcell = (struct Node *)malloc(sizeof(struct Node));
		rearcell->data = rearelem;
		if (Q->cursize == 0)
			Q->front = Q->rear = rearcell;
		else
		{
			Q->rear->next = rearcell;
			Q->rear = Q->rear->next;
		}	
		++Q->cursize;
	}
}

ElementType dequeue(Queue Q)
{
	struct Node *frontcell;
	ElementType frontelem;
	if (IsEmpty(Q))
	{
		printf("The queue is empty.\n");
		ElementType error = -1;
		return error; 
	}
	else
	{
		frontcell = Q->front;
		frontelem = frontcell->data;
		if (Q->front == Q->rear)
			Q->front = Q->rear = NULL;
		else
			Q->front = Q->front->next;
		free(frontcell);
		--Q->cursize;
		return frontelem;
	}
}
