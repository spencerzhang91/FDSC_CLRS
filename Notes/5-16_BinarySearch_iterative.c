/* code fragment 5-15: recursive way to do binary search 
   The time complexity is O(h). h is the height of the tree.
*/
typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

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