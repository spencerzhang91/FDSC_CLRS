/* lever order traversal of binary tree */
#define MAXSIZE 100

typedef struct Node *TreeNode;
struct Node {
    int data;
    TreeNode left;
    TreeNode right;
};

void level_order(TreeNode ptr)
{
	int front = rear = 0;
	TreeNode queue[MAXSIZE];
	if (!ptr)
		return;
	enqueue(front, &rear, ptr);
	for (;;)
	{
		ptr = dequeue(&front, rear);
		if (ptr)
		{
			printf("%d ", ptr->data);
			if (ptr->left)
				enqueue(front, &rear, ptr->left);
			if (ptr->right)
				enqueue(front, &rear, ptr->right);
		}
		else
			break;
	}
}