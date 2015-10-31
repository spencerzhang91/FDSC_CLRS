/* 4-7_MultiLinkedStack_Delete.c */
/* On page 94 of book FDSC */

element delete(Stack *top)
{
	Stack temp = *top;
	element item;
	item = (*temp)->item;
	*top = (*temp)->next;
	free(temp);
	return item;
}