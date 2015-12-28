// code list 7-3: compare two element lists
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 1000 // maximum item number plus one
#define COMPARE(x, y) ((x) > (y))? -1: (((x) == (y))? 0: 1)
typedef struct {
    int key;
    /* other fields */
} element;

element list_one[MAXSIZE] = {{1},{2},{3},{4},{5},{6},{7},{8}};
element list_two[MAXSIZE] = {{1},{3},{5},{7},{9}};

void verify1(element list1[], element list2[], int n, int m);
int seqsearch(element list[], int target, int n);

int main(void)
{
    verify1(list_one, list_two, 8, 5);
    return 0;
}

void verify1(element list1[], element list2[], int n, int m)
{
    /* m: element number of list1; n: element number of list2
       compare two unordered lists list1 and list2 */
    int i, j;
    bool marked[MAXSIZE];
    for (i = 0; i < m; i++)
        marked[i] = false;
    for (i = 0; i < n; i++)
        if ((j = seqsearch(list2, list1[i].key, m)) < 0)  // j is the place where list1[i] is found in list2
            printf("%d is not in list2.\n", list1[i].key);
        else
            marked[j] = true;  // this line means for list2, this j place has common element with list1
    for (i = 0; i < m; i++)
        if (!marked[i])  // if marked[i] is false, then it is not common element with list1
            printf("%d is not in list1.\n", list2[i].key);    
}

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