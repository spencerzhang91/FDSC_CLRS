// excercise 7.1.4 on P206
/* This excercise is to compare efficiency of two differenct
search algorthms: binary search and interpolation search */

#include <stdio.h>
#define SIZE 5
#define MAXSIZE 1000 // maximum item number plus one
#define COMPARE(x, y) ((x) > (y))? -1: (((x) == (y))? 0: 1)
typedef struct {
    int key;
    // any other possible fields
} element;

int itpsearch(element list[], int target, int n);
int binsearch(element list[], int target, int n);

int main(void)
{
    element list[MAXSIZE] = {{1},{2},{3},{4},{5},{6},{7},{8}};
    int rec1 = 0, rec2 = 0;
    int res1 = itpsearch(list, 5, 8);
    int res2 = binsearch(list, 5, 8);
    printf("res1: %d  res2: %d\n", res1, res2);
    printf("rec1: %d steps, rec2: %d steps\n", rec1, rec2);
    runtime(&rec1);
    return 0;
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

int itpsearch(element list[], int target, int n)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (list[left].key <= list[right].key && target >= list[left].key &&
        target <= list[right].key)
    {
        mid = left + (target - list[left].key) *
        ((right - left) / (list[right].key - list[left].key));
        if (list[mid].key < target)
            left = mid + 1;
        else if (list[mid].key > target)
            right = mid - 1;
        else return mid;
    }
    if (target == list[left].key)
        return left;
    else return -1;
}
