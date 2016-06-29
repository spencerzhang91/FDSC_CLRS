/* Excercise 4.3.1.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char *s);

int main(void)
{
    char s[10] = "abcdedcba";
    if (isPalindrome(s))
        printf("IS PALINDROME!\n");
    else
        printf("No way!\n");
    
    return 0;
}

bool isPalindrome(char *s)
{
	if(s==NULL || !strcmp(s,""))
		return true;

	for(char* p = s + strlen(s) -1; p>s;)
		if(isalnum(*s) && isalnum(*p) &&
            tolower(*(s++)) != tolower(*(p--)))
			return false;
    	else if(!isalnum(*s))
    		s++;
    	else if(!isalnum(*p))
    		p--;
    return true;
}
