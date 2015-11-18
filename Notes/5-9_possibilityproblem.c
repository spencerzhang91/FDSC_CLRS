/* 5-9 the possibility problme on page 132 of FDSC */
typedef enum {not, and, or, true, false} logical;
typedef struct treeNode *BiTree;
struct treeNode {
    int value;
    logical data;
    BiTree left;
    BiTree right;
};

void postorder_eval(BiTree node)
{
	/* post order traversal to evaluate a propositional calculus tree. */
	if (node)
	{
		postorder_eval(node->left);
		postorder_eval(node->right);
		switch (node->data)
		{
			case not: node->value = !node->right->value;
			break;
			case and: node->value = node->left->value && node->right->value;
			break;
			case or: node->value = node->left->value || node->right->value;
			break;
			case true: node->value = 1;
			break;
			case false: node->value = 0;
			break;
			default: printf("Something fucking goes wrong!\n");
		}

	}
}