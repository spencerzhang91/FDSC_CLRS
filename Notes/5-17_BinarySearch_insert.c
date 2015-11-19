/* code fragment 5-17: insert a new item into the binary search tree */

typedef struct treeNode *BiTree;
struct treeNode {
    int data;
    BiTree left;
    BiTree right;
};

void insert_node(BiTree *pointer, int num)
{
    
    BiTree ptr; // to point to num container node(to be created on the fly)
    BiTree temp = modified_search(*pointer, num);
    if (temp || !*pointer) // means num is not in the tree
    {
        ptr = (BiTree)malloc(sizeof(treeNode));
        if (!ptr)
        {
            fprintf(stderr, "The memory is full.\n");
            exit(EXIT_FAILURE);
        }
        ptr->data = num; ptr->left = ptr->right = NULL;
        if (*pointer) // which means the tree is not empty
        {
            if (num < temp->data) temp->left = ptr;
            else temp->right = ptr;
        }
        else // pointer is an empty tree
            *pointer = ptr;            
    }
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