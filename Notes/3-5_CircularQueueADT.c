/* circular queue ADT */
/* code list 3-5 & 3-6 */
#include <stdio.h>
#define MAX_QUEUE_SIZE 6

typedef struct {
	int key;
	// other fields
} element;
/* global defination of queue */
element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;

void showqueueu(element *queue);
void enqueue(int front, int *rear, element item);
element dequeue(int *front, int rear);

int main(void)
{
	element n1 = {1};
	enqueue(front, &rear, n1);
	return 0;
}

void enqueue(int front, int *rear, element item)
{
	*rear = (*rear + 1) % MAX_QUEUE_SIZE;
	if (front == *rear)
		return queue_full(rear);
	queue[*rear] = item;
}

element dequeue(int *front, int rear)
{
	if (*front == rear)
		return queue_empty();
	*front = (*front + 1) % MAX_QUEUE_SIZE;
	return queue[*front];
}

void showqueueu(element *queue)
{
	
}
