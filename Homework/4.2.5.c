/* Excercise 4.2.5.c */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Linked;

Linked CreateList(int len);
void SkipDelete(Linked *list);

int main(void)
{
	Linked List = CreateList(10)
}    

Linked CreateList(int len)
{
    /* create a linked list with len nodes */
    if (len <= 0)
        printf("Invalid list length!\n");
    else
    {
        Linked ptrl = (Linked)malloc(sizeof(struct Node));
        ptrl->data = len; ptrl->next = NULL;
        Linked temp = ptrl;
        len--;
        while (len > 0)
        {
            Linked curr = (Linked)malloc(sizeof(struct Node));
            curr->data = len; curr->next = NULL;
            temp->next = curr;
            temp = temp->next;
            len--;
        }
        return ptrl;
    }
}


void SkipDelete(Linked *list)
{
	int listlen = length(list);
	// to be done before Thursday
}