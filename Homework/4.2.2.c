/* Excercise 4.2.2.c of FDSC on page 92 */
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
