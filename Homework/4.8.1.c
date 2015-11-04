/* excercise 4.8.1.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Linked;
struct Node {
    int data;
    Linked left;
    Linked right;
};

Linked CreateDCList(int len);
void dinsert(Linked node, Linked newnode);
void ddelete(Linked node, Linked deleted);
void displaycircular(Linked ptr); // borowed from 4-2

int main(void)
{
    Linked head = CreateDCList(10);
    displaycircular(head);

    return 0;
}

Linked CreateDCList(int len)
{
    /* head node is not part of the 'len' elements */
    Linked head = (Linked)malloc(sizeof(struct Node));
    Linked temp;
    Linked curr = head;
    for (int i = 0; i < len; i++)
    {
        temp = (Linked)malloc(sizeof(struct Node));
        temp->data = i;
        curr->right = temp;
        temp->left = curr;
        curr = temp;
    }
    curr->right = head;
    head->left = curr;
    return head;
}

void dinsert(Linked node, Linked newnode)
{
    /* insert new node to the right of node, and node is in a doubly linked 
    circular list */
    newnode->left = node;
    newnode->right = node->right;
    node->right->left = newnode;
    node->right = newnode;
}

void ddelete(Linked node, Linked deleted)
{
    /* delete a node from a doubly linked circular list, where node is the
    head of the list */
    if (node == deleted)
        printf("Head node is not allowed to be deleted.\n");
    else
    {
        deleted->right->left = deleted->left;
        deleted->left->right = deleted->right;
        free(deleted);
    }
}

void displaycircular(Linked list)
{
    if (!list->right)
        printf("%d /n", list->data);
    printf("%d ", list->data);
    Linked temp = list->right;
    while (temp != list)
    {
        printf("%d ", temp->data);
        temp = temp->right;
    }
        
    printf("\n");
}