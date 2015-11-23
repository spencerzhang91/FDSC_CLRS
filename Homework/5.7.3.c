/* excercise 5.7.3.c */
typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

void insert_node_iter(BiTree *root, int num)
{
    /* iterative implementation of inserting a value in the binary search tree */
    if (!search_iter(*root, num)) // means num is not found in the binary tree
    {
        BiTree newptr = (BiTree)malloc(sizeof(struct treeNode));
        newptr->data = num;
        newptr->left = NULL; newptr->right = NULL;
        if (!(*root))
            *root = newptr;
        else
        {
            BiTree temp = *root; BiTree parent;
            while (temp)
            {
                parent = temp;
                if (num < temp->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if (num < parent->data) parent->left = newptr;
            else parent->right = newptr;
        }
    }
    else printf("The number %d is already in the tree.\n", num);
}


BiTree search_iter(BiTree root, int key)
{
    /* return a pointer to the node that contains key. If there's no such key,
    return NULL. */
    while (root)
    {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}