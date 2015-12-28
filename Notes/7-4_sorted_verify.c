/* code list 7-4: compare two sorted element lists */
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

void verify2(element list1[], element list2[], int n, int m);
void sort(element list[], int len);

int main(void)
{
    verify2(list_one, list_two, 8, 5);
    return 0;
}

void verify2(element list1[], element list2[], int n, int m)
{
    /* same task as verify1, but list1 and list2 are sorted */
    int i, j;
    sort(list1, n);
    sort(list2, m);
    i = j = 0;
    while (i < n && j < m)
        if (list1[i].key < list2[j].key)
        {
            printf("%d is not in list2\n", list1[i].key);
            i++;
        }
        else if (list1[i].key == list2[j].key)
        {
            /* compare list1 and list2 on each of other fields and report any
            siscrepancies */
            i++; j++;
        }
        else
        {
            printf("%d is not in list1\n", list2[j].key);
            j++;
        }
    // the two 'for' block below is to run through left list(1 or 2)
    for (; i < n; i++)
        printf("%d is not in list2\n", list1[i].key);
    for (; j < m; j++)
        printf("%d is not in list1\n", list2[j].key);
}

void sort(element list[], int len)
{
    return;
}

