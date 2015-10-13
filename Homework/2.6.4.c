/* Excercise 2.6.4.c */
#include <stdio.h>
#include <string.h>

int strpos1(char *string, char ch);

int main(void)
{
    int pos;
    char string[10] = "abcabcabcd";
    char ch = 'c';
    pos = strpos1(string, ch);
    printf("%c is first appeared in %s at position %d.\n",
            ch, string, pos);
    return 0;
}

int strpos1(char *string, char ch)
{
    for (int i = 0; string[i] != '\0'; i++)
        if (string[i] == ch)
            return i;
    return -1;
}
