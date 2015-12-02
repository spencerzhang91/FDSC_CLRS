/* Test file for binary tree related functions */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
#define MAXSIZE 100
#define LEFT 0
#define RIGHT 1
#define IS_FULL(x) ((x)==NULL)?1: 0
#define N 10
#define ElementType BiTree
#define dataType char // the type of data of thrtreeNode


/* binary tree ADT struct definition */
typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

/* stack ADT struct definition */
typedef struct {
    ElementType *array;
    int top;
    int maxsize;
} Snode;
typedef Snode *Stack;

/* queue ADT struct definition */
struct Node{
    ElementType data;
    struct Node *next;
};

typedef struct {
    struct Node *front;
    struct Node *rear;
    int cursize;
    int maxsize;
} Qnode;
typedef Qnode *Queue;

/* stack ADT methods */
Stack CreateStack(int size);
bool IsFull(Stack S);
bool IsEmpty(Stack S);
void push(Stack S, ElementType item);
ElementType pop(Stack S);
void display(Stack S);

/* queue ADT methods */
Queue CreateQueue(int maxsize);
bool QIsFull(Queue Q);
bool QIsEmpty(Queue Q);
void enqueue(Queue Q, ElementType item);
ElementType dequeue(Queue Q);


/* binary tree traversal */
void iter_preorder(BiTree root);
void iter_inorder(BiTree root);
void iter_postorder(BiTree root);
void iter_postorder1(BiTree root);
void iter_postorder2(BiTree root);

void inorder(BiTree ptr);
void preorder(BiTree ptr);
void postorder(BiTree ptr);

BiTree copy(BiTree origin);
bool isEqual(BiTree t1, BiTree t2);
void countleaf(BiTree root, int *count);
int iter_countleaf(BiTree root);
void swaptree(BiTree root);

/* binary tree creation and helper function */
BiTree createBiTree(char *array, int len);
BiTree makenode(char data);

int main(void)
{
    char info2[N+1] = "0abcd##e#f";
    BiTree testree = createBiTree(info2, N+1);
    iter_preorder(testree);
    iter_inorder(testree);
    iter_postorder(testree);
    
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

/* queue ADT methods */
Queue CreateQueue(int maxsize)
{
    Queue temp = (Queue)malloc(sizeof(Qnode));
    temp->front = temp->rear = NULL;
    temp->maxsize = maxsize;
    temp->cursize = 0;
    return temp;
}

bool QIsFull(Queue Q)
{
    return Q->cursize == Q->maxsize;
}

bool QIsEmpty(Queue Q)
{
    return Q->front == NULL;
}

void enqueue(Queue Q, ElementType item)
{
    struct Node *rearcell;
    ElementType rearelem = item;
    if (QIsFull(Q))
    {
        printf("The queue is Full.\n");
        exit(1);
    }
        
    else
    {
        rearcell = (struct Node *)malloc(sizeof(struct Node));
        rearcell->data = rearelem;
        if (Q->cursize == 0)
            Q->front = Q->rear = rearcell;
        else
        {
            Q->rear->next = rearcell;
            Q->rear = Q->rear->next;
        }    
        ++Q->cursize;
    }
}

ElementType dequeue(Queue Q)
{
    struct Node *frontcell;
    ElementType frontelem;
    if (QIsEmpty(Q))
    {
        printf("The queue is empty.\n");
        return NULL; 
    }
    else
    {
        frontcell = Q->front;
        frontelem = frontcell->data;
        if (Q->front == Q->rear)
            Q->front = Q->rear = NULL;
        else
            Q->front = Q->front->next;
        free(frontcell);
        --Q->cursize;
        return frontelem;
    }
}

/* binary tree traversal methods */
void iter_preorder(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);    // create and initialize stack
    BiTree tree = root;
    while (tree || !IsEmpty(S))        // using 'while' is more readable than 'for'
    {
        while (tree)
        {
            printf("%c ", tree->data);
            push(S, tree);             // push visited node into stack
            tree = tree->left;         // move all the way to left
        }
        if (!IsEmpty(S))
        {
            tree = pop(S);             // when there's no more left suBiTree,
            tree = tree->right;        // to the right
        }
    }
    printf("\n");
}

void iter_inorder(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BiTree tree = root;
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
            printf("%c ", tree->data);     // which means move back upper level and print
            tree = tree->right;            // then, to the right sub tree and repeat
        }
    }
    printf("\n");
}

#define LEFT 0
#define RIGHT 1
void iter_postorder(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BiTree lastvisited = NULL;
    BiTree peeknode = NULL;
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
                printf("%c ", peeknode->data);
                lastvisited = pop(S);
            }
        }
    }
    printf("\n");
}

void iter_postorder1(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BiTree lastvisited = NULL;
    BiTree peeknode = NULL;
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
                printf("%c ", peeknode->data);
                lastvisited = pop(S);
            }
        }
    }
    printf("\n");
}

/* no visited flag solution */
void iter_postorder2(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BiTree prev = NULL; // previously traversed(not necessarily printed) node
    push(S, root);
    BiTree curr = NULL;
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
    printf("\n");
}

void inorder(BiTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(BiTree ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        inorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preorder(BiTree ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        inorder(ptr->left);
        inorder(ptr->right);
    }
}

BiTree copy(BiTree origin)
{
    if (origin)
    {
        BiTree temp = (BiTree)malloc(sizeof(struct treeNode));
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

bool isEqual(BiTree t1, BiTree t2)
{
    return (!t1 && !t2) || (t1 && t2 && (t1->data == t2->data) &&
    isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right));
}

void countleaf(BiTree root, int *count)
{
    if (root)
    {
        countleaf(root->left, count);
        countleaf(root->right, count);
        if (!root->left && !root->right)
            (*count)++;
    }
}

int iter_countleaf(BiTree root)
{
    Stack S = CreateStack(MAXSIZE);
    BiTree lastvisited = NULL;
    BiTree peeknode = NULL;
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

void swaptree(BiTree root)
{
    if (!root)
        return;
    BiTree temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    swaptree(root->left);
    swaptree(root->right);
}

BiTree createBiTree(char *array, int len)
{
    /* generate a binary tree */
    BiTree parent;
    Queue Q = CreateQueue(len);
    int i = 1;
    BiTree root = makenode(array[i]);
    //printf("[Line 456] root->data: %c\n", root->data);
    enqueue(Q, root);
    //printf("[Line 458] root->data: %c\n", root->data);

    while (Q && (i*2+1 < len))
    {
        parent = dequeue(Q);
        //printf("[Line 465] i: %d\n", i);        
        BiTree leftchild = makenode(array[i*2]);
        BiTree rightchild = makenode(array[i++*2+1]);
        if (leftchild)
        {
            parent->left = leftchild;
            //printf("[Line 471] leftchild->data: %c | i: %d\n", leftchild->data, i);
            enqueue(Q, leftchild);
            //printf("[Line 473] leftchild->data: %c | i: %d\n", leftchild->data, i);
        }
        if (rightchild)
        {
            parent->right = rightchild;
            //printf("[Line 478] rightchild->data: %c | i: %d\n", rightchild->data, i);
            enqueue(Q, rightchild);
            //printf("[Line 480] rightchild->data: %c | i: %d\n", rightchild->data, i);
        }
    }
return root;
}

BiTree makenode(char data)
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
        node->data = data; node->left = NULL; node->right = NULL;
        return node;
    }
    else
        return NULL;
}

