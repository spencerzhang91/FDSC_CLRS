/* How to calculate a pattern string's failure function ? */
/* pattern_fail.c */
#include <stdio.h>
#include <string.h>
void fail(char *pattern, int *fa, int plen);

int main(void)
{
    char *pat = "abcabca";
    int pat_length = strlen(pat);
    int failure_array[pat_length];
    
    fail(pat, failure_array, pat_length);
    for (int i = 0; i < pat_length; i++)
        printf("%d ", failure_array[i]);
    printf("\n");
    
    return 0;
}

void fail(char *pattern, int *fa, int plen)
{
    int i;                                                              // declare tracer i
    fa[0] = -1;                                                         // first is always -1 (if unmatch)
    for (int j = 1; j < plen; j++)                                      // scan through pattern string
    {
        i = fa[j-1];                                                    // initialize i as -1                                                
        while ((pattern[j] != pattern[i+1]) && i >= 0)                  // loop condition: 
            i = fa[i];
        if (pattern[j] == pattern[i+1])
            fa[j] = i + 1;
        else
            fa[j] = -1;
    }
}
