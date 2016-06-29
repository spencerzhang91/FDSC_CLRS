/* Convert a binary tree to a threaded binary */
/* There are : preorder, inorder and postorder threaded binary trees. */
/* based on common binary tree constructor (file 5_BTreeGenerator.c) */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ElementType thrBiTree
#define dataType char // the type of data of thrtreeNode
#define MAX_STACK_SIZE 100

/* struct definition for threaded binary tree */
typedef struct thrtreeNode *thrBiTree;
struct thrtreeNode {
    dataType data;
    thrBiTree left;
    thrBiTree right;
    bool left_thr;    // true if no left child: left is a thread
    bool right_thr;   // false if has right child: right links a child
};
/* declare for test */
thrBiTree create_sentinel(thrBiTree root);
thrBiTree makethrnode(dataType data);
thrBiTree createthrBiTree(dataType *array, int len);
thrBiTree linkthr_preorder(thrBiTree root, int len);
thrBiTree linkthr_inorder(thrBiTree root, int len); // to be done
thrBiTree linkthr_postorder(thrBiTree root, int len); // to be done
/* declare for test */


thrBiTree makethrnode(dataType data)
{
    /* create a threaded tree node and return its pointer if data
     is not '#' */
    if (data != '#')
    {
        thrBiTree node = (thrBiTree)malloc(sizeof(struct thrtreeNode));
        if (!node)
        {
            fprintf(stderr, "Memory full.\n");
            exit(EXIT_FAILURE);
        }
        node->data = data; node->left = NULL; node->right = NULL;
        // newly created node has no children yet so threaded set to true
        node->left_thr = true; node->right_thr = true;
        return node;
    }
    else
        return NULL;
}

thrBiTree createthrBiTree(dataType *array, int len)
{
    /* Level orderly generates a threaded binary tree whose threads are yet 
    defined. Output of this function is to be used by linkthr_ functions */
    if (len < 2)
        return NULL;
    thrBiTree parent;
    Queue Q = CreateQueue(len);
    Queue save = CreateQueue(len);
    int i = 1;
    thrBiTree root = makethrnode(array[i]);
    enqueue(Q, root);
    enqueue(save, root);

    while (Q && (i*2+1 < len))
    {
        parent = dequeue(Q);      
        thrBiTree leftchild = makethrnode(array[i*2]);
        thrBiTree rightchild = makethrnode(array[i++*2+1]);
        if (leftchild)
        {
            parent->left = leftchild;
            parent->left_thr = false;
            enqueue(Q, leftchild);
        }
        if (rightchild)
        {
            parent->right = rightchild;
            parent->right_thr = false;
            enqueue(Q, rightchild);
        }
    }
return root;
}

thrBiTree linkthr_preorder(thrBiTree root, int len)
{
    /* input: root is the root node of sent in binary tree
    len is the number of tree nodes excluding sentinel node of arg 'array'
    of function 'thrBiTree createthrBiTree(dataType *array, int len)' 
    The returned 'temp' is the wanted node of the threaded tree. */
    Queue save = CreateQueue(len);
    Stack S = CreateStack(MAXSIZE);          // create and initialize stack
    thrBiTree tree = root;
    thrBiTree prev, curr;               // two pointer to be used to make thread
    thrBiTree sentinel = create_sentinel(root); // create a sentinel node
    while (tree || !IsEmpty(S))        // using 'while' is more readable than 'for'
    {
        while (tree)
        {
            printf("%c ", tree->data);
            enqueue(save, tree);       // save preorder traversed node in queue
            push(S, tree);             // push visited node into stack
            tree = tree->left;         // move all the way to left
        }
        if (!IsEmpty(S))
        {
            tree = pop(S);             // when there's no more left subtree,
            tree = tree->right;        // to the right
        }
    }
    prev = dequeue(save);
    prev->left_thr = true;
    prev->left = sentinel;
    while (!QIsEmpty(save))
    {
        curr = dequeue(save);
        if (!curr->left)
        {
            curr->left_thr = true;
            curr->left = prev;
        }
        if (!prev->right)
        {
            prev->right_thr = true;
            prev->right = curr;
        }
        prev = curr;
    }
    prev->right_thr = true;
    prev->right = sentinel;
    return sentinel;
}

thrBiTree linkthr_inorder(thrBiTree root, int len) // to be done
{
    return root;
}

thrBiTree linkthr_postorder(thrBiTree root, int len)  // to be done
{
    return root;
}

thrBiTree create_sentinel(thrBiTree root)
{
    /* This function creates sentinel node for tree and applies all 
    three linkthr_ functions */
    thrBiTree temp = (thrBiTree)malloc(sizeof(struct thrtreeNode));
    temp->left = root; temp->right = temp;
    temp->left_thr = false; temp->right_thr = false;
    return temp;
}

