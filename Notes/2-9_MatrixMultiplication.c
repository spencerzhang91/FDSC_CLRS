/* code list 2-9 sparse matrix multiplication */
#define MAX 10
#include <stdio.h>

typedef struct {                                                        // The same struct definition as 2-7
	int col;
	int row;
	int val;
} term;

void mmult(term a[], term b[], term d[]);
void fast_transpose(term a[], term b[]);                                // Function from code list 2-8 as a helper funtion

int main(void)
{
    return 0;
}

void mmult(term a[], term b[], term d[])                                // Multiply two sparse matrices
{
    int i, j, column, totald = 0;
    int rows_a = a[0].row, cols_a = a[0].col, totala = a[0].val;        // Properties of matrix a
    int rows_b = b[0].row, cols_b = b[0].col, totalb = b[0].val;        // Properties of matrix b
    int row_begin = 1, row = a[1].row, sum = 0;                         // row_begin: first element of current row
    int new_b[MAX][3];                                                  // Matrix b after transpose
    if (cols_a != b[0].row)                                             // Invalid multiplication
    {
        fprintf(stderr, "Incompatible matrices\n");
        exit(1);
    }
    fast_transpose(b, new_b);                                           // transpose second matrix(b) for multiplication
    /* set boundary condition */
    a[totala+1].row = rows_a;
    new_b[totalb+1].row = cols_b;
    new_b[totalb+1].col = 0;
    for (i =1; i <= totala;)
    {
        column = new_b[1].row;
        for (j = 1; j <= totalb+1;)
        {
           /* multiply row of a by column of b */
            if (a[i].row != row)
            {
                storesum(d, &totald, row, column, &sum);
                i = row_begin;
                for (; new_b[j].row == colunm; j++)
                    continue;
                column = new_b[j].row;
            }
            else if (new_b[j].row != column)
            {
                storesum(d, &totald, row, column, &sum);
                i = row_begin;
                column = new_b[j].row;
            }
            else switch (COMPARE(a[i].col, new_b[j].col))
            {
                case -1:                                                    // go to next term in a
                    i++; break;
                case 0:                                                     // add terms, go to next term in a and b
                    sum += (a[i++].val * new_b[j++].val);
                    break;
                case 1:                                                     // advance to next term in b
                    j++;
            } 
        }
        for (; a[i].row == row; i++)
            continue;
        row_begin = i;
        row = a[i].row;
    }
    d[0].row = rows_a;
    d[0].col = cols_b;
    d[0].val = totald;
}
