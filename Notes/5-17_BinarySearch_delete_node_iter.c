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

int main(void)
{

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
        else
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
            }
            free(temp);
            printf("Successfully deleted number %d from tree.\n", number);
        }
    }
}

BiTree findmax(BiTree node)
{
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

