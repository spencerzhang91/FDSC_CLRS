// code list 7-2: binary search
#include <stdio.h>
#define MAXSIZE 1000 // maximum item number plus one
#define COMPARE(x, y) ((x) > (y))? -1: (((x) == (y))? 0: 1)
typedef struct {
    int key;
    /* other fields */
} element;

element list[MAXSIZE] = {{1},{2},{3},{4},{5},{6},{7},{8}};

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

int main(void)
{
    int res = binsearch(list, 45, 8);
    printf("The result is %d\n", res);

    return 0;
}
