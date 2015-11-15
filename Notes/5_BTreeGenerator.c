/* Binary tree generator array based C implementation */
/* A binary tree of structure below can be represented according to its level
order traversal, missing node is replaced by '#': (LeetCode way)
             A                     A
            / \                   / 
           B   C                 B
          /\    \                \
         D  E    F                D
          (tree1)                (tree2)
tree1: {'0','A','B','C','D','E','#','F'} or "0ABCDE#F";
tree2: {'0','A','B','#','#','D'} or "0AB##D";
First '0' is the sentinel node for subfix conciseness
The function takes in an array or a tring and returns the root of the tree
*/

typedef struct treeNode *BTree;
struct treeNode {
    char data;
    BTree left;
    BTree right;
};

BTree createBTree(char *array, int len)
{
    /* generate a binary tree */
    BTree parent;
    Queue Q = CreateQueue(len);
    int i = 1;
    BTree root = makenode(array[i]);
    //printf("[Line 456] root->data: %c\n", root->data);
    enqueue(Q, root);
    //printf("[Line 458] root->data: %c\n", root->data);

    while (Q && (i*2+1 < len))
    {
        parent = dequeue(Q);
        //printf("[Line 465] i: %d\n", i);        
        BTree leftchild = makenode(array[i*2]);
        BTree rightchild = makenode(array[i*2+1]);
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
        ++i;
    }

BTree makenode(ElementType data)
{
    /* create a tree node and return its pointer if data is not '#' */
    if (data != '#')
    {
        BTree node = (BTree)malloc(sizeof(struct treeNode));
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