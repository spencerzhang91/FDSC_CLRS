/* Test file for 5-4 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType BTree
#define MAX_STACK_SIZE 100
#define MAXSIZE 100
#define LEFT 0
#define RIGHT 1
#define IS_FULL(x) ((x)==NULL)?1: 0

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
void iter_postorder2(BTree root);

void inorder(BTree ptr);
void preorder(BTree ptr);
void postorder(BTree ptr);
BTree CreateBTree(char *preorder, char *inorder); // yet done
BTree copy(BTree origin);
bool isEqual(BTree t1, BTree t2);
void countleaf(BTree root, int *count);
int iter_countleaf(BTree root);

int main(void)
{
	BTree root = (BTree)malloc(sizeof(struct treeNode));
	root->data = 100;

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

	iter_postorder2(root);
	int leaves = 0;
	int leaves2 = iter_countleaf(root);
    countleaf(root, &leaves);
	printf("\nrecursive counted leaf number: %d\n", leaves);
	printf("iterative counted leaf number: %d\n", leaves2);
	
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

#define LEFT 0
#define RIGHT 1
void iter_postorder(BTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BTree lastvisited = NULL;
    BTree peeknode = NULL;
    while (!IsEmpty(S) || root)
    {
        if (root)
        {
            push(S, root);
            root = root->left;
        }
        else
        {
            peeknode = pop(S);
            push(S, peeknode); // not now to pop out so push back
            if (peeknode->right && lastvisited != peeknode->right)
                root = peeknode->right;
            else
            {
                printf("%d ", peeknode->data);
                lastvisited = pop(S);
            }
        }
    }
}

/* no visited flag solution */
void iter_postorder2(BTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BTree prev = NULL; // previously traversed(not necessarily printed) node
    push(S, root);
    BTree curr = NULL;
    while (!IsEmpty(S))
    {
        curr = pop(S);
        push(S, curr);
        if (!prev || prev->left == curr || prev->right == curr)
        {
            // traversing down the tree
            if (curr->left)
                push(S, curr->left);
            else if (curr->right)
                push(S, curr->right);
            else
            {
                printf("%d ", curr->data);
                pop(S);
            }
        }
        else if (curr->left == prev)
        {
            // traversing up the tree from left sub tree
            if (curr->right)
                push(S, curr->right);
            else
            {
                printf("%d ", curr->data);
                pop(S);
            }
        }
        else if (curr->right == prev)
        {
            // traversing up the tree from right sub tree
            printf("%d ", curr->data);
            pop(S);
        }
        prev = curr;
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

BTree copy(BTree origin)
{
    if (origin)
    {
        BTree temp = (BTree)malloc(sizeof(struct treeNode));
        if (IS_FULL(temp))
        {
            fprintf(stderr, "The memory is full.\n");
            exit(1);
        }
        temp->left = copy(origin->left);
        temp->right = copy(origin->right);
        temp->data = origin->data;
        return temp;
    }
    return NULL;
}

bool isEqual(BTree t1, BTree t2)
{
    return (!t1 && !t2) || (t1 && t2 && (t1->data == t2->data) &&
    isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right));
}

void countleaf(BTree root, int *count)
{
    if (root)
    {
        countleaf(root->left, count);
        countleaf(root->right, count);
        if (!root->left && !root->right)
            (*count)++;
    }
}

int iter_countleaf(BTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BTree lastvisited = NULL;
    BTree peeknode = NULL;
    int leaves = 0;
    while (!IsEmpty(S) || root)
    {
        if (root)
        {
            push(S, root);
            root = root->left;
        }
        else
        {
            peeknode = pop(S);
            push(S, peeknode); // not now to pop out so push back
            if (peeknode->right && lastvisited != peeknode->right)
                root = peeknode->right;
            else
            {
                printf("%d ", peeknode->data);
                if (!peeknode->left && !peeknode->right)
                	leaves++;
                lastvisited = pop(S);
            }
        }
    }
    return leaves;
}
