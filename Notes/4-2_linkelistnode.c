/* C Implementation of Linked List ADT */
/* code list 4.2 on page 90 to 93 */
/* Functions of Excercise 4.2 and 4.5 is added */
/* Test module for all excerciese associate with linked list */
#include <stdio.h>
#include <stdlib.h>
#define VAL 10;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Linked;

Linked create2(void);
Linked CreateList(int len);
Linked CreateCList(int len); // create circular list

void InsertA(Linked *ptr, Linked node);
Linked InsertB(Linked ptr, Linked node);
void display(Linked ptr);
void displaycircular(Linked ptr); // display circular list (ptr is head node)

void delete(Linked *ptr, Linked trail);
Linked find(Linked list, int num);
void deletenum(Linked *list, int num);
int length(Linked list);
Linked MergeLists(Linked list1, Linked list2);
Linked weave(Linked list1, Linked list2);
Linked weave2(Linked list1, Linked list2);

Linked searchnum(Linked list, int num);
void cdeletenum(Linked *list, int num);
void InvertCircularList(Linked *list);
Linked concatenate(Linked list1, Linked list2); /* this two circular list's
                                                 pointer point to last node */

int main(void)
{
    Linked list = CreateCList(10);
    displaycircular(list);
    Linked list2 = CreateList(10);
    display(list2);
    Linked list3 = CreateCList(4);
    Linked newlist = concatenate(list, list3);
    displaycircular(newlist);
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

void displaycircular(Linked list)
{
    if (!list->next)
        printf("%d /n", list->data);
    printf("%d ", list->data);
    Linked temp = list->next;
    while (temp != list)
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


int length(Linked list)
{
    int len = 0;
    while (list)
    {
        len++;
        list = list->next;
    }
    return len;
}

Linked CreateList(int len)
{
    /* create a linked list with len nodes */
    if (len <= 0)
        printf("Invalid list length!\n");
    else
    {
        int i = 0;
        Linked ptrl = (Linked)malloc(sizeof(struct Node));
        ptrl->data = i; ptrl->next = NULL;
        Linked temp = ptrl;
        len--; i++;
        while (len > 0)
        {
            Linked curr = (Linked)malloc(sizeof(struct Node));
            curr->data = i++; curr->next = NULL;
            temp->next = curr;
            temp = temp->next;
            len--;
        }
        return ptrl;
    }
}

Linked CreateCList(int len)
{
    /* create a linked list with len nodes */
    if (len <= 0)
        printf("Invalid list length!\n");
    else
    {
        int i = 0;
        Linked ptrl = (Linked)malloc(sizeof(struct Node));
        ptrl->data = i; ptrl->next = NULL;
        Linked temp = ptrl;
        len--; i++;
        while (len > 0)
        {
            Linked curr = (Linked)malloc(sizeof(struct Node));
            curr->data = i++; curr->next = NULL;
            temp->next = curr;
            temp = temp->next;
            len--;
        }
        temp->next = ptrl;
        return ptrl;
    }
}

Linked MergeLists(Linked list1, Linked list2)
{
    /* create a new list while remainning original ones */
    Linked head = (Linked)malloc(sizeof(struct Node));
    head->data; head->next = NULL;
    Linked ptr = head;
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            ptr->next = list1;
            list1 = list1->next;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
            ptr = ptr->next;
        }
    }
    if (list1)
        ptr->next = list1;
    if (list2)
        ptr->next = list2;

    return head;
}

Linked weave(Linked list1, Linked list2)
{
    /* weave two linked lists */
    Linked newlist = (Linked)malloc(sizeof(struct Node));
    newlist->data; newlist->next = NULL;
    Linked curr = newlist;
    int flag = 1;
    while (list1 && list2)
    {
        if (flag == 1)
        {
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
            flag = 0;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
            flag = 1;
        }
    }
    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;
    newlist = newlist->next;
    return newlist;
}

Linked weave2(Linked list1, Linked list2)
{
    /* weave two linked lists (without using flag) */
    Linked newlist = (Linked)malloc(sizeof(struct Node));
    newlist->data; newlist->next = NULL;
    Linked curr = newlist;
    while (list1 && list2)
    {
        curr->next = list1;
        list1 = list1->next;
        curr = curr->next;
        curr->next = list2;
        list2 = list2->next;
        curr = curr->next;
    }
    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;
    newlist = newlist->next;
    return newlist;
}

Linked searchnum(Linked list, int num)
{
    Linked temp = list->next;
    while (temp != list)
    {
        if (temp->data == num)
            return temp;
        else
            temp = temp->next;
    }
    return NULL;
}

void cdeletenum(Linked *list, int num)
{
    Linked curr = (*list)->next;
    Linked prev = *list;
    if (prev->data == num)
    {
        Linked temp = prev;
        while (temp->next != prev)
            temp = temp->next;
        temp->next = prev->next;
        *list = (*list)->next;
        free(prev);
        return;
    }
    while (curr != *list)
    {
        if (curr->data == num)
        {
            Linked temp = curr;
            prev->next = temp->next;
            temp->next = NULL;
            free(temp);
            return;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }
}

void InvertCircularList(Linked *list)
{
    Linked prev, curr, flag;
    flag = *list;
    prev = *list;
    curr = *list;
    *list = (*list)->next;
    while (*list != flag)
    {
        prev = curr;
        curr = *list;
        *list = (*list)->next;
        curr->next = prev;
    }
    flag->next = *list;
}

Linked concatenate(Linked list1, Linked list2)
{
    Linked head1 = list1->next;
    Linked head2 = list2->next;
    list1->next = head2;
    list2->next = head1;
    return list2;
}
