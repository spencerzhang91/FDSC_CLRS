/* code list 2-13 & 2-14 (page 57 -58)*/
/* The KMP algorithm conceived by Knuth, Morris and Pratt */
#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

int pmatch(char *string, char *pat);
void fail(char *pat);

int failure[MAX_PATTERN_SIZE];
char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];

int main(void)
{
    char string[] = "abcabcde";
    char pat[] = "abcd";
    fail(pat);                                              // calculate failure funtion
    printf("The matching result is %d\n",
            pmatch(string, pat));
    
    return 0;
}

int pmatch(char *string, char *pat)
{
    /* Knuth, Morris & Pratt string matching algorithm */
    int i = 0, j = 0;
    int lens = strlen(string);
    int lenp = strlen(pat);
    while (i < lens && j < lenp)
    {
        if (string[i] == pat[j])                            // pattern and string matchs so far
        {
            i++;
            j++;
        }
        else if (j == 0)                                    // not matching the pattern but haven't 
            i++;                                            // come to end of string yet
        else                                                // have come to the end of string, not match
            j = failure[j-1]+1;
    }
    return (j == lenp)? (i-lenp): -1;
}

void fail(char *pat)                                        // the failure funtion of a pattern is decided by
{                                                           // pattern itself
    /* compute the pattern's failure funtion */
    int n = strlen(pat);
    int i;
    failure[0] = -1;
    for (int j = 1; j < n; j++)
    {
        i = failure[j-1];
        while ((pat[j] != pat[i+1]) && (i >= 0))
            i = failure[i];
        if (pat[j] == pat[i+1])
            failure[j] = i + 1;
        else
            failure[j] = -1;
    }
}

