/* 5-1,2,3 inorder, preorder and postorder traversal of binary tree */
typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

void inorder(BiTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(BiTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        inorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preorder(BiTree ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        inorder(ptr->left);
        inorder(ptr->right);
    }
}