// First excercise of chapter 7 on P205
#include <stdio.h>
#define SIZE 5
typedef struct {
    int key;
    // any other possible fields
} element;

void swapsearch(element list[], int len, int target);

int main(void)
{
    element list[SIZE] = {{5},{3},{2},{6},{1}};
    printf("first element before search: %d\n", list[0].key);
    swapsort(list, 5, 3);
    printf("first element after search: %d\n", list[0].key);

    return 0;
}

void swapsearch(element list[], int len, int target)
{
    int temp;
    for (int i = 0; i < len; i++)
        if (list[i].key == target)
        {
            temp = list[i].key;
            list[i].key = list[0].key;
            list[0].key = temp;
            printf("%d is found!\n", target);
            return i;
        }
    printf("%d is not found in the list.\n", target);
    return -1;
}