/* excercise 4.5.4.c */
/* invert a circular linked list */

typedef struct Node *Linked;
struct Node {
    int val;
    Linked next;
};

void invert(linked list)
{
	Linked prev, curr;
	curr = NULL;
	while (list)
	{
		prev = curr;
		curr = list;
		list = list->next;
		curr->next = prev;
	}
	return curr;
}

void InvertCircularList(Linked list)
{
	Linked prev, curr, flag;
	flag = list;
	prev = list;
	curr = list;
	list = list->next;
	while (list != flag)
	{
		prev = curr;
		curr = list;
		list = list->next;
		curr->next = prev;
	}
	flag-next = list;
}

// not testified yet