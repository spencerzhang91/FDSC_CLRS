/* Two implementation of binary Tree storage */
/* Array based storage and linked storage */
#define MAXSIZE 100
// Array based defination:
int BTree[MAXSIZE];

// Linked based defination:
typedef struct Node *TreeNode;
struct Node {
	int data;
	TreeNode left, right;
};