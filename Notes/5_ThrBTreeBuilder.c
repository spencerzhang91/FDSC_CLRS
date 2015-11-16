/* Convert a binary tree to a threaded binary */
/* There are : preorder, inorder and postorder threaded binary trees. */
/* based on common binary tree constructor (file 5_BTreeGenerator.c) */
typedef struct treeNode *thrBTree;
struct treeNode {
    char data;
    thrBTree left;
    thrBTree right;
};