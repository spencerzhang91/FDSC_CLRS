/* code fragment 5-17: delete a new item from the binary search tree */
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

BiTree createSearchTree(int init);
BiTree delete_recr(BiTree root, int number);
void delete_iter(BiTree *root, int number);
BiTree findmax(BiTree node);

int main(void)
{
    BiTree tree = createSearchTree(3);
    delete_recr(tree, 2);
    delete_recr(tree, 3);
    
    return 0;
}

BiTree createSearchTree(int init)
{
    BiTree temp = (BiTree)malloc(sizeof(struct treeNode));
    temp->left = temp->right = NULL;
    temp->data = init;
    return temp;
}

BiTree delete_recr(BiTree root, int number)
{
    BiTree temp;
    if (!root) printf("Not found.\n");
    else if (number < root->data)
        root->left = delete_recr(root->left, number);
    else if (number > root->data)
        root->right = delete_recr(root->right, number);
    else
    {
        if (root->left && root->right)
        {
            temp = findmax(root->left); // or findmin(root->right);
            root->data = temp->data;
            root->left = delete_recr(root->left, root->data);
        }
        else
        {
            temp = root;
            if (!root->right) root = root->left;
            else if (!root->left) root = root->right;
            free(temp);
        }
        return root; // to return is for recurse
    }
}

void delete_iter(BiTree *root, int number) // something wrong here!
{
    BiTree temp;
    if (!root) printf("Empty tree!\n");
    while (root)
    {
        if (number < (*root)->data)
            (*root) = (*root)->left;
        else if (number > (*root)->data)
            (*root) = (*root)->right;
        else
        {
            if ((*root)->left && (*root)->right)
            {
                temp = findmax((*root)->left);
                if (temp->left)
                    (*root)->left->right = temp->left;
                (*root)->data = temp->data;
            }
            else
            {
                temp = (*root);
                if (!(*root)->right) (*root) = (*root)->left;
                else if (!(*root)->left) (*root) = (*root)->right;
            }
            free(temp);
        }
    }
}

BiTree findmax(BiTree node)
{
    while (node->right)
        node = node->right;
    return node;
}
