#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void strndel(char *string, int start, int len);

int main(void)
{
    char string[10] = "abcdefghij";
    strndel(string, 3, 3);
    printf("%s", string);
    
    return 0;
}

void strndel(char *string, int start, int len)
{
    int i = 0;
    while (string[i] != '\0')
        i++;
    char temp[i-len+1];
    if (start > 0)
    {
        strncpy(temp, string, start);
        strcat(temp, string+start+len);
        strcpy(string, temp);
    }
    else if (start == 0)
    {
        strcpy(temp, string + len);
        strcpy(string, temp);
    }
}
