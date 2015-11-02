/* 4-19 insert a node in front of a circular linked list */

void insert_front(Linked *ptr, Linked node)
{
	/* insert node in front of list ptr, where ptr is the last node 
	of the circular list */
	if (!(*ptr))
	{
		/* list is empty, change point to new node */
		*ptr = node;
		node->next = node;
	}
	else
	{
		/* list is not empty, add new entry at front */
		node->next = (*ptr)->next;
		(*ptr)->next = node;
	}
}