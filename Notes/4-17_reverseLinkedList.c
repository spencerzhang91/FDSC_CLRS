/* 4-17 invert linked list */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Linked;
struct Node {
    int val;
    Linked next;
};

void invert(Linked list);

int main(void)
{
    Linked temp = (Linked)malloc(sizeof(struct Node));
    temp->val = 3;
    temp->next = NULL;
    
    printf("%d\n", temp->val);
    return 0;
}

void invert(linked list)
{
    Linked prev, curr;
    curr = NULL;
    while (list)
    {
        prev = curr;
        curr = list;
        list = list->next;
        curr->next = prev;
    }
    return curr;
}