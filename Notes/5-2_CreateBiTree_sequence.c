// This is the C implementation of 5-2_CreateBiTree_sequence.py
/* An algorithm to generete an unique binary tree with its preorder and
inorder sequence.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treeNode *Tree;
struct treeNode
{
    int value;
    Tree left;
    Tree right;
};

Tree CreateBiTree(char *preseq, char *inseq);
void PostOrderTraversal(Tree root);
Tree CreateBiTreeNode(int value);

int main(void)
{
    char *preseq = "ABCDEFGHI";
    char *inseq = "BCAEDGHFI";
    // Tree bitree = CreateBiTree(preseq, inseq);
    // PostOrderTraversal(bitree);
    printf("Ha, it is a boring test.\n");
    printf("Length: %d\n", (int)strlen(inseq));
    char cha = *(strchr(preseq, 'E'));
    char first = *preseq;
    printf("The char is %c", cha);
    printf("First char of preseq: %c\n", first);
    CreateBiTreeNode(first);
    return 0;
}

Tree CreateBiTree(char *preseq, char *inseq)
{
    char curr;
    if (strlen(preseq) <= 0 && strlen(inseq) <= 0)
        return NULL;
    else
    {
        curr = *preseq;
        // TODO:
        // split inorder sequence into two parts
        // split preorder sequence into two parts
        // NOT DONE YET
        return NULL;
    }
}

void PostOrderTraversal(Tree root)
{
    if (root)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d ", root->value);
    }
}

Tree CreateBiTreeNode(int value)
{
    Tree node = (Tree)malloc(sizeof(struct treeNode));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}
