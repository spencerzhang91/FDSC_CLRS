// excercise of chapter 7 on P206
#include <stdio.h>
#define SIZE 5
typedef struct {
    int key;
    // any other possible fields
} element;

void swapsort(element list[], int len, int target);

int main(void)
{
    element list[SIZE] = {{5},{3},{2},{6},{1}};
    printf("first element before search: %d\n", list[0].key);
    swapsort(list, 5, 3);
    printf("first element after search: %d\n", list[0].key);

    return 0;
}

void movesort(element list[], int len, int target)
{
    
}