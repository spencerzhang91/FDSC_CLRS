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
#define DataType char
typedef struct treeNode *BiTree;
struct treeNode {
    DataType data;
    BiTree left;
    BiTree right;
};

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
