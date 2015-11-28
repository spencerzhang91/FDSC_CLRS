/* excercise 5.7.1b.c */
/* delete value from a binary search tree, duplicate value allowed */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode *BiTree_duplicate;
struct treeNode {
    int data;
    int count;    // count duplicate values
    BiTree_duplicate left;
    BiTree_duplicate right;
};

typedef struct pair *Pairs; // to contain result of modified findmax function
struct pair {
    BiTree_duplicate parent;
    BiTree_duplicate child;
};

void insert_node_iter_du(BiTree_duplicate *root, int num);
void delete_iter_du(BiTree_duplicate root, int number);
void preorder(BiTree_duplicate root);
BiTree_duplicate search_iter(BiTree_duplicate root, int key);
Pairs findmax(BiTree_duplicate node);

int main(void)
{
    BiTree_duplicate root = (BiTree_duplicate)malloc(sizeof(struct treeNode));
    root->data = 40; root->left = root->right = NULL;
    for (int i = 0; i < 10; i++)
        insert_node_iter_du(&root, 10 * i);
    insert_node_iter_du(&root, 55);
    insert_node_iter_du(&root, 7);
    insert_node_iter_du(&root, 3);
    insert_node_iter_du(&root, 9);
    insert_node_iter_du(&root, 59);
    insert_node_iter_du(&root, 57);

    preorder(root); puts("\n");
    delete_iter_du(root, 60);
    preorder(root);

    return 0;
}

void delete_iter_du(BiTree_duplicate root, int number) // something wrong here!
{
    /* Find the node in the tree if node->data == number, and find proper
    replacement node in node's sub tree, let node->data = replace->data, and
    then acutally delete the replacement node. */
    BiTree_duplicate delptr;
    BiTree_duplicate parent, child;
    Pairs found;
    if ((delptr = search_iter(root, number)) != NULL && root)
    {
        if (delptr->count > 1)
            delptr->count--;
        else
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
    }
    else printf("\nThe deletion operation failed because of empty tree"
    "or number not found in the tree.\n");
}

Pairs findmax(BiTree_duplicate node)
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

void preorder(BiTree_duplicate root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void insert_node_iter_du(BiTree_duplicate *root, int num)
{
    /* Dupliation allowed vertion of iterative implementation of inserting a value
     in the binary search tree */
    if (!search_iter(*root, num)) // means num is not found in the binary tree
    {
        BiTree_duplicate newptr = (BiTree_duplicate)malloc(sizeof(struct treeNode));
        newptr->data = num;
        newptr->left = NULL; newptr->right = NULL;
        if (!(*root))
            *root = newptr;
        else
        {
            BiTree_duplicate temp = *root; BiTree_duplicate parent;
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

BiTree_duplicate search_iter(BiTree_duplicate root, int key)
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
