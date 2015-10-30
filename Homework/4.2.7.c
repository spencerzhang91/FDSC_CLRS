/* Excercise 4.2.7.c */
Linked weave(Linked list1, Linked list2)
{
    /* weave two linked lists */
    Linked newlist = list1;
    Linked curr = newlist;
    int flag = 1;
    while (list1 && list2)
    {
        if (flag == 1)
        {
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
            flag = 0;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
            flag = 1;
        }
    }
    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;
    return newlist;
}