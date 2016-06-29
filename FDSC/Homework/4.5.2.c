/* excercise 4.5.2.c */
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