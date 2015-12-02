/* 5-4 iterative implementation of traversal of binary tree */
/* This file need to be compared with file '5-4_BinaryTree_IterTraversal.c'
since this two is identical in nature and comparable in implementation */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define DataType int
typedef struct treeNode *BiTree;
struct treeNode {
    DataType data;
    BiTree left;
    BiTree right;
};

void iter_inorder(treeNode node);
void iter_preorder(treeNode node);
void iter_postorder(treeNode node);

void inorder(treeNode node);
void preorder(treeNode node);
void postorder(treeNode node);

void push(int *top, treeNode node);
treeNode pop(int *top);
BiTree createBiTree(char *array, int len);
BiTree makenode(DataType data);

int top = -1; // initialize stack
treeNode stack[MAXSIZE];

int main(void)
{
    BiTree tree = createBiTree("0ABCDE#F", 8);
    iter_postorder(tree);
    
    return 0;
}

void iter_inorder(treeNode node)
{
    for (;;)
    {
        for (; node; node = node->left)
            push(&top, node); // push to stack
        node = pop(&top); // pop from stack
        if (!node) break; // empty stack
        printf("%d ", node->data);
        node = node->right;
    }    
}

void iter_preorder(treeNode node)
{
    for (;;)
    {
        for (; node; node = node->left)
        {
            printf("%d ", node->data);
            push(&top, node);
        }
        node = pop(&top); // pop from stack
        if (!node) break; // empty stack
        node = node->right;
    }

}

void iter_postorder(treeNode node)
{
   for (;;)
    {
        for (; node; node = node->left)
            push(&top, node);
        if (!node)
    }
}

void push(int *top, treeNode node)
{
    if (*top >= MAXSIZE - 1)
        return;
    stack[++*top] = node;
}

treeNode pop(int *top)
{
    if (*top == -1)
        return NULL;
    return stack[(*top)--];
}

void inorder(treeNode ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(treeNode ptr)
{
    if (ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preorder(treeNode ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

BiTree createBiTree(char *array, int len)
{
    /* generate a binary tree */
    BiTree parent;
    Queue Q = CreateQueue(len);
    int i = 1;
    BiTree root = makenode(array[i]);
    enqueue(Q, root);

    while (Q && (i*2+1 < len))
    {
        parent = dequeue(Q);      
        BiTree leftchild = makenode(array[i*2]);
        BiTree rightchild = makenode(array[i*2+1]);
        if (leftchild)
        {
            parent->left = leftchild;
            enqueue(Q, leftchild);
        }
        if (rightchild)
        {
            parent->right = rightchild;
            enqueue(Q, rightchild);
        }
        ++i;
    }

return root;
}

BiTree makenode(DataType data)
{
    /* create a tree node and return its pointer if data is not '#' */
    if (data != '#')
    {
        BiTree node = (BiTree)malloc(sizeof(struct treeNode));
        if (!node)
        {
            fprintf(stderr, "Memory full.\n");
            exit(EXIT_FAILURE);
        }
        node->data = data;  // the data type of data is default to char
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else
        return NULL;
}