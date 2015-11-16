/* excercise 5.5.5.c */
/* post order traversal of threaded binary tree */
/* struct definition for threaded binary tree */
typedef struct thrtreeNode *thrBTree;
struct thrtreeNode {
    dataType data;
    thrBTree left;
    thrBTree right;
    bool left_thr;    // true if no left child: left is a thread
    bool right_thr;   // false if has right child: right links a child
};

void tpreorder(thrBTree tree)
{
    /* pre-order traversal of threaded binary tree, the input is the sentinel
    node of generated threaded binary tree. */
    thrBTree temp = tree;
    for (;;)
    {
        temp = presucc(temp);
        if (temp == tree) break;
        printf("%c ", temp->data);
    }
}

thrBTree presucc(thrBTree node)
{
    /* find the preorder sucessor of node in a threaded binary tree, the input
    is the sentinel    node of generated threaded binary tree. */
    thrBTree temp;
    temp = node->right;
    if (!node->right_thr)
        if (!node->left_thr)
        	temp = temp->left;
    return temp;
}