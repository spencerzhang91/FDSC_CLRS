/* function to fast transpose a matrix */
/* code list 2-8 */
#include <stdio.h>
#define MAX 100
#define N 5

typedef struct {
	int col;
	int row;
	int val;
} term;

void fast_transpose(term a[], term b[]);
int main(void)
{
	term a[N] = {{2,2,1},{0,1,2}};
	term b[N];
	fast_transpose(a, b);
	
	//for (int i = 0; i < N; i++)
		//if (a[i].val)
			//printf("row: %d  col: %d -> val: %d\n", b[i].row, b[i].col, b[i].val);
	
	return 0;
}

void fast_transpose(term a[], term b[])
{													// fast transepose matrix a into matrix b
	int row_terms[MAX], starting_pos[MAX];
	int i, j;
	int num_cols = a[0].col; 						// total colums of matrix a
	int num_terms = a[0].val; 						// total number of non-zero elements of matrix a
	b[0].row = num_cols; 							// b's row number equal to a's col number
	b[0].col = a[0].row; 							// b's col number equal to a's row number
	b[0].val = num_terms; 							// the total non-zero number remains the same
	if (num_terms > 0) 								// if the matrix is a non-zero matrix:
	{
		for (i = 0; i < num_cols; i++)
			row_terms[i] = 0;
		for (i = 1; i < num_terms; i++)
			row_terms[a[i].col]++;
		starting_pos[0] = 1;
		for (i = 1; i < num_cols; i++)
			starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
		for (i = 1; i <= num_terms; i++)
		{
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].val = a[i].val;
		}
	}
}

