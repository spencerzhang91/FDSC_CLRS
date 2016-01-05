/* Linked list ADT , modulize later */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define datatype int
#define SIZE 5
typedef struct node *Linked;
struct node {
    datatype key;
    Linked next;
};
// basic operations of a linked list ADT
Linked create(datatype value);
Linked construct(datatype array[], int len);
void destruct(Linked head, int len);
void insert(Linked head, datatype item, int len, int pos);
void delitem(Linked *head, datatype item);
void display(Linked head);
int len(Linked head);
// testing main function
int main(void)
{
    Linked list1 = create(0);
    datatype array[SIZE] = {1, 3, 4, 5, 9};
    Linked list2 = construct(array, SIZE);
    //insert(list1, 30, 1, 1);
    //destruct(list1, length(list1));
    display(list2);
    delitem(list2, 5);
    display(list2);

    return 0;
}

Linked create(datatype value)
{
    Linked head = (Linked)malloc(sizeof(struct node));
    if (head)
    {
        head->next = NULL;
        head->key = value;
    }
    else
    {
        fprintf(stderr, "%s\n", "Fail to create list, full memory.");
        exit(EXIT_FAILURE);
    }
    return head;
}

Linked construct(datatype array[], int len)
{
    Linked head = create(array[0]);
    Linked curr = head;
    for (int i = 1; i < len; i++)
    {
        Linked temp = create(array[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void destruct(Linked head, int len)
{
    Linked temp = head;
    Linked curr = temp->next;
    while (curr)
    {
        free(temp);
        temp = curr;
        curr = temp->next;
    }
}

void insert(Linked head, datatype item, int len, int pos)
{
    // here pos is where new item will attach after
    if (pos > len || pos < -1)
    {
        printf("Invalide insert position.\n");
        exit(EXIT_FAILURE);
    }
    Linked temp = head;
    Linked newnode = create(item);
    int marker = -1; // -1 is to add newnode as new head
    for (; marker < pos; marker++)
        temp = temp->next;
    if (marker == -1)
    {
        newnode->next = temp;
        head = newnode;
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delitem(Linked *head, datatype item)
{
    // delete the requested item(if any)
    Linked temp = *head;
    if (temp->key == item)
    {
        (*head) = (*head)->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        while (temp->next)
        {
            if (temp->next->key == item)
                break;
            else
                temp = temp->next;
        }
        Linked drop = temp->next;
        temp->next = temp->next->next;
        drop->next = NULL;
        free(drop);
    }
}

void display(Linked head)
{
    Linked temp = head;
    while (temp)
    {
        printf("%d ", temp->key); // only if datatype == int
        temp = temp->next;
    }
    puts(""); 
}

int len(Linked head)
{
    int count = 0;
    Linked temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
