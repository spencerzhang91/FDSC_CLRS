/* excercise 5.3.5.c */
void iter_preorder(BTree root)
{
    S = CreateStack(MAXSIZE);          // create and initialize stack
    BTree tree = root;
    while (tree || !isEmpty(S))        // using 'while' is more readable than 'for'
    {
        while (tree)
        {
            printf("%4d", tree->data);
            push(S, tree);             // push visited node into stack
            tree = tree->left;         // move all the way to left
        }
        if (!isEmpty(S))
        {
            tree = pop(S);             // when there's no more left subtree,
            tree = tree->right;        // to the right
        }
    }
}