// code list 7-3: compare two element lists
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 1000 // maximum item number plus one
#define COMPARE(x, y) ((x) > (y))? -1: (((x) == (y))? 0: 1)
typedef struct {
    int key;
    char alphabet;
    /* other fields */
} element;

element list_one[MAXSIZE] = {{1,'a'},{2,'b'},{3,'c'},{4,'d'},
                          {5,'e'},{6,'f'},{7,'g'},{8,'g'}};
element list_two[MAXSIZE] = {{1,'a'},{2,'b'},{3,'c'},{4,'d'},
                          {5,'e'},{6,'f'},{7,'g'},{8,'g'}};

int main(void)
{

    return 0;
}

void verify1(element list1, element list2, int m, int n)
{
    /* m: element number of list1; n: element number of list2
       compare two unordered lists list1 and list2 */
    int i, j;
    bool marked[MAXSIZE];
    for (i = 0; i < m; i++)
        marked[i] = false;
    for (i = 0; i < n; i++)
        if ((j = seqsearch(list2, m, list[i].key)) < 0)
            printf("%d is not in list2.\n", list1[i].key);
        else
            marked[j] = true;
    for (i = 0; i < m; i++)
        if (!marked[i])
            printf("%d is not in list1.\n", list2[i].key);    
}