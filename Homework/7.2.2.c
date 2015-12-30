// excercise 7.2.2 on P208
#include<stdio.h>
#include<stdbool.h>
#define COMPARE(x, y) ((x) > (y))? -1: (((x) == (y))? 0: 1)
#define SIZE 5
typedef struct {
    int key;
    // any other possible fields
} element;

void showlist(element *list, int len);
bool ascending(int x, int y);
bool descending(int x, int y);
void insertion_sort(element list[], int n, bool (*func)(int x, int y));
int binsearch(element list[], int target, int n);

int main(void)
{

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
        for (j = i - 1; j >= 0 && (*func)(next.key, list[j].key); j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
}

int binsearch(element list[], int target, int n)
{
    int left = 0, right = n-1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        switch (COMPARE(target, list[middle].key))
        {
            case -1: left = middle + 1; break;
            case 0: return middle;
            case 1: right = middle - 1;
        }
    }
    return -1;
}