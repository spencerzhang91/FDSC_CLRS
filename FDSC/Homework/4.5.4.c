/* excercise 4.5.4.c */
/* invert a circular linked list */

typedef struct Node *Linked;
struct Node {
    int val;
    Linked next;
};

void InvertCircularList(Linked *list) // here *list point to 'head'
{
    Linked prev, curr, flag, temp;
    flag = *list;
    prev = NULL;
    curr = *list;
    temp = (*list)->next;
    if (!temp)
        return;
    
    while (temp != flag)
    {
        prev = curr;
        curr = temp;
        temp = temp->next;
        curr->next = prev;
    }
    (*list)->next = curr;
}