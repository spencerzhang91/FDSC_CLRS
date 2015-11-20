/* code fragment 5-17: delete a new item from the binary search tree */

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

int main(void)
{
    BiTree tree = createSearchTree(3);
    delete_iter(tree, 2);
    delete_iter(tree, 3);
    
    return 0;
}

BiTree createSearchTree(int init)
{
    BiTree temp = (BiTree)malloc(sizeof(struct treeNode));
    temp->left = temp->right = NULL;
    temp->data = init;
    return temp;
}

BiTree delete_recr(BiTree root, int number)
{
    BiTree temp;
    if (!root) printf("Not found.\n");
    else if (number < root->data)
        root->left = delete(root->left, number);
    else if (number > root->data)
        root->right = delete(root->right, number);
    else
    {
        if (root->left && root->right)
        {
            temp = findmax(root->left); // or findmin(root->right);
            root->data = temp->data;
            root->left = delete(root->left, root->data);
        }
        else
        {
            temp = root;
            if (!right) root = root->left;
            else if (!left) root = root->right;
            free(temp);
        }
        return root; // to return is for recurse
    }
}

void delete_iter(BiTree *root, int number)
{
    BiTree temp;
    if (!root) printf("Empty tree!\n");
    while (root)
    {
        if (number < (*root)->data)
            (*root) = (*root)->left;
        else if (number > (*root)->data)
            (*root) = (*root)->right;
        else
        {
            if ((*root)->left && (*root)->right)
            {
                temp = findmax((*root)->left);
                if (temp->left)
                    (*root)->left->right = temp->left;
                root->data = temp->data;
            }
            else
            {
                temp = (*root);
                if (!right) (*root) = (*root)->left;
                else if (!left) (*root) = (*root)->right;
            }
            free(temp);
        }
    }
}

BiTree findmax(BiTree node)
{
    while (node->right)
        node = node->right;
    return node;
}