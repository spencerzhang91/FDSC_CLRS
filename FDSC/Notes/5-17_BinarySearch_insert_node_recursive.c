/* A recursive implementation of binary search tree node insertion */
#define ElementType int
typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

BiTree Insert(BiTree BST, ElementType X)
{
    if(!BST)
    {   
        /* if BST is empty then create a node with data x */
        BST = (BiTree)malloc(sizeof(struct treeNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
    {
        /* start searching insert point */
        if(X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else  if(X > BST->Data)
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}