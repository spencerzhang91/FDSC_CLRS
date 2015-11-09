/* Circular array based Queue ADT implementation */
/* A more modern and reusable implementation */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define MAXSIZE 10

typedef struct {						// defination of queue
	ElementType *data;
	int front;
	int rear;
	int maxsize;
} QNode;

typedef QNode *Queue;                  // pointer to entire queue

Queue CreateQueue(int maxsize);
bool IsFull(Queue Q);
bool IsEmpty(Queue Q);
void enqueue(Queue Q, ElementType item);
ElementType dequeue(Queue Q);

int main(void)
{
	Queue newqueue;
	newqueue = CreateQueue(MAXSIZE);
	ElementType item1 = 10;
	ElementType item2 = 20;
	ElementType item3 = 30;
	if (IsFull(newqueue))
		printf("The queue is full.\n");
	if (IsEmpty(newqueue))
		printf("The queue is empty.\n");
	enqueue(newqueue, item1);
	enqueue(newqueue, item2);
	printf("dequeued item: %d\n", dequeue(newqueue));

	return 0;
}

Queue CreateQueue(int maxsize)
{
	Queue temp = (Queue)malloc(sizeof(QNode));
	temp->data = (ElementType *)malloc(maxsize*sizeof(ElementType));
	temp->front = temp->rear = 0;
	temp->maxsize = maxsize;
	return temp;
}

bool IsFull(Queue Q)
{
	return ((Q->rear + 1) % Q->maxsize == Q->front);
}

bool IsEmpty(Queue Q)
{
	return Q->rear == Q->front;
}

void enqueue(Queue Q, ElementType item)
{
	if (IsFull(Q))
		printf("The queue is full.\n");
	else
	{
		Q->rear = (Q->rear + 1) % Q->maxsize;
		Q->data[Q->rear] = item;
		printf("New item added to queue.\n");
	}
}

ElementType dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		printf("The queue is empty.\n");
		ElementType error = -1;
		return error;
	}
	else
	{
		Q->front = (Q->front + 1) % Q->maxsize;
		return Q->data[Q->front];
	}	
}