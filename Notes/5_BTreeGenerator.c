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
#define ElementType char // also can be changed to int, float, etc.
typedef struct treeNode *BTree;
struct treeNode {
	ElementType data;
	BTree left;
	BTree right;
};

BTree createBTree(char *array, int len)
{
	/* generate a binary tree */
	int i;
	for (i = 1; i * 2 + 1 < len; i++)
	{
		BTree parent = makenode(array[i]);
		BTree leftchild = makenode(array[i*2]);
		BTree rightchild = makenode(array[i*2+1]);
		if (leftchild)
			parent->left = leftchild;
		if (rightchild)
			parent->right = rightchild;
	}

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

