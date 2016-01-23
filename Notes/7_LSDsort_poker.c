/* LSDsort_poker.c */
/* Use LSDsort to sort cards */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SYMBOL_PART 2  // a card has graphic and numeric fields
#define SUIT 4         // four suits
#define FACE 13        // A2345678910JQK
#define SIZE 8        // card number in hand

enum suit {S, H, C, D, X=10, J=11, Q=12, K=13};
typedef struct card_node *Card;
struct card_node {
    int suit[SUIT];
    int face[FACE];
    Card next;
};

Card radix_sort(Card ptr);
void display_list(Card ptr);
void display_card(char (*poker)[2], int len);

int main(void)
{
    char poker[SIZE][2] = {"SX","D9","C2","C1","HK","S4","D8","H3"};
    display_card(poker, SIZE);

    return 0;
}

void display_card(char poker[][2], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%c", poker[i][j]);
        printf(" ");
    }
    puts("");
}