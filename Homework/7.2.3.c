// excercise 7.2.3 on P208
#include<stdio.h>
#include<stdbool.h>
#define SIZE 5
typedef struct element element;
typedef *element link;
struct element{
    int key;
    link next;
};