// excercise 7.3.4 on P208
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 6
typedef struct element element;
typedef element *link;
struct element{
    int key;
    link next;
};

bool ascending(int x, int y);
bool descending(int x, int y);
void showLinkedList(link head);
// The two function below need to change i
int binsearch(element list[], int target, int n, bool (*func)(int x, int y));
link insertion_sort(link list, int n, bool (*func)(int x, int y));

int main(void)
{
    link head;
    element list[SIZE] = {{5},{3},{2},{6},{1},{8}};
    puts("befor sorting:");
    showlist(list, SIZE);
    showLinkedList(list);

    puts("sort ascendingly:");
    head = insertion_sort(list, SIZE, ascending);
    showlist(list, SIZE);
    showLinkedList(list);

    puts("sort descendingly:");
    head = insertion_sort(list, SIZE, descending);
    showlist(list, SIZE);
    showLinkedList(list);

    return 0;
}

void showlist(element *list, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", list[i].key);
    puts("");
}

bool ascending(int x, int y)
{
    return (x < y);
}

bool descending(int x, int y)
{
    return (x > y);
}

link insertion_sort(link list, int n, bool (*func)(int x, int y)) // to be done
{
    // perform a insertion sort on the list, and return a head of linked list
    int i, j, k;
    element next;
    for (i = 1; i < n; i++)
    {
        next = list[i];
        int place = binsearch(list, next.key, i, func);
        for (j = i - 1; j > place; j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
    /* As the excercise requests: construct a linked list from the sorted array,
    which although would be even slow for first time, but would be faster later.
    */
    for (k = 0; k < n - 1; k++)
        list[k].next = &list[k+1];
    list[k].next = NULL;
    link head = (link)malloc(sizeof(element));
    head->next = &list[0];
    return head;
}

int binsearch(element list[], int target, int n, bool (*func)(int x, int y))
{
    /* this binary search function behave according to the input of ascending
    or descending function pointer */
    int left = 0, right = n-1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        switch ((*func)(target, list[middle].key))
        {
            case false: left = middle + 1; break;
            case true: right = middle - 1;
        }
    }
    return right;
}

void showLinkedList(link head)
{
    for (; head; head = head->next)
        printf("%d ", head->key);
    puts("");
}