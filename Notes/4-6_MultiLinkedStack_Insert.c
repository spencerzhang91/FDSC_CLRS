/* 4-6_MultiLinkedStack_Insert.c */
/* On page 94 of book FDSC */
#define MAX_STACKS 10 // maximum number of stacks
typedef struct {
	int key;
	/* other fields */
} element;


struct Node {
	element item;
	struct Node next;
};
typedef struct Node *Stack;

Stack top[MAX_STACKS];

void add(Stack *top, element item)
{
	/* add an element to the top of stack */
	Stack temp = (Stack)malloc(sizeof(struct Node));
	temp->item = item;
	temp->next = *top;
	*top = temp;
}