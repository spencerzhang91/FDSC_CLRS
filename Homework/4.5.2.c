/* excercise 4.5.2.c */
void deletenum(Linked *list, int num)
{
    // to be done.
    Linked curr = list->next;
    Linked prev = list;
    while (curr != list)
    {
        if (curr->data == num)
        {
            Linked temp = curr;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }

}