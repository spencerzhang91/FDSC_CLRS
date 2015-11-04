/* 5-4 iterative implementation of traversal of binary tree */
#define MAXSIZE 100

typedef struct Node *TreeNode;
struct Node {
    int val;
    TreeNode left;
    TreeNode right;
};

void iter_inorder(TreeNode node)
{
	int top = -1; // initialize stack
	TreeNode stack[MAXSIZE];
	for (;;)
		for (; node; node = node->left)
			add(&top, node); // add to stack
		node = delete(&top); // delete from stack
		if (!node) break; // empty stack
		printf("%d ", node->val);
		node = node->right;
}