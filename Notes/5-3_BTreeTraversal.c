/* 5-1,2,3 inorder, preorder and postorder traversal of binary tree */
typedef struct Node *TreeNode;
struct Node {
    int val;
    TreeNode left;
    TreeNode right;
};

void inorder(TreeNode ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->val);
        inorder(ptr->right);
    }
}

void postorder(TreeNode ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        inorder(ptr->right);
        printf("%d ", ptr->val);
    }
}

void preorder(TreeNode ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->val);
        inorder(ptr->left);
        inorder(ptr->right);
    }
}