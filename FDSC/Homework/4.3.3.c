/* Excercise 4.3.3.c */
#include <stdio.h>
#define pos char
#define element int

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Linked;
typedef Linked X2; // added for this problem

void insert(X2 list, element item, pos p)
{
	if (p == 'f')
		add(list, item);
	else if (p == 'b')
		addq(list, item);
	else
		fprintf(stderr, "wtf???");
}

element delete(X2 list)
{
    /* define delete function as can only 
    delete element from head */
    X2 temp = *top;
    element item;
    item = (*temp)->item;
    *top = (*temp)->next;
    free(temp);
    return item;
}