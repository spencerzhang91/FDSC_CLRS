/* Preorder, inorder and postorder traversal algorithm of binary tree */
/* Using stack ADT to implement iteratively */
/* This file need to be compared with file '5-4_iterBTreeTraversal.c'
since this two is identical in nature and comparable in implementation
I personaly reckon this version as better implemented */

#define MAXSIZE 10                     // the maxsize of tree nodes

typedef struct treeNode *BTree;
struct treeNode {
    int data;
    BTree left;
    BTree right;
};

void iter_preorder(BTree root);
void iter_inorder(BTree root);
void iter_postorder(BTree root);

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

void iter_inorder(BTree root)
{
    S = CreateStack(MAXSIZE);
    BTree tree = root;
    while (tree || isEmpty(S))
    {
        while (tree)
        {
            push(S, tree);                 // push tree node into stack when still have left child
            tree = tree->left;
        }
        if (!isEmpty(S))
        {
            tree = pop(S);                 // pop out tree node when no more left child
            printf("%4d", tree->data);     // which means move back upper level and print
            tree = tree->right;            // then, to the right sub tree and repeat
        }
    }
}

void iter_postorder(BTree root)
{
    S = CreateStack(MAXSIZE);
    BTree tree = root;
    while (tree || isEmpty(S))
    {
        while (tree)
        {
            if (tree->left)
            {
                push(S, tree);
                tree = tree->left;
            }
            else if (tree->right)
            {
                push(S, tree);
                tree = tree->right;
            }
            else
            {
                printf("%4d", tree->data);
                tree = NULL;
            }
        }
        if (!isEmpty(S))
            tree = pop(S);
    }
}