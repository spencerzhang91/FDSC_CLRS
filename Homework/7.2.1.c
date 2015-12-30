// excercise 7.2.1 on P208
#include<stdio.h>
#include<stdbool.h>
#define SIZE 5
typedef struct {
    int key;
    // any other possible fields
} element;

void showlist(element *list, int len);
bool ascending(int x, int y);
bool descending(int x, int y);
void insertion_sort(element list[], int n, bool (*func)(int x, int y));

int main(void)
{
    element list[SIZE] = {{5},{3},{2},{6},{1}};
    puts("befor sorting:");
    showlist(list, SIZE);

    puts("sort ascendingly:");
    insertion_sort(list, SIZE, ascending);
    showlist(list, SIZE);

    puts("sort descendingly:");
    insertion_sort(list, SIZE, descending);
    showlist(list, SIZE);
    return 0;
}

void showlist(element *list, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", list[i]);
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

void insertion_sort(element list[], int n, bool (*func)(int x, int y))
{
    // perform a insertion sort on the list
    int i, j;
    element next;
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && (*func)(next.key, list[j].key); j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
}