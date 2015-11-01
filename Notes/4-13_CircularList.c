/* 4-13, 4-14, 4-15 */
/* On page 100 - 102 of book FDSC */

Linked get_node(void)
{
	/* provide a node from the available list */
	Linked node;
	if (avail)
	{
		node = avail;
		avail = avail->next;
	}
	else
		node = (Linked)malloc(sizeof(struct Node));
	return node;
}

void ret_node(Linked ptr)
{
	/* return a node to the available list */

}