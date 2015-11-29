/* excercise 5.6.6.c */
#include <stdio.h>
#include <stdbool.h>

typedef ElementType int;
typedef heapnode *Heap;
struct heapnode {
    ElementType value;
    Heap lchild;
    Heap rchild;
    Heap parent;
};

int main(void)
{
    return 0;
}

void insert(Heap heap, ElementType item)
{

}

ElementType delete(Heap heap)
{
    
}
