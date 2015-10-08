# Simplest algorithm to transpose a matrix(not sparse)
# The basic idea of transpose
def transpose(matrix):
    '''
    matrix is a 2d python list
    '''
    rows = len(matrix)
    cols = len(matrix[0])
    nrow, nmatrix = [], []
    for i in range(cols):
        for row in matrix:
            nrow.append(row[i])
        nmatrix.append(nrow)
        nrow = []
            
    return nmatrix

    
