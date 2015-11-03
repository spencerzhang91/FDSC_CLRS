/* 4-28 doubly linked list & doubly linked circular list */
typedef struct Node *Linked;
sturct Node {
	int data;
	Linked left;
	Linked right;
};

void dinsert(Linked node, Linked newnode)
{
	/* insert new node to the right of node, and node is in a doubly linked 
	circular list */
	newnode->left = node;
	newnode->right = node->right;
	node->right->left = newnode;
	node->right = newnode;
}

void ddelete(Linked node, Linked deleted)
{
	/* delete a node from a doubly linked circular list, where node is the
	head of the list */
	if (node == deleted)
		printf("Head node is not allowed to be deleted.\n");
	else
	{
		deleted->right->left = deleted->left;
		deleted->left->right = deleted->right;
		free(deleted);
	}
}