/* excercise 4.5.3.c */
/* concatenate two circular linked lists */

typedef struct Node *Linked;
struct Node {
    int val;
    Linked next;
};

Linked concatenate(Linked list1, Linked list2)
{
	Linked head1 = list1->next;
	Linked head2 = list2->next;
	list1->next = head2;
	list2->next = head1;
	return list2;
}