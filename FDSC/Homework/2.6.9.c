/* Homework excercise 2.6.9 (page59) */
/* 2.6.9.c */
#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 10

void fail(char *pat, int *failure);
void showfailure(int *failure, int patlen);

int main(void)
{
    int failure[MAX_PATTERN_SIZE];
    char p1[] = "aaaab";
    int l1 = strlen(p1);
    fail(p1, failure);
    showfailure(failure, l1);
    
    char p2[] = "ababaa";
    int l2 = strlen(p2);
    fail(p2, failure);
    showfailure(failure, l2);
    
    char p3[] = "abaabaab";
    int l3 = strlen(p3);
    fail(p3, failure);
    showfailure(failure, l3);
    
    return 0;
}

void fail(char *pat, int *failure)
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

void showfailure(int *failure, int patlen)
{
    for (int i = 0; i < patlen; i++)
        printf("%d ", failure[i]);
    putchar('\n');
}
