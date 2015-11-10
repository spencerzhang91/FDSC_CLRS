/* Test file for 5-4 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define MAX_STACK_SIZE 100
#define MAXSIZE 10

/* binary tree ADT struct definition */
typedef struct treeNode *BTree;
struct treeNode {
    ElementType data;
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
BTree CreateBTree(char *preorder, char *inorder); // yet done

int main(void)
{
	
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
    S = CreateStack(MAXSIZE);          // create and initialize stack
    BTree tree = root;
    while (tree || !isEmpty(S))        // using 'while' is more readable than 'for'
    {
        while (tree)
        {
            printf("%4d", tree->data);
            push(S, tree);             // push visited node into stack
            tree = tree->left;         // move all the way to left
        }
        if (!isEmpty(S))
        {
            tree = pop(S);             // when there's no more left subtree,
            tree = tree->right;        // to the right
        }
    }
}

void iter_inorder(BTree root)
{
    S = CreateStack(MAXSIZE);
    BTree tree = root;
    while (tree || isEmpty(S))
    {
        while (tree)
        {
            push(S, tree);                 // push tree node into stack when still have left child
            tree = tree->left;
        }
        if (!isEmpty(S))
        {
            tree = pop(S);                 // pop out tree node when no more left child
            printf("%4d", tree->data);     // which means move back upper level and print
            tree = tree->right;            // then, to the right sub tree and repeat
        }
    }
}

void iter_postorder(BTree root)
{
    S = CreateStack(MAXSIZE);
    BTree tree = root;
    while (tree || isEmpty(S))
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
                printf("%4d", tree->data);
                tree = NULL;
            }
        }
        if (!isEmpty(S))
            tree = pop(S);
    }
}

BTree CreateBTree(char *preorder, char *inorder)
{
	/* This function use preorder and inorder traversal sequence of a tree to
	create a unique binary tree. The two input is string type and return the 
	head of the constructed tree. */
}