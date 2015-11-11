#define LEFT 0
#define RIGHT 1
void iter_postorder(BTree root)
{
    int backfrom;
    Stack S = CreateStack(MAXSIZE);
    BTree tree = root;
    while (tree || !IsEmpty(S))
    {
        while (tree)
        {
            push(S, tree);
            tree = tree->left;
            backfrom = LEFT;
        }
        if (!IsEmpty(S))
        {
            tree = pop(S);
            if (backfrom == LEFT)
                while (tree)
                {
                    push(S,tree);
                    tree = tree->right;
                    backfrom == RIGHT;
                }
            else if (backfrom == RIGHT)
            {
                printf("%d ", tree->data);
                tree = NULL;
            }
        }
    }
}

/* standard implementation from wiki */
void iter_postorder(BTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BTree lastvisited = NULL;
    BTree peeknode = NULL;
    while (!IsEmpty(S) || root)
    {
        if (root)
        {
            push(S, root);
            root = root->left;
        }
        else
        {
            peeknode = pop(S);
            push(S, peeknode); // not now to pop out so push back
            if (peeknode->right && lastvisited != peeknode->right)
                root = peeknode->right;
            else
            {
                printf("%d ", peeknode->data);
                lastvisited = pop(S);
            }
        }
    }
}