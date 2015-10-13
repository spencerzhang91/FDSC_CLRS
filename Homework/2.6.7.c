/* Excercise 2.6.7.c */
#include <stdio.h>
#include <string.h>
#define N 11									// string length
#define M 3										// pattern length

int strsearch(char *string, char *pattern);

int main(void)
{
	char words[N] = "acbddabcdac";
	char pattern[M] = "abc";
	int res;
	res = strsearch(words, pattern);
	printf("The result is %d.\n", res);

	return 0;
}

int strsearch(char *string, char *pattern)
{
	int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M;)
        {
            if (string[i+j] == pattern[j])
                j++;
            else
                break;	        
        }
        if (j == M)
            return i;
    }
    return -1;			
}
