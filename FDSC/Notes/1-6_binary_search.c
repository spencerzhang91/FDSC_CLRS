/* binary search algorithm */
/* code list 1-6 */
#include <stdio.h>
#define COMPARE(x, y) ((x) < (y)? -1: ((x) == (y))? 0: 1)
int binsearch(int list[], int target, int left, int right);

int main(void)
{
    int list[9] = {1,2,3,4,5,6,7,8,9};
    int target = 14;
    printf("%s.\n", binsearch(list, target, 0, 8) < 0? "Not found": "Found");
    return 0;
}

int binsearch(int list[], int target, int left, int right)
{
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        switch (COMPARE(list[middle], target))
        {
            case -1: left = middle + 1;
                     break;
            case 0: return middle;
            case 1: right = middle - 1;
        }
    }
    return -1;
}
