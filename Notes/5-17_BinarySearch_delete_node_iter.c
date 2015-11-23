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

void delete_iter(BiTree root, int number);
BiTree findmax(BiTree node);
void preorder(BiTree root);
BiTree search_iter(BiTree root, int key);
void insert_node_iter(BiTree *root, int num);

int main(void)
{
    BiTree root = (BiTree)malloc(sizeof(struct treeNode));
    BiTree left = (BiTree)malloc(sizeof(struct treeNode));
    BiTree test;
    root->data = 10; left->data = 3; root->left = left;
    root->right = left->left = left->right = NULL;
    test = data;
    printf("%d\n", root->left->data);
    printf("%d\n", test->left->data);

    return 0;
}

void delete_iter(BiTree root, int number) // something wrong here!
{
    /* Find the node in the tree if node->data == number, and find proper
    replacement node in node's sub tree, let node->data = replace->data, and
    then acutally delete the replacement node. */
    Bitree delptr, dummy;
    if ((delptr = search_iter(root, number) != NULL) && root)
    {
        if (delptr->left && delptr->right)
        {
            dummy = findmax(delptr->left);
            delptr->left->right = dummy->left;
            deptr->data = dummy->data;
            free(dummy); // What if dummy is NULL?
        }
        
        else
        {
            dummy = delptr;
            if (!delptr->right) delptr = delptr->left;
            else if (!delptr->left) deptr = delptr->right;
            free(dummy);
        }
    }
    else printf("The deletion operation failed because of empty tree
        or number not found in the tree.\n");
}

BiTree findmax(BiTree node)
{
    /* find the right most tree node in sub tree of input 'node' */
    while (node->right)
        node = node->right;
    return node;
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