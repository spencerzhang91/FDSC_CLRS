// The whole new start of FDSC after suspention due to essay preperation
// code list 7-1: sequencial search
#include <stdio.h>
#define MAXSIZE 1000 // maximum item number plus one
typedef struct {
    int key;
    /* other fields */
} element;

element list[MAXSIZE] = {{1},{2},{3},{4},{5},{6},{7},{8}};

int seqsearch(element list[], int target, int n)
{
    /* search an array, list, that has n numbers. Return i if list[i] = target
    Return -1 if target is not in the list. */
    int i;
    list[n].key = target;
    for (i = 0; list[i].key != target; i++)
        ;
    return ((i < n)? i: -1);
}

int main(void)
{
    int res = seqsearch(list, 47, 8);
    printf("The result is %d\n", res);

    return 0;
}
