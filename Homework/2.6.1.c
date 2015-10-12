/* Excercise 2.6.1.c */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 128

typedef struct {
    char character;
    int frequency;
} charcount;

void count(char *string, int len);
bool instr(char *string, char ch);

int main(void)
{
    char *chars = "To be or not to be, it's a question.";
    int len = strlen(chars);
    count(chars, len);
    return 0;
}

void count(char *string, int len)
{
    if (len > 0)
    {
       char temp[MAX] = "";
        temp[0] = string[0];
        int uniqe = 1;
        for (int i = 1; i < len; i++)
        {
            if (instr(temp, string[i]))
                continue;
            else
        } 
    }
    
}

bool instr(char *string, char ch)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == ch)
            return true;
        i++;
    }    
    return false;
}
