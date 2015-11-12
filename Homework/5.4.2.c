/* excercise 5.4.2.c */
typedef struct treeNode *BTree;
struct treeNode {
    int data;
    BTree left;
    BTree right;
};

void swaptree(BTree root)
{
	if (!root)
		return;
	BTree temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	swaptree(root->left);
	swaptree(root->right);
}