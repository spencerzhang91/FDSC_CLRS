/* Excercise 4.2.1.c of char 4 on page 92 */
void delete(Linked *ptr, Linked trail)
{
    Linked temp = (Linked)malloc(sizeof(struct Node));
    if (trail)
    {
        temp = trail->next;
        trail->next = temp->next;
    }
    else
        (*ptr) = (*ptr)->next;
    free(temp);
}
