/* page 9 --1.2.4.c */
/* sort three number using recursion */
#include <stdio.h>
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp))
void sort(int x, int y, int z);

int main(void)
{
    int x = 31, y = 12, z = 13;
    sort(x, y, z);
    return 0;
}

void sort(int x, int y, int z)
{
    int temp;
    if (x <= y && y <= z)
    {
        printf("%d %d %d", x, y, z);
        return;
    }
    else
    {
        if (x > y)
        {
            SWAP(x, y, temp);
            sort(x, y, z);
        }
        else if (y > z)
        {
            SWAP(y, z, temp);
            sort(x, y, z);
        }    
    }     
}

