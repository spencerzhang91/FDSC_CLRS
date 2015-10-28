/* C Implementation of Linked List ADT */
/* code list 4.2 on page 90 to 93 */
#include <stdio.h>
#include <stdlib.h>
#define VAL 10;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Linked;
Linked create2(void);
void InsertA(Linked *ptr, Linked node);
Linked InsertB(Linked ptr, Linked node);
void display(Linked ptr);
void delete(Linked *ptr, Linked trail);
Linked find(Linked list, int num);
void deletenum(Linked *list, int num);

int main(void)
{
    Linked TwoNode = create2();
    display(TwoNode);
    
    InsertA(&TwoNode, TwoNode);
    display(TwoNode);
    
    Linked newtwo;
    newtwo = InsertB(TwoNode, TwoNode);
    display(newtwo);

    delete(&newtwo, newtwo->next);
    display(newtwo);

    if (find(newtwo, 1))
        printf("Found.\n");

    deletenum(&newtwo, 1);
    display(newtwo);
    
    deletenum(&newtwo, 2);
    display(newtwo);
    
    deletenum(&newtwo, 10);
    display(newtwo);
    
    deletenum(&newtwo, 10);
    display(newtwo);

    return 0;    
}

Linked create2(void)
{
    /* create linked list with two nodes */
    Linked head = (Linked)malloc(sizeof(struct Node));
    Linked tail = (Linked)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = tail;
    tail->data = 2;
    tail->next = NULL;
    return head;
}

void InsertA(Linked *ptr, Linked node)
{
    /* insert after node if list is not empty */
    Linked temp = (Linked)malloc(sizeof(struct Node));
    temp->data = VAL;
    if (*ptr)
    {
        temp->next = node->next;
        node->next = temp;
    }
    else
    {
        temp->next = NULL;
        *ptr = temp;
    }
}

Linked InsertB(Linked ptr, Linked node)
{
    Linked temp = (Linked)malloc(sizeof(struct Node));
    temp->data = VAL;
    if (ptr)
    {
        temp->next = node->next;
        node->next = temp;
    }
    else
    {
        temp->next = NULL;
        ptr = temp;
    }
    return ptr;
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

void delete(Linked *ptr, Linked trail)
{
    Linked temp = (Linked)malloc(sizeof(struct Node));
    if (trail)
    {
        temp = trail->next;
        trail->next = temp->next;
    }
    else
        (*ptr) = (*ptr)->next;
    free(temp);
}

Linked find(Linked list, int num)
{
    while (list)
    {
        if (list->data == num)
            return list;
        else
            list = list->next;
    }
    return NULL;
}

void deletenum(Linked *list, int num)
{
    Linked curr = find(*list, num);
    if (curr)
    {
        if (curr == *list)
        {
            Linked temp = *list;
            *list = (*list)->next;
            free(temp);            
        }
        else
        {
            Linked prev = *list;
            while (prev->next != curr)
                prev = prev->next;
            prev->next = curr->next;
            curr->next = NULL;
            free(curr);
        }
    }
    printf("Not in list or list is empty.\n");
}
