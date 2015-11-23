/* excercise 5.7.5.c */
typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

typedef struct pair *Pairs; // to contain result of modified findmax function
struct pair {
    BiTree parent;
    BiTree child;
};

void delete_iter(BiTree root, int number) // something wrong here!
{
    /* Find the node in the tree if node->data == number, and find proper
    replacement node in node's sub tree, let node->data = replace->data, and
    then acutally delete the replacement node. */
    BiTree delptr, temp;
    BiTree parent, child;
    Pairs found;
    if ((delptr = search_iter(root, number)) != NULL && root)
    {
        if (delptr->left && delptr->right)
        {
            found = findmax(delptr->left);
            parent = found->parent; child = found->child;
            delptr->data = child->data;
            if (parent) parent->right = child->left;
            free(child); child = NULL;            
        }
        else
        {
            child = delptr;
            if (!delptr->right) delptr = delptr->left;
            else if (!delptr->left) delptr = delptr->right;
            free(child); child = NULL;
        }
    }
    else printf("\nThe deletion operation failed because of empty tree"
    "or number not found in the tree.\n");
}

Pairs findmax(BiTree node)
{
    /* find the right most tree node in sub tree of input 'node' */
    Pairs P = (Pairs)malloc(sizeof(struct pair));
    P->parent = NULL; P->child = node;
    while (P->child->right)
    {
        P->parent = P->child;
        P->child = P->child->right;
    }
    return P;
}
