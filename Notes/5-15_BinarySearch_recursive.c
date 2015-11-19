/* code fragment 5-15: recursive way to do binary search 
   The time complexity is O(h) and additional stack space consumption O(h) 
   h is the height of the tree.
*/
typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

BiTree search_recr(BiTree root, int key)
{
    /* return a pointer to the node that contains key. If there's no such key,
    return NULL. */
    if (!root) return NULL;
    if (key == root->data) return root;
    if (key < root->data)
        return search_recr(root->left, key);
    else
        return search_recr(root->right, key);
}