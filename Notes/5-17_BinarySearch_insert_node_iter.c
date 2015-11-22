/* code fragment 5-17: insert a new item into the binary search tree */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

void insert_node(BiTree root, int num);
void preorder(BiTree tree);
BiTree search_iter(BiTree root, int key)

int main(void)
{
    BiTree root = (BiTree)malloc(sizeof(struct treeNode));
    root->data = 100; root->left = root->right = NULL;
    return 0;
}

void insert_node(BiTree root, int num)
{
    
}

void preorder(BiTree tree)
{
    if (tree)
    {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
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