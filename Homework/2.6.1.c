/* Excercise 2.6.1.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 128

typedef struct {
    char character;
    int frequency;
} charcount;

void count(char *string, int len);

int main(void)
{
    char *chars = "To be or not to be, it's a question.";
    int len = strlen(chars);
    count(chars, len);
    
    return 0;
}

void count(char *string, int len)
{
    char temp[(MAX > len)? len: MAX];
    temp[0] = string[0];

    for (int i = 1; i < len; i++)
    {
        ;
    }
}
