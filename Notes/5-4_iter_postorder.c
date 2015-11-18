#define LEFT 0
#define RIGHT 1

/* standard solution from wiki */
void iter_postorder(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BiTree lastvisited = NULL;
    BiTree peeknode = NULL;
    while (!IsEmpty(S) || root)
    {
        if (root)
        {
            push(S, root);
            root = root->left;
        }
        else
        {
            peeknode = top(S) // not now to pop out so push back
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

/* no visited flag solution */
void iter_postorder2(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BiTree prev = NULL; // previously traversed(not necessarily printed) node
    push(S, root);
    BiTree curr = NULL;
    while (!IsEmpty(S))
    {
        curr = top(S);
        if (!prev || prev->left == curr || prev->right == curr)
        {
            // traversing down the tree
            if (curr->left)
                push(S, curr->left);
            else if (curr->right)
                push(S, curr->right);
            else
            {
                printf("%d ", curr->data);
                pop(S);
            }
        }
        else if (curr->left == prev)
        {
            // traversing up the tree from left sub tree
            if (curr->right)
                push(S, curr->right);
            else
            {
                printf("%d ", curr->data);
                pop(S);
            }
        }
        else if (curr->right == prev)
        {
            // traversing up the tree from right sub tree
            printf("%d ", curr->data);
            pop(S);
        }
        prev = curr;
    }
}