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
bool insert(Linked head, datatype item, int len, int pos);
bool delete(Linked head, datatype item);
void display(Linked head);
int length(Linked head);
// testing main function
int main(void)
{
    Linked list1 = create(0);
    datatype array[SIZE] = {1, 3, 4, 5, 9};
    Linked list2 = construct(array, SIZE);
    insert(list1, 30, 1, 1);
    destruct(list1, length(list1));
    display(list2);
    delete(list2, 5);

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

bool insert(Linked head, datatype item, int len, int pos)
{

}

bool delete(Linked head, datatype item)
{

}

void display(Linked head)
{

}

int length(Linked head)
{

}
