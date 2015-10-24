/* Excercise 1.3.2: Implementation of a set */
#include <stdio.h>
#define ElementType int
#define MAXNUM 100;

typedef struct {
	ElementType *data;
	int currentnum;
} Set;

ElementType Create(int len);
void Insert(Set dataset, ElementType ele);
void Remove(Set dataset);
bool Is_In(Set dataset, ElementType ele);
void Uniont(Set database1, Set database2);
void Inerception(Set database1, Set database1);
void Difference(Set database1, Set database2);

int main(void)
{
	return 0;
}



