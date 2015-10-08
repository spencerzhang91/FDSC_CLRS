# Define a class to store sparse matrix elements
class Element:
    '''
    A class represent a non-zero element of a sparse matrix.
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
    A function to transpose sparse matrix.
    This function does not preserve an order according to row or col.
    '''
    info = Element()
    info.row = matrix[0].col
    info.col = matrix[0].row
    info.val = matrix[0].val
    new_matrix = [info]
    if info.val:
        for i in range(1,len(matrix)):
            new_matrix.append(Element(matrix[i].col,
                                      matrix[i].row,
                                      matrix[i].val))
    return new_matrix


def transpose_ordered(matrix: list)->list:
    '''
    This function will sort matrix list elements according to row number.
    '''
    info = Element(matrix[0].col, matrix[0].row, matrix[0].val)
    new_matrix = [info]
    if info.val:
        for i in range(matrix[0].col):
            for j in range(1, matrix[0].val + 1):
                if matrix[j].col == i:
                    new_matrix.append(Element(matrix[j].col,
                                              matrix[j].row,
                                              matrix[j].val))
    return new_matrix


def transpose_fast(matrix: list)->list:
    '''
    This function can transpose in O(2n) time while the former need O(n^2)
    worst time.
    The main idea is that record non-zero element number in each colum of
    the sparse matrix which indicates the position of elements in the new
    matrix.
    '''
    info = Element(matrix[0].col, matrix[0].row, matrix[0].val)
    new_matrix = [0] * (matrix[0].val + 1)  # info as [0] and other 3 vals as [1][2][3]
    starting_pos = [0] * matrix[0].col
    row_elements = [0] * matrix[0].col      # non-zero elements in origin's each col
                                            # which means in new matrix's each row
    new_matrix[0] = info
    starting_pos[0] = 1                     # new matrix's first element is 'info' too
    if info.val:
        for i in range(1, matrix[0].val + 1):
            row_elements[matrix[i].col] += 1
        for i in range(1, matrix[0].col):
            starting_pos[i] = starting_pos[i-1] + row_elements[i-1]
        for i in range(1, matrix[0].val + 1):
            j = starting_pos[matrix[i].col]
            new_matrix[j] = Element(matrix[i].col, matrix[i].row, matrix[i].val)
    return new_matrix
        
        

if __name__ == '__main__':
    
    M1 = [Element(6,8,3), Element(1,3,3), Element(3,2,-5), Element(4,5,2)]
    print('M1:\n', M1)
    M2 = transpose_sparse(M1)
    M3 = transpose_ordered(M1)
    print('M2:\n', M2)
    print('M3:\n', M3)
    M4 = transpose_fast(M1)
    print('M4:\n', M4)
