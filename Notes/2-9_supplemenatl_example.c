/* write a spare matrix multiplication algorithm from scratch */
/* supplementary example for code list 2-9_MatrixMultiplication.c */
#include <stdio.h>

typedef struct {
    int row;
    int col;
    int val;
} element;

int main(void)
{
    element A[2] = {{2,3,1}, {1,1,1}};
    element B[3] = {{3,4,2}, {0,4,1}, {1,1,1}};
    printf("Matrix A's only non-zero element: %d\n", A[1].val);
    
    return 0;
}
