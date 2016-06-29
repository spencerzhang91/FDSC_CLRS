# simple matrix multiplication algorithm (none sparse matrix)
# as a supplementary code for 2-9_MatrixMultiplication.c

from 2-8_matrix_transpose_basic import transpose                # import transpose module

def mul_matrix(m1:list, m2:list)->list:
    '''
    Input of this function is two 2d list.
    Output is a 2d list. If the result is a number,
    then return [[num]].
    Assume both matrixs are well structured (row & col)
    '''
    if len(m1[0]) != len(m2):                               # verify valid multiplication
        print("Invalid multiplication attempted.")
        return None
    nrow = len(m1)                                          # row number of product
    ncol = len(m2[0])                                       # col number of product
    product = []
    temp = []
    s = 0
    m2 = transpose(m2)                                      # transpose for simplicity
    for rowm1 in m1:
        for rowm2 in m2:
            for i in range(len(m1[0])):
                s += rowm1[i] * rowm2[i]
            temp.append(s)                                  # product's element
            s = 0                                           # reset to zero in next loop
        product.append(temp)                                # product's row
        temp = []                                           # reset to empty list
    return product


if __name__ == '__main__':

    M1 = [[1,2,0,1],
          [4,3,1,4],
          [0,1,1,4],
          [0,0,1,1],
          [1,2,1,3]]
    M2 = transpose(M1)
    res = mul_matrix(M1, M2)
    print(res)
    
