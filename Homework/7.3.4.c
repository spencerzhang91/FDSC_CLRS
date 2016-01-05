// excercise 7.3.4 on P208
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 6
typedef struct node *Linked;
struct node {
    datatype key;
    Linked next;
};

bool ascending(int x, int y);
bool descending(int x, int y);
void showLinkedList(Linked head);
Linked insertion_sort(Linked list, int n, bool (*func)(int x, int y));

// basic operations of a linked list ADT
Linked create(datatype value);
Linked construct(datatype array[], int len);
void destruct(Linked head, int len);
void insert(Linked head, datatype item, int len, int pos);
void delitem(Linked head, datatype item);
void display(Linked head);
int length(Linked head);

int main(void)
{
    Linked sortedhead;
    element list[SIZE] = {{5},{3},{2},{6},{1},{8}};
    puts("befor sorting:");
    showLinkedList(list);

    puts("sort ascendingly:");
    sortedhead = insertion_sort(list, SIZE, ascending);
    showLinkedList(list);

    puts("sort descendingly:");
    sortedhead = insertion_sort(list, SIZE, descending);
    showLinkedList(list);

    return 0;
}

void showlist(element *list, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", list[i].key);
    puts("");
}

bool ascending(int x, int y)
{
    return (x < y);
}

bool descending(int x, int y)
{
    return (x > y);
}

link insertion_sort(link list, int n, bool (*func)(int x, int y)) // to be done
{

}

void showLinkedList(link head)
{
    for (; head; head = head->next)
        printf("%d ", head->key);
    puts("");
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
        printf("Invalide insert position.\n");
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
    // if the item is successfully deleted return true, else false
    Linked temp = head;
    if (head->key == item)
    {
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
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

int length(Linked head)
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