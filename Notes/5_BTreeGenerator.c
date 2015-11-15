/* Binary tree generator array based C implementation */
/* A binary tree of structure below can be represented according to its level
order traversal, missing node is replaced by '#': (LeetCode way)
             A                     A
            / \                   / 
           B   C                 B
          /\    \                \
         D  E    F                D
          (tree1)                (tree2)
tree1: {'A','B','C','D','E','#','F'} or "ABCDE#F";
tree2: {'A','B','#','#','D'} or "AB##D";
The function takes in an array or a tring and returns the root of the tree
*/
#define ElementType char // also can be changed to int, float, etc.
typedef struct treeNode *BTree;
struct treeNode {
	ElementType data;
	BTree left;
	BTree right;
};


