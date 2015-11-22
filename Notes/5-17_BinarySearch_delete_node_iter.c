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
    root->data = 100; root->left = root->right = NULL;
    insert_node_iter(&root, 40);
    insert_node_iter(&root, 102);
    preorder(root);
    puts("fuck");
    delete_iter(root, 50);
    puts("Fuck");
    return 0;
}

void delete_iter(BiTree root, int number) // something wrong here!
{
    BiTree temp;
    if (!root) printf("Empty tree!\n");
    while (root)
    {
        if (number < root->data)
            root = root->left;
        else if (number > root->data)
            root = root->right;
        else if (number == root->data)
        {
            if (root->left && root->right)
            {
                temp = findmax(root->left);
                if (temp->left)
                    root->left->right = temp->left;
                root->data = temp->data;
            }
            else
            {
                temp = root;
                if (!root->right) root = root->left;
                else if (!root->left) root = root->right;
                else printf("The number in not in the binary search tree.\n");
            }
            free(temp);
            printf("Successfully deleted number %d from tree.\n", number);
        }
    }
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