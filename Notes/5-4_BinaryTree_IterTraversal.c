/* Preorder, inorder and postorder traversal algorithm of binary tree */
/* Using stack ADT to implement iteratively */
/* This file need to be compared with file '5-4_iterBiTreeTraversal.c'
since this two is identical in nature and comparable in implementation
I personaly reckon this version as better implemented */

#define MAXSIZE 10                     // the maxsize of tree nodes

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

void iter_preorder(BiTree root)
{
    S = CreateStack(MAXSIZE);          // create and initialize stack
    BiTree tree = root;
    while (tree || !IsEmpty(S))        // using 'while' is more readable than 'for'
    {
        while (tree)
        {
            printf("%4d", tree->data);
            push(S, tree);             // push visited node into stack
            tree = tree->left;         // move all the way to left
        }
        if (!IsEmpty(S))
        {
            tree = pop(S);             // when there's no more left subtree,
            tree = tree->right;        // to the right
        }
    }
}

void iter_inorder(BiTree root)
{
    S = CreateStack(MAXSIZE);
    BiTree tree = root;
    while (tree || IsEmpty(S))
    {
        while (tree)
        {
            push(S, tree);                 // push tree node into stack when still have left child
            tree = tree->left;
        }
        if (!IsEmpty(S))
        {
            tree = pop(S);                 // pop out tree node when no more left child
            printf("%4d", tree->data);     // which means move back upper level and print
            tree = tree->right;            // then, to the right sub tree and repeat
        }
    }
}

void iter_postorder(BiTree root)
{
    /* standard solution from wiki
    see more solution in file 5-4_iter_postorder.c */
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
            peeknode = top(S); // 'top()' gets but not pop out the stack top
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