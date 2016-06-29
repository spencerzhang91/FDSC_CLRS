/* code list 2-11 string insertion fucntion */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
void strnins(char *s, char *t, int i);

int main(void)                                  // test main function
{
    char s1[] = "Autic";
    char s2[] = "toma";
    strnins(s1, s2, 2);
    printf("%s", s1);
    
    return 0;
}

void strnins(char *s, char *t, int i)           // insert t into s at position i
{
    char string[MAX];
    char *temp = string;
    if (i < 0 || i > strlen(s))
    {
        fprintf(stderr, "Position is out of bound.\n");
        exit(1);
    }
    if (strlen(s) == 0)
        strcpy(s, t);
    else if (strlen(t))
    {
        strncpy(temp, s, i);                    // copy first i chars of s into temp
        strcat(temp, t);                        // concatenate temp(first ith s) and t
        strcat(temp, (s + i));                  // here s is a pointer
        strcpy(s, temp);                        // use temp to override origin s
    }
}
