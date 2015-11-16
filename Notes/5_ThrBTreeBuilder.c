/* Convert a binary tree to a threaded binary */
/* There are : preorder, inorder and postorder threaded binary trees. */
/* based on common binary tree constructor (file 5_BTreeGenerator.c) */
#define ElementType char
/* struct definition for threaded binary tree */
typedef struct treeNode *thrBTree;
struct treeNode {
    char data;
    thrBTree left;
    thrBTree right;
    bool left_thr;    // true if no left child then left is a thread
    bool right_thr;   // false if has right child then right links a child
};

BTree makethrnode(ElementType data)
{
    /* create a threaded tree node and return its pointer if data
     is not '#' */
    if (data != '#')
    {
        BTree node = (BTree)malloc(sizeof(struct treeNode));
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

BTree createthrBTree(char *array, int len)
{
    /* generate a binary tree */
    if (len < 2)
    	return NULL;
    BTree parent;
    Queue Q = CreateQueue(len);
    int i = 1;
    BTree root = makenode(array[i]);
    enqueue(Q, root);
    enqueue(save, root);

    while (Q && (i*2+1 < len))
    {
        parent = dequeue(Q);      
        BTree leftchild = makenode(array[i*2]);
        BTree rightchild = makenode(array[i*2+1]);
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
        ++i;
    }

return root;
}

void linkthr_preorder(BTree root, int len)
{
	/* input: root is the root node of sent in binary tree
	len is the number of tree nodes excluding sentinel node of arg 'array'
	of function 'BTree createthrBTree(char *array, int len)' */
	Queue save = CreateQueue()
}

void linkthr_inorder(BTree root)
{

}

void linkthr_preorder(BTree root)
{

}