/* excercise 4.5.4.c */
/* invert a circular linked list */

typedef struct Node *Linked;
struct Node {
    int val;
    Linked next;
};

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