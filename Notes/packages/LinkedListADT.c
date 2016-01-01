/* Linked list ADT , modulize later */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define datatype int
typedef struct node *Linked;
struct node {
    datatype key;
    Linked next;
};

Linked create(datatype value);
