/* 5-9 the possibility problme on page 132 of FDSC */
typedef enum {not, and, or, true, false} logical;
typedef struct treeNode *BTree;
struct treeNode {
    int data;
    BTree left;
    BTree right;
};