/* Excercise 2.3.1.c */
#include <stdio.h>
#define MAXTERMS 20

typedef struct {
    float coef;
    int expon;
} polynomial;

void readpoly(polynomial *terms);                       // function create polynomial
void printpoly(polynomial *terms);                      // function prints polynomial

int main(void)
{
    polynomial p1[MAXTERMS];
    readpoly(p1);
    printpoly(p1);
    
    return 0;
}

void readpoly(polynomial *terms)
{
    int i = 0;
    float coef;
    int expon;
    printf("Please enter polynomial coefs and exponents,");
    printf(" maximum term size is set to %d.\n", MAXTERMS);
    printf("Enter 'q' to quit.\n");
    while ((scanf("%f %d", &coef, &expon) == 2) && i <= MAXTERMS)
    {
        terms[i].coef = coef;
        terms[i].expon = expon;
        i++;
    }
    if (i == MAXTERMS)
        printf("Max term size reached.\n");
    printf("Done.\n");
}

void printpoly(polynomial *terms)
{
    for (int i = 0; i <= MAXTERMS; i++)
            printf("%.2f*X^%d + ", terms[i].coef, terms[i].expon);
}

