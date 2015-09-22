/* recursive permutation algorithm */
#include <stdio.h>
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp))

void perm(char *list, int i, int n);
int main(void)
{
    char list[4] = {'a', 'b', 'c', 'd'};
    perm(list, 0, 3);
    
    return 0;
}

void perm(char *list, int i, int n)
{
    int j, temp;
    if (i == n)
    {
        for (j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("  ");
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            SWAP(list[i], list[j], temp);  
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}
