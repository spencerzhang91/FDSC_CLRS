// This is the C implementation of 5-2_CreateBiTree_sequence.py
/* An algorithm to generete an unique binary tree with its preorder and
inorder sequence.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode *Tree;
struct treeNode
{
    int value;
    Tree left;
    Tree right;
};

Tree CreateBiTree(char *preseq, char *inseq);
void PostOrderTraversal(Tree root);

int main(void)
{
    char *preseq = "ABCDEFGHI";
    char *inseq = "BCAEDGHFI";
    Tree bitree = CreateBiTree(preseq, inseq);
    PostOrderTraversal(bitree);
    printf("Ha, it is a boring test.\n");

    return 0;
}

Tree CreateBiTree(char *preseq, char *inseq)
{
    return NULL;
}

void PostOrderTraversal(Tree root)
{
    
}