/* LSDsort_poker.c */
/* Use LSDsort to sort cards */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SYMBOL_PART 2  // a card has graphic and numeric fields
#define SUIT 4         // four suits
#define FACE 13        // A2345678910JQK

enum suit {spade, heart, club, diamond};
typedef struct card_node *Card;
struct card_node {
    int suit[SUIT];
    int face[FACE];
    Card next;
};

Card radix_sort(Card ptr);
void display(Card ptr);

int main(void)
{
    int number[4] = {10,20,30,40};
    printf("%d ", number[heart]);

    return 0;
}