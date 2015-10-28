/* Excercise 4.2.1.c of char 4 on page 92 */
void delete(Linked *ptr, Linked trail)
{
	if (trail)
	{
		Linked temp = trail->next;
		trail->next = temp->next;
	}
	else
		(*ptr) = (*ptr)->next;
	free(temp);
}
