/* Excercise 4.2.6 */
Linked MergeLists(Linked list1, Linked list2)
{
    /* create a new list while remainning original ones */
    Linke result = (Linked)malloc(sizeof(struct Node));
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            append(result, list1->data);
            list1 = list1->next;
        }
        else
        {
            append(result, list2->data);
            list2 = list2->next;
        }
    }
    while (list1)
    {
        append(result, list1->data);
        list1 = list1->next;
    }
    while (list2)
    {
        append(result, list2->data);
        list2 = list2->next;
    }
    return result;
}

void MergeList(Linked list1, Linked list2)
{
	/* original lists gone, merged into new one */
	
}