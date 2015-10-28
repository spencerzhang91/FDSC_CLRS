/* Excercise 4.2.3.c of FDSC on page 92 */

int length(Linked list)
{
    int len = 0;
    while (list)
    {
        len++;
        list = list->next;
    }
    return len;
}