/* copy binary tree using (recursive) postorder traversal */
#define IS_FULL(x) ((x)==NULL)?0: 1
typedef struct treeNode *BTree;
struct treeNode {
    int data;
    BTree left;
    BTree right;
};

BTree copy(BTree origin)
{
	if (origin)
	{
		BTree temp = (BTree)malloc(sizeof(struct treeNode));
		if (IS_FULL(temp))
		{
			fprintf("The memory is full.\n");
			exit(1);
		}
		temp->left = copy(origin->left);
		temp->right = copy(origin->right);
		temp->data = origin->data;
		return temp;
	}
	return NULL;
}