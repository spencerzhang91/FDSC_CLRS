#define LEFT 0
#define RIGHT 1

/* standard solution from wiki */
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

/* my own solution */
void iter_postorder(BTree root)
{
	S = CreateStack(MAXSIZE);
    BTree tree = root;
    BTree visited;
	push(S, tree);
    while (tree || isEmpty(S))
    {
        if (tree->left && tree->left != visited)
        {
            push(S, tree->left);
            tree = tree->left;
        }
        else if (tree->right && tree->right != visited)
        {
            push(S, tree->right);
            tree = tree->right;
        }
        else
            break;
    }
    if (!isEmpty(S))
    {
        printf("%d ", tree->data);
        visited = tree;
        tree = pop(S);
    }
}