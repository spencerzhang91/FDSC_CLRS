/* 1.2.3.c */
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100

void truth_table(int n);

int main(void)
{
   int n;
   printf("Enter n(>=0): ");
   scanf("%d", &n);
   
   while (n <= 0) 
   {
     printf("Enter n(>=0): ");
     scanf("%d", &n);
   }
   truth_table(n);
}

void truth_table(int n)
{
	int row, col, div, rem;
	char string[MAX];
	for (row = 0; row < pow(2,n); row++)
	{
        strcpy(string ,"\0");
        div = row;
	    for (col = n; col > 0; col--)
	    {
	        rem = div%2;
	        div = div/2;
		    if (!rem)
                strcat(string, "FALSE ");
		    else
                strcat(string, "TRUE  ");
        }
	    printf("%s\n", string);
    }	 
}
