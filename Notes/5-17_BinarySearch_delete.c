/* code fragment 5-17: delete a new item from the binary search tree */
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

BiTree createSearchTree(int init); //
BiTree delete_recr(BiTree root, int number);//

void delete_iter(BiTree root, int number);
BiTree findmax(BiTree node);
void preorder(BiTree root);
void insert_node(BiTree *pointer, int num);
BiTree modified_search(BiTree root, int key);

int main(void)
{
    BiTree tree = createSearchTree(3);
    preorder(tree);
    
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
            return;
        }
    }
    printf("Number %d not found in the tree.\n", number);
    puts("\n");
    return;
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

void insert_node(BiTree *pointer, int num)
{
    
    BiTree ptr; // to point to num container node(to be created on the fly)
    BiTree temp = modified_search(*pointer, num);
    if (temp || !*pointer) // means num is not in the tree
    {
        ptr = (BiTree)malloc(sizeof(struct treeNode));
        if (!ptr)
        {
            fprintf(stderr, "The memory is full.\n");
            exit(EXIT_FAILURE);
        }
        ptr->data = num; ptr->left = ptr->right = NULL;
        if (*pointer) // which means the tree is not empty
        {
            if (num < temp->data) temp->left = ptr;
            else temp->right = ptr;
        }
        else // pointer is an empty tree
            *pointer = ptr;            
    }
}


BiTree modified_search(BiTree root, int key)
{
    if (!root)
    {
        printf("The tree is empty.\n");
        return NULL;
    }
    while (root->left || root->right)
    {
        if (root->data == key)
        {
            printf("The key %d is already in the tree.\n", key);
            return NULL;
        }
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}
