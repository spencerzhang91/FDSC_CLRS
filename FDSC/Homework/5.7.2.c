/* excercise 5.7.2.c */
BiTree modified_search(BiTree root, int key)
{
    if (!root)
    {
        printf("The tree is empty.\n");
        return NULL;
    }
    while (root->left || root->right)
    {
        if (root->data == key)
        {
            printf("The key %d is already in the tree.\n", key);
            return NULL;
        }
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}