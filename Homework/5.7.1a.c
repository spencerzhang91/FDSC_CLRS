/* excercise 5.7.1a.c */
/* insert value to a binary search tree, duplicate value allowed */
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

void insert_node_iter_du(BiTree_duplicate *root, int num);
void preorder(BiTree_duplicate tree);
BiTree_duplicate search_iter(BiTree_duplicate root, int key);

int main(void)
{
    BiTree_duplicate root = (BiTree_duplicate)malloc(sizeof(struct treeNode));
    root->data = 100; root->left = root->right = NULL;
    insert_node_iter_du(&root, 40);
    insert_node_iter_du(&root, 102);
    insert_node_iter_du(&root, 40);
    preorder(root);
    printf("%d ", root->left->count);
    return 0;
}

void insert_node_iter_du(BiTree_duplicate *root, int num)
{
    /* Dupliation allowed vertion of iterative implementation of inserting a value
     in the binary search tree */
    BiTree_duplicate pointer = search_iter(*root, num);
    if (!pointer) // means num is not found in the binary tree
    {
        BiTree_duplicate newptr = (BiTree_duplicate)malloc(sizeof(struct treeNode));
        newptr->data = num; newptr->count = 1;
        newptr->left = NULL; newptr->right = NULL;
        if (!(*root)) // if the search tree is empty tree
            *root = newptr;
        else          // the search tree is not empty tree otherwise
        {
            BiTree_duplicate temp = *root;
            BiTree_duplicate parent;
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
    else
    {
        pointer->count++;
        printf("Number %d is already in the tree and now increased by 1.\n", num);
    }
}

void preorder(BiTree_duplicate tree)
{
    if (tree)
    {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

BiTree_duplicate search_iter(BiTree_duplicate root, int key)
{
    /* return a pointer to the node that contains key. If there's no such key,
    return NULL, else return a pointer point to the found node */
    while (root)
    {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}