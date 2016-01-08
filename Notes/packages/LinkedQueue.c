/* Linked list based Queue ADT implementation */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedQueue.h"

Queue CreateQueue(int maxsize)
{
    /* This function initialize an empty queue by taking in the queue size
    and the return a pointer pointing to a queue node. */
    Queue temp = (Queue)malloc(sizeof(struct Qnode));
    temp->front = temp->rear = NULL;
    temp->maxsize = maxsize;
    temp->cursize = 0;
    return temp;
}

Queue ConstructQ(ElementType array[], int size)
{
    Queue temp = CreateQueue(size);
    for (int i = 0; i < size; i++)
        enqueue(temp, array[i]);
    return temp;
}

bool QIsFull(Queue Q)
{
    return Q->cursize == Q->maxsize;
}

bool QIsEmpty(Queue Q)
{
    return Q->front == NULL;
}

void enqueue(Queue Q, ElementType item)
{
    Node rearcell;
    ElementType rearelem = item;
    if (QIsFull(Q))
    {
        printf("The queue is Full.\n");
        exit(1);
    }   
    else
    {
        rearcell = (Node)malloc(sizeof(struct qnode));
        rearcell->data = rearelem;
        rearcell->next = NULL;
        if (Q->cursize == 0)
            Q->front = Q->rear = rearcell;
        else
        {
            Q->rear->next = rearcell;
            Q->rear = Q->rear->next;
        }    
        ++Q->cursize;
    }
}

ElementType dequeue(Queue Q)
{
    Node frontcell;
    ElementType frontelem;
    if (QIsEmpty(Q))
    {
        printf("During dequeue the queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        frontcell = Q->front;
        frontelem = frontcell->data;
        if (Q->front == Q->rear)
            Q->front = Q->rear = NULL;
        else
            Q->front = Q->front->next;
        free(frontcell);
        --Q->cursize;
        return frontelem;
    }
}

ElementType first(Queue Q)
{
    /* Returns the first element in the queue(first to out), without
     deleting it */
    Node frontcell;
    ElementType frontelem;
    if (QIsEmpty(Q))
    {
        printf("During peeking first element the queue is empty.\n");
        exit(EXIT_FAILURE); 
    }
    else
    {
        frontcell = Q->front;
        frontelem = frontcell->data;
        return frontelem;
    }
}

int len(Queue Q)
{
    return Q->cursize;
}

void displayQ(Queue Q)
{
    Node temp = Q->front;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}
