/* code fragment 5-17: insert a new item into the binary search tree */

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

void insert_node(BiTree *pointer, int num)
{
    BiTree
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

BiTree modified_search(BiTree root, int key)
{
    if (!root)
    {
        printf("The tree is empty.\n");
        return NULL;
    }
    while (root->left || root->right)
    {
        if (root->data == key)
        {
            printf("The key %d is already in the tree.\n", key);
            return NULL;
        }
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}