/* Test file for 5-4 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType BTree
#define MAX_STACK_SIZE 100
#define MAXSIZE 100

/* binary tree ADT struct definition */
typedef struct treeNode *BTree;
struct treeNode {
    int data;
    BTree left;
    BTree right;
};

/* stack ADT struct definition */
typedef struct {
    ElementType *array;
    int top;
    int maxsize;
} Snode;
typedef Snode *Stack;

/* stack ADT methods */
Stack CreateStack(int size);
bool IsFull(Stack S);
bool IsEmpty(Stack S);
void push(Stack S, ElementType item);
ElementType pop(Stack S);
void display(Stack S);

/* binary tree traversal */
void iter_preorder(BTree root);
void iter_inorder(BTree root);
void iter_postorder(BTree root);
void inorder(BTree ptr);
void preorder(BTree ptr);
void postorder(BTree ptr);
BTree CreateBTree(char *preorder, char *inorder); // yet done

int main(void)
{
	BTree root = (BTree)malloc(sizeof(struct treeNode));
	root->data = 100;
	BTree node0 = (BTree)malloc(sizeof(struct treeNode)); node0->data = 0;
	BTree node1 = (BTree)malloc(sizeof(struct treeNode)); node1->data = 1;
	BTree node2 = (BTree)malloc(sizeof(struct treeNode)); node2->data = 2;
	BTree node3 = (BTree)malloc(sizeof(struct treeNode)); node3->data = 3;
	BTree node4 = (BTree)malloc(sizeof(struct treeNode)); node4->data = 4;
	BTree node5 = (BTree)malloc(sizeof(struct treeNode)); node5->data = 5;
	BTree node6 = (BTree)malloc(sizeof(struct treeNode)); node6->data = 6;
	BTree node7 = (BTree)malloc(sizeof(struct treeNode)); node7->data = 7;
	root->left = node1; root->right = node2;
	node1->left = node3; node1->right = node4;
	node2->left = node5; node2->right = node6;
	node3->left = NULL; node3->right = NULL; node4->left = node7; node4->right = NULL;
	node5->left = NULL; node5->right = NULL; node6->left = NULL; node6->right = NULL;
	node7->left = NULL; node7->right = NULL;

	iter_postorder(root);
	puts("\n");
	postorder(root);
	return 0;
}

/* stack ADT methods */
Stack CreateStack(int size)
{
    Stack newS = (Stack)malloc(sizeof(Stack));
    newS->array = (ElementType *)calloc(size, sizeof(ElementType));
    newS->top = -1;
    newS->maxsize = size;
    return newS;
}

bool IsFull(Stack S)
{
    return S->top - 1 == S->maxsize;
}

bool IsEmpty(Stack S)
{
    return S->top == -1;
}

void push(Stack S, ElementType item)
{
    if (IsFull(S))
    {
        fprintf(stderr, "The stack is full.\n");
        exit(EXIT_FAILURE);
    }
    else
        S->array[++(S->top)] = item;
}

ElementType pop(Stack S)
{
    if (IsEmpty(S))
    {
        fprintf(stderr, "The stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    else
        return S->array[(S->top)--];
}

void display(Stack S)
{
    for (int i = 0; i < S->top + 1; i++)
        printf("%d ", S->array[i]);
    putchar('\n');
}

/* binary tree traversal methods */
void iter_preorder(BTree root)
{
    Stack S = CreateStack(MAXSIZE);          // create and initialize stack
    BTree tree = root;
    while (tree || !IsEmpty(S))        // using 'while' is more readable than 'for'
    {
        while (tree)
        {
            printf("%d ", tree->data);
            push(S, tree);             // push visited node into stack
            tree = tree->left;         // move all the way to left
        }
        if (!IsEmpty(S))
        {
            tree = pop(S);             // when there's no more left subtree,
            tree = tree->right;        // to the right
        }
    }
}

void iter_inorder(BTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BTree tree = root;
    while (tree || !IsEmpty(S))
    {
        while (tree)
        {
            push(S, tree);             // push tree node into stack when still have left child
            tree = tree->left;
        }
        if (!IsEmpty(S))
        {
            tree = pop(S);                 // pop out tree node when no more left child
            printf("%d ", tree->data);     // which means move back upper level and print
            tree = tree->right;            // then, to the right sub tree and repeat
        }
    }
}

void iter_postorder(BTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BTree tree = root;
    while (tree || !IsEmpty(S))
    {
        while (tree)
        {
            if (tree->left)
            {
                push(S, tree);
                tree = tree->left;
            }
            else if (tree->right)
            {
                push(S, tree);
                tree = tree->right;
            }
            else
            {
                printf("%d ", tree->data);
                tree = NULL;
            }
        }
        if (!IsEmpty(S))
            tree = pop(S);
    }
}

BTree CreateBTree(char *preorder, char *inorder)
{
	/* This function use preorder and inorder traversal sequence of a tree to
	create a unique binary tree. The two input is string type and return the 
	head of the constructed tree. */
}

void inorder(BTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(BTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        inorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preorder(BTree ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        inorder(ptr->left);
        inorder(ptr->right);
    }
}
