/* excercise 5.7.5.c */
void delete_iter(BiTree root, int number) // something wrong here!
{
    BiTree temp;
    if (!root) printf("Empty tree!\n");
    while (root)
    {
        if (number < root->data)
            root = root->left;
        else if (number > root->data)
            root = root->right;
        else
        {
            if (root->left && root->right)
            {
                temp = findmax(root->left);
                if (temp->left)
                    root->left->right = temp->left;
                root->data = temp->data;
            }
            else
            {
                temp = root;
                if (!root->right) root = root->left;
                else if (!root->left) root = root->right;
            }
            temp = NULL;
            free(temp);
            printf("Successfully deleted number %d from tree.\n", number);
        }
    }
}

BiTree findmax(BiTree node)
{
    while (node->right)
        node = node->right;
    return node;
}
