/* How to calculate a pattern string's failure function ? */
/* pattern_fail.c */
#include <stdio.h>
#include <string.h>
void fail(char *pattern, int *fa, int plen);

int main(void)                                                          // test function
{
    char *pat = "ababacabab";
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
        while ((pattern[j] != pattern[i+1]) && i >= 0)                  // the first condition means no duplicated char appered yet
                                                                        // the second condition means  
            i = fa[i];
        if (pattern[j] == pattern[i+1])                                 // means duplicated char in pattern appeared in "right place"
            fa[j] = i + 1;                                              // if duplicated char appeared, fa[j] = i + 1; i can be accumulated
        else
            fa[j] = -1;                                                 // or, not in "right place"(or not appeared), reset i to -1 then put
    }                                                                   // this i into jth of fa
}
