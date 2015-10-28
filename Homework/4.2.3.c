/* Excercise 4.2.3.c of FDSC on page 92 */

void delete(Linked list, int num)
{
    Linked curr;
    if ((curr = find(list, num) != NULL)
    {
        Linked pre = list;
        while (pre->next != curr)
            pre = pre->next;
        pre->next = curr->next;
        free(curr);
    }
    else
        fprintf("num is not in the list.\n");
}