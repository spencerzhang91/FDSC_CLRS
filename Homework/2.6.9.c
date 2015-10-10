/* Homework excercise 2.6.9 (page59) */
/* 2.6.9.c */
#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

char *fail(char *pat);
void showfailure(char *failure);

int main(void)
{
    char p1[] = "aaab";
    char p2[] = "ababaa";
    char p3[] = "abaabaab";
    
    return 0;
}

void fail(char *pat)
{
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

