/* 5-1,2,3 inorder, preorder and postorder traversal of binary tree */
typedef struct treeNode *BTree;
struct treeNode {
    int data;
    BTree left;
    BTree right;
};

void inorder(BTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(BTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        inorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preorder(BTree ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        inorder(ptr->left);
        inorder(ptr->right);
    }
}
