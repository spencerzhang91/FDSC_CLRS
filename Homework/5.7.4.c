/* excercise 5.7.4.c */
BiTree delete_recr(BiTree root, int number)
{
    BiTree temp;
    if (!root) printf("Not found.\n");
    else if (number < root->data)
        root->left = delete_recr(root->left, number);
    else if (number > root->data)
        root->right = delete_recr(root->right, number);
    else
    {
        if (root->left && root->right)
        {
            temp = findmax(root->left); // or findmin(root->right);
            root->data = temp->data;
            root->left = delete_recr(root->left, root->data);
        }
        else
        {
            temp = root;
            if (!root->right) root = root->left;
            else if (!root->left) root = root->right;
            free(temp);
        }
        return root; // to return is for recurse
    }
}

BiTree findmax(BiTree node)
{
    while (node->right)
        node = node->right;
    return node;
}