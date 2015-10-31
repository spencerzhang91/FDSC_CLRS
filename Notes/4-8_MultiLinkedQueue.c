/* 4-8_MultiLinkedQueue_Insert */
/* 4-9_MultiLinkedQueue_Delete */
/* On page 95 of book FDSC */

#define MAX_QUEUES 10
struct Node {
	element item;
	struct Node *next;
};

typedef struct Node *Queue;

Queue front[MAX_QUEUES], rear[MAX_QUEUES];

void addq(Queue *front, Queue *rear, element item)
{
	/* add an element to the rear of the queue */
	Queue temp = (Queue)malloc(sizeof(struct Node));
	temp->item = item;
	temp->next = NULL;
	if (*front)
		(*rear)->next = temp;
	else
		*front = temp;
	*rear = temp;
}

element deleteq(Queue *front)
{
	/* delete an element from front of queue */
	Queue temp = *front;
	element item;
	item = temp->item;
	*front = temp->next;
	free(temp);
	return item;
}