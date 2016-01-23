/* 7-15_LSDsort.c */
/* The original implementation from FDSC book */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DIGIT 3 // number between 0 to 999
#define RADIX_SIZE 10
#define LENGTH 10

typedef struct list_node *list_pointer;
struct list_node {
    int key[MAX_DIGIT];
    list_pointer link;
};

list_pointer radix_sort(list_pointer ptr);
list_pointer convert2list(int *array, int len);
int *convert2array(list_pointer list);
void display(int *array, int len);

int main(void)
{
    int array[LENGTH] = {179,208,306,93,859,984,55,9,271,33};
    list_pointer list = convert2list(array, LENGTH);
    list = radix_sort(list);
    int *new_array = convert2array(list);
    display(array, LENGTH);
    display(new_array, LENGTH);
    return 0;
}

list_pointer radix_sort(list_pointer ptr)
{
    // radix sort using a linked list
    puts("B");
    list_pointer front[RADIX_SIZE], rear[RADIX_SIZE];
    int i, j, digit;
    for (i = MAX_DIGIT-1; i >= 0; i--)
    {
        for (j = 0; j < RADIX_SIZE; j++)
            front[j] = rear[j] = NULL;
        while (ptr)
        {
            digit = ptr->key[i];
            if (!front[digit])
                front[digit] = ptr;
            else
                rear[digit]->link = ptr;
            rear[digit] = ptr;
            ptr = ptr->link;
        }
        /* reestablish the linked list for the next pass */
        ptr = NULL;
        puts("A");
        for (j = RADIX_SIZE-1; j >= 0; j--)
            if (front[j])
            {
                rear[j]->link = ptr;
                ptr = front[j];
            }
    }
    return ptr;
}

list_pointer convert2list(int *array, int len)
{
    if (len <= 0)
        return NULL;
    list_pointer curr;
    list_pointer head = (list_pointer)malloc(sizeof(struct list_node));
    for (int i = 0; i < MAX_DIGIT; i++)
        head->key[i] = array[0] / pow(RADIX_SIZE, MAX_DIGIT-i-1);
    head->link = NULL;
    curr = head;
    for (int i = 1; i < len; i++)
    {
        list_pointer temp = (list_pointer)malloc(sizeof(struct list_node));
        for (int j = 0; j < MAX_DIGIT; j++)
            head->key[j] = array[i] / pow(RADIX_SIZE, MAX_DIGIT-j-1);
        temp->link = NULL;
        curr->link = temp;
        curr = temp;
    }
    return head;
}

int *convert2array(list_pointer list)
{
    // yet done
    int *temp = (int *)malloc(sizeof(int) * LENGTH);
    int i = 0;
    while (list && i < LENGTH)
    {
        int num = 0;
        for (int j = 0; j < MAX_DIGIT; j++)
            num += list->key[j] * (int)pow(10, MAX_DIGIT-j-1);
        temp[i] = num;
        list = list->link;
    }
    return temp;
}

void display(int *array, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    puts("");
}