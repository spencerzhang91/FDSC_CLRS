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
void destruct(Linked head, int len);
void insert(Linked head, datatype item, int len, int pos);
void delitem(Linked head, datatype item);
void display(Linked head);
int len(Linked head);

int main(void)
{
    Linked sortedhead;
    datatype list[SIZE] = {5, 3, 2, 6, 1, 8};
    Linked origin = construct(list, SIZE);
    delitem(origin, 2);
    display(origin);
    delitem(origin, 5);
    display(origin);
    /*
    puts("befor sorting:");
    display(origin);

    puts("sort ascendingly:");
    sortedhead = insertion_sort(origin, ascending);
    display(sortedhead);

    puts("sort descendingly:");
    sortedhead = insertion_sort(origin, descending);
    display(sortedhead);
    */
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
    /* perform a insertion sort on the linked list. Actually here's a little bit
    detoured here, in order to use ADT functions only. */
    int length = len(list);
    if (length <= 1)
        return list;
    Linked newhead = create(list->key);
    Linked curr = list->next;
    
    return newhead;
}

// definition of linked list functions
Linked create(datatype value)
{
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

void destruct(Linked head, int len)
{
    Linked temp = head;
    Linked curr = temp->next;
    while (curr)
    {
        free(temp);
        temp = curr;
        curr = temp->next;
    }
}

void insert(Linked head, datatype item, int len, int pos)
{
    // here pos is where new item will attach after
    if (pos > len || pos < -1)
    {
        printf("Invalide insert position: %d.\n", pos);
        exit(EXIT_FAILURE);
    }
    Linked temp = head;
    Linked newnode = create(item);
    int marker = -1; // -1 is to add newnode as new head
    for (; marker < pos; marker++)
        temp = temp->next;
    if (marker == -1)
    {
        newnode->next = temp;
        head = newnode;
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delitem(Linked head, datatype item)
{
    // delete the requested item(if any)
    Linked temp = head;
    if (head->key == item)
    {
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        while (temp->next)
        {
            if (temp->next->key == item)
                break;
            else
                temp = temp->next;
        }
        Linked drop = temp->next;
        temp->next = temp->next->next;
        drop->next = NULL;
        free(drop);
    }
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

int len(Linked head)
{
    int count = 0;
    Linked temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}