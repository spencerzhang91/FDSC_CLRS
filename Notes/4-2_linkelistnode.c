/* C Implementation of Linked List ADT */
/* code list 4.2 on page 90 to 93 */
/* Functions of Excercise 4.2 is added */
/* Test module for all excerciese associate with linked list... */
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
void InsertA(Linked *ptr, Linked node);
Linked InsertB(Linked ptr, Linked node);
void display(Linked ptr);
void delete(Linked *ptr, Linked trail);
Linked find(Linked list, int num);
void deletenum(Linked *list, int num);
int length(Linked list);
Linked MergeLists(Linked list1, Linked list2);
Linked weave(Linked list1, Linked list2);
Linked weave2(Linked list1, Linked list2);

int main(void)
{
    Linked TwoNode = create2();
    display(TwoNode);   
    InsertA(&TwoNode, TwoNode);
    display(TwoNode);  
    Linked newtwo;
    newtwo = InsertB(TwoNode, TwoNode);
    display(newtwo);
    int len = length(newtwo);
    printf("length of newtwo is %d\n", len);
    delete(&newtwo, newtwo->next);
    display(newtwo);
    if (find(newtwo, 1))
        printf("Found.\n");
    printf("Delete num test below:\n");
    deletenum(&newtwo, 1);
    display(newtwo);
    deletenum(&newtwo, 2);
    display(newtwo);
    deletenum(&newtwo, 10);
    display(newtwo);
    deletenum(&newtwo, 10);
    display(newtwo);
    printf("New test below:\n");
    Linked newlist = CreateList(10);
    display(newlist);
    printf("Merge test below:\n");
    Linked listone = CreateList(5);
    Linked listtwo = CreateList(5);
    display(listone);
    display(listtwo);
    Linked result = MergeLists(listone, listtwo);
    display(result);
    printf("Weave test below:\n");
    Linked list1 = CreateList(8);
    Linked list2 = CreateList(5);
    display(list1); display(list2);
    Linked wtf = weave2(list1, list2);
    display(wtf);
    
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
        len--;
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
