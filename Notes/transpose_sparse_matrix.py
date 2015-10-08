# Define a class to store sparse matrix elements
class Element:
    '''
    A class represent a non-zero element of a sparse matrix
    '''
    def __init__(self, row=0, col=0, val=0):
        self.row = row
        self.col = col
        self.val = val

    def __repr__(self):
        return "{(%d,%d): %d}" % (self.row, self.col, self.val)

# For a certain matrix, use a list of instances of class Element
# to represent all non-zero element of the matrix
# The first element of list represent total rows, cols and
# non-zero element number


def transpose_sparse(matrix: list) -> list:
    '''
    A function to transpose sparse matrix
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




if __name__ == '__main__':
    
    M1 = [Element(6,8,3), Element(1,1,3), Element(4,2,-5), Element(5,5,2)]
    print(M1)
    M2 = transpose_sparse(M1)
    print(M2)
    


