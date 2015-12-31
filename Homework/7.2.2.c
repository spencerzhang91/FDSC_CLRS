// excercise 7.2.2 on P208
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
int binsearch(element list[], int target, int n, bool (*func)(int x, int y));

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
    // from this point to the end of this function need to be modified
    for (i = 1; i < n; i++)
    {
        next = list[i];
        int place = binsearch(list, next.key, i, func);
        for (j = i - 1; j > place; j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
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