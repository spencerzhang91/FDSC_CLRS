/* 4-6_MultiLinkedStack_Insert */
/* 4-7_MultiLinkedStack_Delete */
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

element delete(Stack *top)
{
    Stack temp = *top;
    element item;
    item = (*temp)->item;
    *top = (*temp)->next;
    free(temp);
    return item;
}