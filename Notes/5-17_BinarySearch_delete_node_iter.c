/* code fragment 5-17: delete a new item from the binary search tree */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void insert_node_iter(BiTree *root, int num);
void delete_iter(BiTree root, int number);
void preorder(BiTree root);
BiTree search_iter(BiTree root, int key);
Pairs findmax(BiTree node);

int main(void)
{
    BiTree root = (BiTree)malloc(sizeof(struct treeNode));
    root->data = 40; root->left = root->right = NULL;
    for (int i = 0; i < 10; i++)
        insert_node_iter(&root, 10 * i);
    insert_node_iter(&root, 55);
    insert_node_iter(&root, 7);
    insert_node_iter(&root, 3);
    insert_node_iter(&root, 9);
    insert_node_iter(&root, 59);
    insert_node_iter(&root, 57);

    preorder(root); puts("\n");
    delete_iter(root, 60);
    preorder(root);

    return 0;
}

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

void preorder(BiTree root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void insert_node_iter(BiTree *root, int num)
{
    if (!search_iter(*root, num)) // means num is not found in the binary tree
    {
        BiTree newptr = (BiTree)malloc(sizeof(struct treeNode));
        newptr->data = num;
        newptr->left = NULL; newptr->right = NULL;
        if (!(*root))
            *root = newptr;
        else
        {
            BiTree temp = *root; BiTree parent;
            while (temp)
            {
                parent = temp;
                if (num < temp->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if (num < parent->data) parent->left = newptr;
            else parent->right = newptr;
        }
    }
    else printf("The number %d is already in the tree.\n", num);
}

BiTree search_iter(BiTree root, int key)
{
    /* return a pointer to the node that contains key. If there's no such key,
    return NULL. */
    while (root)
    {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}
