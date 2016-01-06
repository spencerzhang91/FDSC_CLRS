// excercise 7.3.4 on P208
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 6
#define datatype int
typedef struct node *Linked;
struct node {
    datatype key;
    Linked next;
};

bool ascending(int x, int y);
bool descending(int x, int y);
Linked insertion_sort(Linked list, bool (*func)(int x, int y));

// basic operations of a linked list ADT
Linked create(datatype value);
Linked construct(datatype array[], int len);
void display(Linked head);

int main(void)
{
    Linked sortedhead;
    datatype list[SIZE] = {5, 3, 2, 6, 1, 8};
    Linked origin = construct(list, SIZE);
    display(origin);
    
    puts("befor sorting:");
    display(origin);

    puts("sort ascendingly:");
    sortedhead = insertion_sort(origin, ascending);
    display(sortedhead);

    puts("sort descendingly:");
    sortedhead = insertion_sort(origin, descending);
    display(sortedhead);

    return 0;
}

bool ascending(int x, int y)
{
    return (x < y);
}

bool descending(int x, int y)
{
    return (x > y);
}

Linked insertion_sort(Linked list, bool (*func)(int x, int y)) // to be done
{
    /* This function use the approach of create a new list rather than swap
    order in place: which aquire three pointers and have sophisticated boundry
    conditions. */
    Linked curr = list->next;
    Linked newhead = create(list->key);
    while (curr)
    {
        
    }
}

Linked create(datatype value)
{
    // create a Linked list node
    Linked head = (Linked)malloc(sizeof(struct node));
    if (head)
    {
        head->next = NULL;
        head->key = value;
    }
    else
    {
        fprintf(stderr, "%s\n", "Fail to create list, full memory.");
        exit(EXIT_FAILURE);
    }
    return head;
}

Linked construct(datatype array[], int len)
{
    Linked head = create(array[0]);
    Linked curr = head;
    for (int i = 1; i < len; i++)
    {
        Linked temp = create(array[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void display(Linked head)
{
    Linked temp = head;
    while (temp)
    {
        printf("%d ", temp->key); // only if datatype == int
        temp = temp->next;
    }
    puts(""); 
}