/* code list 2-12: a similiar funtion of strstr() */
#include <stdio.h>
#include <string.h>
int nfind(char *string, char *pat);

int main(void)
{
    char *s = "abbaccadd";
    char *pattern = "bac";
    int res = nfind(s, pattern);
    printf("%d\n", res);
    
    return 0;
}

int nfind(char *string, char *pat)
{
    /* match the last character of pattern first,
    and then match from the beginning */
    int start = 0;
    int i, j;
    int lasts = strlen(string) - 1;                                 // last char of string
    int lastp = strlen(pat) - 1;                                    // last char of pattern
    int endmatch = lastp;
    
    for (i = 0; endmatch <= lasts; endmatch++, start++)
    {
        if (string[endmatch] == pat[lastp])
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++)
                continue;
        if (j == lastp)
            return start;                                           // successful
    }
    return -1;                                                      // mismatch
}
