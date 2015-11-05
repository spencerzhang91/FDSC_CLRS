/* 5-4 iterative implementation of traversal of binary tree */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Node *TreeNode;
struct Node {
    int data;
    TreeNode left;
    TreeNode right;
};
void iter_inorder(TreeNode node);
void push(int *top, TreeNode node);
TreeNode pop(int *top);

int top = -1; // initialize stack
TreeNode stack[MAXSIZE];

int main(void)
{
	TreeNode n0 = (TreeNode)calloc(1, sizeof(struct Node));
	TreeNode n1 = (TreeNode)calloc(1, sizeof(struct Node));
	TreeNode n2 = (TreeNode)calloc(1, sizeof(struct Node));
	TreeNode n3 = (TreeNode)calloc(1, sizeof(struct Node));
	n0->left = n1; n0->data = 0;
	n0->right = n2; n1->data = 1; n2->data = 2; n3->data = 3;
	n1->left = n3;
	iter_inorder(n0);
	
	return 0;
}



void iter_inorder(TreeNode node)
{
	for (;;)
	{
	    for (; node; node = node->left)
			push(&top, node); // push to stack
		node = pop(&top); // pop from stack
		if (!node) break; // empty stack
		printf("%d ", node->data);
		node = node->right;
    }	
}

void push(int *top, TreeNode node)
{
	if (*top >= MAXSIZE - 1)
		return;
	stack[++*top] = node;
}

TreeNode pop(int *top)
{
	if (*top == -1)
		return NULL;
	return stack[(*top)--];
}
