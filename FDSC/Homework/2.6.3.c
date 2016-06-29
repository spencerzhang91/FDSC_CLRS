/* Exercise 2.6.3.c */
#include <stdio.h>
#include <string.h>

void strpol1(char *string, char ch);

int main(void)
{
    char string[10] = "abcdeabcde";
    strpol1(string, 'c');
    printf("%s", string);
    
    return 0;
}

void strpol1(char *string, char ch)
{
    int len = 0;
    while (string[len] != '\0')
        len++;
    char temp[len];
    char *pos = strchr(string, ch);
    int n = pos - string;
    strncpy(temp, string, n);
    strcat(temp, string+n+1);
    strcpy(string, temp);
}
