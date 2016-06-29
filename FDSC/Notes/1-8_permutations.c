/* recursive permutation algorithm */
#include <stdio.h>
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp))

void perm(char *list, int i, int n);
int main(void)
{
    char list[3] = {'a', 'b', 'c'};
    perm(list, 0, 2);
    
    return 0;
}

void perm(char *list, int i, int n)
{
    int j, temp;
    if (i == n)
    {
        for (j = 0; j <= n; j++)
            printf("%c ", list[j]);
        printf("\n");
    }
    else
    {
        for (j = i; j <= n; j++)
        {
                                                    printf("#1 i = %d j = %d\n", i, j);
            SWAP(list[i], list[j], temp); 
                                                    printf("#2 i = %d j = %d\n", i, j);
            perm(list, i+1, n);
                                                    printf("#3 i = %d j = %d\n", i, j);
            SWAP(list[i], list[j], temp);
                                                    printf("#4 i = %d j = %d\n", i, j);
                                                    printf("\n");
        }
    }
}
