/* Excercise 4.2.7.c */
Linked weave(Linked list1, Linked list2)
{
    /* weave two linked lists */
    Linked newlist = (Linked)malloc(sizeof(struct Node));
    newlist->next = list1;
    Linked curr = list1;
    while (list1 && list2)
    {
        list1 = list1->next;
        curr->next = list2;
        list2 = list2->next;
        curr->next = list1;
        curr = curr->next;
    }
    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;
    return newlist;
}