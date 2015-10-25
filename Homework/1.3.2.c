/* Excercise 1.3.2: Implementation of a set */
#include <stdio.h>
#define ElementType int
#define MAXNUM 100;

struct set{
	ElementType *data;
	int currentnum;
	int totoallen;
};

typedef set *Set;

Set Create(int len);
void Insert(Set dataset, ElementType ele);
void Remove(Set dataset, ElementType ele);
bool Is_In(Set dataset, ElementType ele);
Set Union(Set database1, Set database2);
Set Inerception(Set database1, Set database1);
Set Difference(Set database1, Set database2);

int main(void)
{
	return 0;
}

Set Create(int len)
{
	Set dataset = (Set)calloc(1, sizeof(Set));
	dataset->data = (ElementType *)calloc(len, sizeof(ElementType));
	dataset->currentnum = 0;
	dataset->totoallen = len;
	return dataset;
}

void Insert(Set dataset, ElementType ele)
{
	if (dataset->currentnum < dataset->totoallen)
		dataset->data[dataset->currentnum] = ele;
	else
		printf("The set is full.\n");
}

void Remove(Set dataset, ElementType ele)
{
	for (int i = 0; i < dataset->currentnum; i++)
	{
		if (dataset[i] == ele)
		{
			for (int j = i; j < dataset->currentnum -1; j++)
				dataset[j] = dataset[j+1];
			dataset[j] = NULL;
		}
	}
	printf("The element is not in the set.\n");
}

bool Is_In(Set dataset, ElementType ele)
{
	for (int i = 0; i < dataset->currentnum; i++)
		if (dataset[i] == ele)
			return true;
	return false;
}

Set Union(Set database1, Set database2)
{

}

Set Inerception(Set database1, Set database1)
{

}

Set Difference(Set database1, Set database2)
{

}

