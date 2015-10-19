/* Excercise 2.6.5.c */
#include <stdio.h>
#include <string.h>

char *strch1(char *string, char ch);

int main(void)
{
	char *string = "abcdefg";
	char ch = 'c';
	char *ptrc;
	ptrc = strch1(string, ch);
	printf("%s", ptrc);
	
	return 0;
}

char *strch1(char *string, char ch)
{
    int str_len = 0;
    while (string != '\0')
    {
    	string++;
    	if (*string == ch)
    		return string;
    }
    return NULL;    
}
