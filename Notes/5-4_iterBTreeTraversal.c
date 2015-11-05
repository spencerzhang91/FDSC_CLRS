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
void iter_preorder(TreeNode node);
void iter_postorder(TreeNode node);

void inorder(TreeNode node);
void preorder(TreeNode node);
void postorder(TreeNode node);

void push(int *top, TreeNode node);
TreeNode pop(int *top);

int top = -1; // initialize stack
TreeNode stack[MAXSIZE];

int main(void)
{
    /* create a tree manually, function to be developed */
    TreeNode n0 = (TreeNode)calloc(1, sizeof(struct Node));
    TreeNode n1 = (TreeNode)calloc(1, sizeof(struct Node));
    TreeNode n2 = (TreeNode)calloc(1, sizeof(struct Node));
    TreeNode n3 = (TreeNode)calloc(1, sizeof(struct Node));
    TreeNode n4 = (TreeNode)calloc(1, sizeof(struct Node));
    n0->data = 0; n1->data =1; n2->data = 2; n3->data = 3; n4->data = 4;
    n0->left = n1; n0->right = n2;
    n1->left = n3; n1->right = n4;
    n2->left = n2->right = NULL;
    n3->left = n3->right = NULL;
    n4->left = n4->right = NULL;
    
    // iter_inorder(n0);
    // iter_preorder(n0);
    iter_postorder(n0);
    
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

void iter_preorder(TreeNode node)
{
    for (;;)
    {
        for (; node; node = node->left)
        {
            printf("%d ", node->data);
            push(&top, node);
        }
        node = pop(&top); // pop from stack
        if (!node) break; // empty stack
        node = node->right;
    }

}

void iter_postorder(TreeNode node)
{
   for (;;)
    {
        for (; node; node = node->left)
            push(&top, node);
        if (!node)
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

void inorder(TreeNode ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(TreeNode ptr)
{
    if (ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preorder(TreeNode ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
