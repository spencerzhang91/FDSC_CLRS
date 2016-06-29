/* LSDsort_poker.c */
/* Use LSDsort to sort cards. This algorithm is actually aimed at
sorting the sturct with multiple fields
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMP(x,y) ((x)==(y))
#define SYMBOL_PART 2  // a card has graphic and numeric fields
#define SUIT 4         // four suits
#define FACE 13        // A2345678910JQK
#define SIZE 8         // card number in hand

enum suit {S, H, C, D, X=10, J=11, Q=12, K=13};
char S_str[4] = "SHCD";
char F_str[14] = "0123456789XJQK";
typedef struct card_node *Card;
struct card_node {
    int suit;
    int face;
    Card next;
};

Card radix_sort(Card ptr);
Card convert(char (*poker)[2], int len);
char **reconvert(Card ptr, int len);
void display_list(Card ptr);
void display_card(char (*poker)[2], int len);

int main(void)
{
    char poker[SIZE][2] = {"SX","D9","C2","C1","HK","S4","D8","H3"};
    display_card(poker, SIZE);
    Card pokerface = convert(poker, SIZE);
    display_list(pokerface);

    return 0;
}
Card radix_sort(Card ptr)
{
    // to be done
}

Card convert(char (*poker)[2], int len)
{
    Card head = (Card)malloc(sizeof(struct card_node));
    char head_s = poker[0][0];
    char head_f = poker[0][1];
    for (int i = S; i <= D; i++)
        if (CMP(head_s, S_str[i]))
        {
            head->suit = i;
            break;
        }
    for (int j = 0; j <= K; j++)
        if (CMP(head_f, F_str[j]))
        {
            head->face = j;
            break;
        }
    //printf("%c %c\n", head_s, head_f);
    //printf("%d %d\n", head->suit, head->face);
    Card curr = head;
    for (int k = 1; k < len; k++)
    {
        Card temp = (Card)malloc(sizeof(struct card_node));
        char temp_s = poker[k][0];
        char temp_f = poker[k][1];
        for (int ki = S; ki <= D; ki++)
            if (CMP(temp_s, S_str[ki]))
            {
                temp->suit = ki;
                break;
            }
        for (int kj = 0; kj <= K; kj++)
            if (CMP(temp_f, F_str[kj]))
            {
                temp->face = kj;
                break;
            }
        //printf("%c %c\n", temp_s, temp_f);
        //printf("%d %d\n", temp->suit, temp->face);
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
    }
    return head;
}
char **reconvert(Card ptr, int len)
{
    // to be done
}


void display_list(Card ptr)
{
    while (ptr)
    {
        printf("%c%c ",S_str[ptr->suit], F_str[ptr->face]);
        ptr = ptr->next;
    }
    puts("");
}

void display_card(char (*poker)[2], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%c", poker[i][j]);
        printf(" ");
    }
    puts("");
}