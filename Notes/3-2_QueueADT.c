/* code list 3-2 queue ADT */
#include <stdio.h>
#define MAXSIZE 100

typedef struct {
	int key;
	// other fields
} element;

element queue[MAXSIZE];							// global array
int rear = -1;
int front = -1;

void enqueue(int *rear, element item);			// enqueue
element dequeue(int *front, int rear);			// dequeue
void showqueue(void);

int main(void)
{
	element n1 = {3};
	enqueue(&rear, n1);
	printf("%d", queue[0].key);
	return 0;
}

void enqueue(int *rear, element item)
{
	if (*rear == MAXSIZE - 1)
		fprintf(stderr, "Queue is full.\n");
	else
		queue[++*rear] = item;
}

element dequeue(int *front, int rear)
{
	if (*front == rear)
	{
		printf("Queue is empty.\n");
		element wrong = {-1};
		return wrong;
	}
	return queue[++*front];
}