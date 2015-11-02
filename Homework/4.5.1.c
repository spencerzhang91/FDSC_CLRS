/* excercise 4.5.1.c */

typedef struct Node *Linked;
struct Node {
    int data;
    Linked next;
};

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