/* circular queue ADT */
/* code list 3-5 & 3-6 */
#include <stdio.h>
#define MAX_QUEUE_SIZE 6

typedef struct {
	int key;
	// other fields
} element;
/* global defination of queue */
element queue[MAX_QUEUE_SIZE] = {0,0,0,0,0,0};
int rear = 0;
int front = 0;

void showqueue(element *queue);
void enqueue(int front, int *rear, element item);
element dequeue(int *front, int rear);

int main(void)
{
	element n1 = {1};
	element n2 = {2};
	element n3 = {3};
	element n4 = {4};
	element n5 = {5};
	enqueue(front, &rear, n1);
	enqueue(front, &rear, n2);
	enqueue(front, &rear, n3);
	enqueue(front, &rear, n4);
	enqueue(front, &rear, n5);
	showqueue(queue);
	return 0;
}

void enqueue(int front, int *rear, element item)
{
	*rear = (*rear + 1) % MAX_QUEUE_SIZE;
	if (front == *rear)
		printf("Queue is full.\n");
	queue[*rear] = item;
}

element dequeue(int *front, int rear)
{
	if (*front == rear)
		printf("Queue is empty.\n");
	*front = (*front + 1) % MAX_QUEUE_SIZE;
	return queue[*front];
}

void showqueue(element *queue)
{
	if (rear < front)
	   rear = rear + MAX_QUEUE_SIZE;
	printf("front: %d, rear: %d\n", front, rear);
	for (int i = front; i <= rear; i++)
	   printf("%d ", queue[i]);
}
