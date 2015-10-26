# Python implementation of maze solving algorithm using stack

# A 6*8 maze, can move up, down, left and right four directions
maze = [[0, 0, 1, 0, 0, 0, 1, 0], 
        [1, 1, 1, 1, 0, 1, 1, 1], 
        [0, 0, 1, 0, 1, 1, 0, 1], 
        [1, 0, 1, 0, 0, 1, 0, 0], 
        [1, 0, 1, 1, 1, 1, 1, 0], 
        [0, 1, 1, 0, 1, 0, 0, 0]]
# An array that records visited cells
mark = [[0, 0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0, 0], 
        [0, 0, 0, 0, 0, 0, 0, 0]]

print(maze)