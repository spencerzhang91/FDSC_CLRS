/* 4-18 concatenate two linked lists */
Linked concatenate(Linked ptr1, Linked ptr2)
{
	/* produce a new list that contains list ptr1 followed by the list ptr2.
	The list pointed to by ptr1 is changed permanently. */
	Linked temp;
	if (!ptr1)
		return ptr2;
	else
	{
		if (ptr2)
		{
			for (temp = ptr1; temp->next; temp = temp->next)
				continue;
			temp->next = ptr2;
		}
		return ptr1;
	}
}