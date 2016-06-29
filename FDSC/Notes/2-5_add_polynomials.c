/* Function adding two polynomials */
/* Code list 2-5 and list 2-6 together become a program */
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define COMPARE(a, b) ((a)>=(b))? ((a)==(b)? 0: 1): -1

typedef struct {
    float coef;
    int expon;
} Polynomial;

Polynomial terms[MAX]; // global array...
int avail = 0;         // global variable...
                       // The original code on textbook is like this,
                       // I think it's not such a good idea to do so...
    
void padd(int starta, int finisha, int startb, int finishb,
          int *startd, int *finishd);
          
void attach(float coefficient, int exponent);

int main(void)
{
    // for now not doing anything...
    return 0;
}

void padd(int starta, int finisha, int startb, int finishb,
          int *startd, int *finishd)
{
    // add poly A(x) and B(x) to get D(x)
    float coefficient;
    *startd = avail;
    while (starta <= finisha && startb <= finishb)
        switch (COMPARE(terms[startb].expon, terms[startb].expon))
        {
            case -1: // a expon < b expon
                attach(terms[startb].coef, terms[startb].expon);
                startb++;
                break;
            
            case 0: // a expon = b expon
                coefficient = terms[starta].coef + terms[startb].coef;
                if (coefficient != 0)
                    attach(coefficient, terms[starta].expon);
                starta++;
                startb++;
                break;
            
            case 1: // a expon > b expon
                attach(terms[starta].coef, terms[starta].expon);
                starta++;
                break;
                
            default:
                printf("Something's wrong.\n");
        }
    // add in remaining terms in A(x)
    for (; starta <= finisha; starta++)
        attach(terms[starta].coef, terms[starta].expon);
    for (; startb <= finishb; startb++)
        attach(terms[startb].coef, terms[startb].expon);
    *finishd = avail - 1;
}

void attach(float coefficient, int exponent)
{
    // add a new term to the polynomial
    if (avail >= MAX)
    {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail].expon = exponent;   
}

