/* 4-20 calculate length of circular linked list */
int length(Linked ptr)
{
	/* find the length of the circular list ptr */
	Linked temp;
	int count = 0;
	if (ptr)
	{
		temp = ptr;
		do {
			count++;
			temp = temp->next;
		} while (temp != ptr);
	}
	return count;
}