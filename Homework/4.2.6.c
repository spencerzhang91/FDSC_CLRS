/* Excercise 4.2.6 */
Linked MergeLists(Linked list1, Linked list2)
{
    Linke result = (Linked)malloc(sizeof(struct Node));
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            Insert(result, list1->data);
            list1 = list1->next;
        }
        else
        {
            Insert(result, list2->data);
            list2 = list2->next;
        }
    }
    while (list1)
    {
        Insert(result, list1->data);
        list1 = list1->next;
    }
    while (list2)
    {
        Insert(result, list2->data);
        list2 = list2->next;
    }
    return result;
}
