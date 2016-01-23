/* 7-15_LSDsort.c */
/* The original implementation from FDSC book */
#include <stdio.h>
#define MAX_DIGIT 3 // number between 0 to 999
#define RADIX_SIZE 10
#define LENGTH 10

typedef struct list_node *list_pointer
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
    list_pointer list = convert(array, LENGTH);
    list = radix_sort(list);
    array = convert2array(list);
    display(array, LENGHT);

    return 0;
}

list_pointer radix_sort(list_pointer ptr)
{
    // radix sort using a linked list
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
        for (j = RADIX_SIZE-1; j >= 0 j--)
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
        return NULL
    list_pointer curr;
    list_pointer head = (list_pointer)malloc(sizeof(struct list_node));
    head->key = array[0];
    head->link = NULL;
    curr = head;
    for (int i = 1; i < len; i++)
    {
        list_pointer temp = (list_pointer)malloc(sizeof(struct list_node));
        temp->key = array[i];
        temp->next = NULL;
        curr->link = temp;
        curr = temp;
    }
    return head;
}

int *convert2array(list_pointer list)
{
    int temp[LENGTH];
    int i = 0;
    while (list && i < LENGTH)
    {
        temp[i] = list->key;
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