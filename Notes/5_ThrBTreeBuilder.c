/* Convert a binary tree to a threaded binary */
/* There are : preorder, inorder and postorder threaded binary trees. */
/* based on common binary tree constructor (file 5_BTreeGenerator.c) */
#define ElementType thrBTree
#define dataType char // the type of data of thrtreeNode
#define MAX_STACK_SIZE 100

/* struct definition for threaded binary tree */
typedef struct thrtreeNode *thrBTree;
struct thrtreeNode {
    dataType data;
    thrBTree left;
    thrBTree right;
    bool left_thr;    // true if no left child: left is a thread
    bool right_thr;   // false if has right child: right links a child
};
static thrBTree create_sentinel(thrBTree root);

thrBTree makethrnode(dataType data)
{
    /* create a threaded tree node and return its pointer if data
     is not '#' */
    if (data != '#')
    {
        thrBTree node = (thrBTree)malloc(sizeof(struct thrtreeNode));
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

thrBTree createthrBTree(dataType *array, int len)
{
    /* generate a binary tree */
    if (len < 2)
        return NULL;
    thrBTree parent;
    Queue Q = CreateQueue(len);
    int i = 1;
    thrBTree root = makenode(array[i]);
    enqueue(Q, root);
    enqueue(save, root);

    while (Q && (i*2+1 < len))
    {
        parent = dequeue(Q);      
        thrBTree leftchild = makenode(array[i++*2]);
        thrBTree rightchild = makenode(array[i++*2+1]);
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

thrBTree linkthr_preorder(thrBTree root, int len)
{
    /* input: root is the root node of sent in binary tree
    len is the number of tree nodes excluding sentinel node of arg 'array'
    of function 'thrBTree createthrBTree(dataType *array, int len)' */
    Queue save = CreateQueue(len);
    S = CreateStack(MAXSIZE);          // create and initialize stack
    thrBTree tree = root;
    thrBTree prev, curr;               // two pointer to be used to make thread
    thrBTree sentinel = create_sentinel(root); // create a sentinel node
    while (tree || !IsEmpty(S))        // using 'while' is more readable than 'for'
    {
        while (tree)
        {
            printf("%4d", tree->data);
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
    while (!IsEmpty(save))
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

thrBTree linkthr_inorder(thrBTree root, int len)
{
	// to be done
	return root;
}

thrBTree linkthr_preorder(thrBTree root, int len)
{
	// to be done
	return root;
}

static thrBTree create_sentinel(thrBTree root)
{
	thrBTree temp = (thrBTree)malloc(sizeof(struct thrtreeNode));
	temp->left = root; temp->right = temp;
	temp->left_thr = false; temp->right_thr = false;
	return temp;
}

