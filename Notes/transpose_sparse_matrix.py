# Define a class to store sparse matrix elements
class Element:
    '''
    A class represent a non-zero element of a sparse matrix
    '''
    def __init__(self, row=0, col=0, val=0):
        self.row = row                      # row number of element
        self.col = col                      # col number of element
        self.val = val                      # value of element (non-zero)

    def __repr__(self):
        return "{(%d,%d): %d}" % (self.row, self.col, self.val)

# For a certain matrix, use a list of instances of class Element
# to represent all non-zero element of the matrix
# The first element of list represent total rows, cols and
# non-zero element number


def transpose_sparse(matrix: list)->list:
    '''
    A function to transpose sparse matrix
    This function does not preserve an order according to row or col
    '''
    info = Element()
    info.row = matrix[0].col
    info.col = matrix[0].row
    info.val = matrix[0].val
    new_matrix = [info]
    for i in range(1,len(matrix)):
        new_matrix.append(Element(matrix[i].col,
                                  matrix[i].row,
                                  matrix[i].val))
    return new_matrix


def transpose_ordered(matrix: list)->list:
    '''
    This function will sort matrix list elements according to row number
    '''
    info = Element(matrix[0].col, matrix[0].row, matrix[0].val)
    new_matrix = [info]
    for i in range(matrix[0].col):
        for j in range(1, matrix[0].val + 1):
            if matrix[j].col == i:
                new_matrix.append(Element(matrix[j].col,
                                          matrix[j].row,
                                          matrix[j].val))
    return new_matrix
        


if __name__ == '__main__':
    
    M1 = [Element(6,8,3), Element(1,3,3), Element(3,2,-5), Element(4,5,2)]
    print('M1:\n', M1)
    M2 = transpose_sparse(M1)
    M3 = transpose_ordered(M1)
    print('M2:\n', M2)
    print('M3:\n', M3)
    


