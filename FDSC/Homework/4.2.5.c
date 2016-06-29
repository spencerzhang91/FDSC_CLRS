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
void display(Linked ptr);

int main(void)
{
	Linked List = CreateList(10);
    display(List);
    SkipDelete(&List);
    display(List);

    return 0;

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
	if (*list)
    {
        Linked temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    Linked ptr = *list;
    while (ptr && ptr->next)
    {
        Linked temp = ptr->next;
        ptr->next = temp->next;
        ptr = ptr->next;
        free(temp);
    }
}

void display(Linked list)
{
    Linked temp = list;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
        
    printf("\n");
}
