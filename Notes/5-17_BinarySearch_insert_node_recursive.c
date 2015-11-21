/* A recursive implementation of binary search tree node insertion */

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};