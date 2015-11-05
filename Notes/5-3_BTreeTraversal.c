/* 5-1,2,3 inorder, preorder and postorder traversal of binary tree */
typedef struct Node *TreeNode;
struct Node {
    int data;
    TreeNode left;
    TreeNode right;
};

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
        inorder(ptr->left);
        inorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preorder(TreeNode ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        inorder(ptr->left);
        inorder(ptr->right);
    }
}
