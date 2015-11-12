/* excercise 5.4.1.c */
typedef struct treeNode *BTree;
struct treeNode {
    int data;
    BTree left;
    BTree right;
};

int iter_countleaf(BTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BTree lastvisited = NULL;
    BTree peeknode = NULL;
    int leaves = 0;
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
                if (!peeknode->left && !peeknode->right)
                	leaves++;
                lastvisited = pop(S);
            }
        }
    }
    return leaves;
}

void countleaf(BTree root, int *count)
{
    if (root)
    {
        countleaf(root->left, count);
        countleaf(root->right, count);
        if (!root->left && !root->right)
            (*count)++;
    }
}