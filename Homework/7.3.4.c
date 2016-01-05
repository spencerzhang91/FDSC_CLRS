// excercise 7.3.4 on P208
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 6
typedef struct node *Linked;
struct node {
    datatype key;
    Linked next;
};

bool ascending(int x, int y);
bool descending(int x, int y);
void showLinkedList(Linked head);
Linked insertion_sort(Linked list, int n, bool (*func)(int x, int y));

int main(void)
{
    Linked sortedhead;
    element list[SIZE] = {{5},{3},{2},{6},{1},{8}};
    puts("befor sorting:");
    showLinkedList(list);

    puts("sort ascendingly:");
    sortedhead = insertion_sort(list, SIZE, ascending);
    showLinkedList(list);

    puts("sort descendingly:");
    sortedhead = insertion_sort(list, SIZE, descending);
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

}

void showLinkedList(link head)
{
    for (; head; head = head->next)
        printf("%d ", head->key);
    puts("");
}