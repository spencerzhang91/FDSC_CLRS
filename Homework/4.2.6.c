/* Excercise 4.2.6 */
Linked MergeLists(Linked list1, Linked list2)
{
    /* create a new list while remainning original ones */
    Linke head = (Linked)malloc(sizeof(struct Node));
    head->data = NULL; head->next = NULL;
    Linked ptr = head;
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            ptr->next = list1;
            list1 = list1->next;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
            ptr = ptr->next;
        }
    }
    if (list1)
        ptr->next = list1;
    if (list2)
        ptr->next = list2;

    return head;
}
