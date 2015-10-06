/* function to transpose a matrix */
/* code list 2-7 */
#include <stdio.h>
#define MAX 100
#define N 5

typedef struct {
	int col;
	int row;
	int val;
} term;

void transpose(term a[], term b[]);
int main(void)
{
	term a[N] = {{2,2,1},{0,1,2}};
	term b[N];
	transpose(a, b);
	
	//for (int i = 0; i < N; i++)
		//if (a[i].val)
			//printf("row: %d  col: %d -> val: %d\n", b[i].row, b[i].col, b[i].val);
	
	return 0;
}

void transpose(term a[], term b[])
{
	int n, i, j, curb; 							// curb is current b
	n = a[0].val;               				// total elements
	b[0].row = a[0].col;          				// b's row == a's col
	b[0].col = a[0].row;          				// b's col == b's row
	b[0].val = n;               				// b's total elements == a's total elements
	
	if (n > 0)
	{
		curb = 1;
		for (i = 0; i < a[0].col; i++)			// transpose according to a's col (col by col)
			for (j = 0; j <= n; j++)				// for all elements...
				if (a[j].col == i) 				// if it is in a's current col
				{								// then transpose it into b's current row
					b[curb].row = a[j].col;
					b[curb].col = a[j].row;
					b[curb].val = a[j].val;
					printf("a::= row: %d  col: %d -> val: %d\n", a[j].row, a[j].col, a[j].val);
					printf("b::= row: %d  col: %d -> val: %d\n", b[curb].row, b[curb].col, b[curb].val);
					curb++;
				}
	}	
}
