/* Excercise 1.3.2: Implementation of a set ADT*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
#define MAXNUM 100;

struct set{
    ElementType *data;
    int currentnum;
    int volume;
};

typedef struct set *Set;

Set Create(int len);
void Insert(Set dataset, ElementType ele);
void Remove(Set dataset, ElementType ele);
bool Is_In(Set dataset, ElementType ele);
Set Union(Set dataset1, Set dataset2);
Set Inerception(Set dataset1, Set dataset2);
Set Difference(Set dataset1, Set dataset2);

int main(void)
{
    Set s1 = Create(10);
    Insert(s1, 10);
    bool x = Is_In(s1, 10);
    printf("%d", x);
    return 0;
}

Set Create(int len)
{
    Set dataset = (Set)calloc(1, sizeof(struct set));
    dataset->data = (ElementType *)calloc(len, sizeof(ElementType));
    dataset->currentnum = 0;
    dataset->volume = len;
    return dataset;
}

void Insert(Set dataset, ElementType ele)
{
    if (dataset->currentnum < dataset->volume && !Is_In(dataset, ele))
    {
        dataset->data[dataset->currentnum] = ele;
        dataset->currentnum++;
    }
    else
        printf("The set is full.\n");
}

void Remove(Set dataset, ElementType ele)
{
    int i, j;
    for (i = 0; i < dataset->currentnum; i++)
    {
        if (dataset->data[i] == ele)
        {
            for (j = i; j < dataset->currentnum -1; j++)
                dataset->data[j] = dataset->data[j+1];
            dataset->data[j] = '\0';
        }
    }
    printf("The element is not in the set.\n");
}

bool Is_In(Set dataset, ElementType ele)
{
    for (int i = 0; i < dataset->currentnum; i++)
        if (dataset->data[i] == ele)
            return true;
    return false;
}

Set Union(Set dataset1, Set dataset2)
{
    Set res = (Set)calloc(1, sizeof(struct set));
    res->data = (ElementType *)calloc(dataset1->volume + dataset2->volume,
                               sizeof(ElementType));

    for (int i = 0; i < dataset1->volume; i++)
        Insert(res, dataset1->data[i]);
    for (int j = 0; j < dataset2->volume; j++)
        if (!Is_In(res, dataset2->data[j]))
            Insert(res, dataset2->data[j]);
    return res;
}

Set Inerception(Set dataset1, Set dataset2)
{
    int size = (dataset1->volume >= dataset2->volume)? dataset1->volume: dataset2->volume;
    Set res = (Set)calloc(1, sizeof(struct set));
    res->data = (ElementType *)calloc(size, sizeof(ElementType));
    for (int i = 0; i < dataset1->volume; i++)
        if (Is_In(dataset2, dataset1->data[i]))
            Insert(res, dataset1->data[i]);
    return res;
}

Set Difference(Set dataset1, Set dataset2)
{
    /* returns a set that contains elements in dataset1 but not in dataset2 */
    Set res = (Set)calloc(1, sizeof(struct set));
    res->data = (ElementType *)calloc(dataset1->volume + dataset2->volume,
                               sizeof(ElementType));
    for (int i = 0; i < dataset1->volume; i++)
    	if (!Is_In(dataset2, dataset1->data[i]))
    		Insert(res, dataset1->data[i]);

    return res;
}
