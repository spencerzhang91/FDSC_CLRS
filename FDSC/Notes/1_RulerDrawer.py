# An example from DSAIP(Chap4, page 135, code fragment 4.2)
# Served as an supplymentary example to illustrate recursion
# Drawing an English ruler recursively
# RulerDrawer.py

def draw_line(tick_lenth, tick_label=''):
    '''Draw one line with given tick lenght(followed by
       opetional label)'''
    line = '-' * tick_lenth
    if tick_label:
        line += ' ' + tick_label
    print(line)

def draw_interval(center_length):
    '''Draw tick interval based upon central tick length'''
    if center_length > 0:      # stops when length drops to 0
        draw_interval(center_length - 1)
        draw_line(center_length)
        draw_interval(center_length - 1)

def draw_ruler(num_inches, major_length):
    '''Draw English ruler with given number of inches, major
    tick length'''
    draw_line(major_length, '0')
    for j in range(1, 1+num_inches):
        draw_interval(major_length - 1)
        draw_line(major_length, str(j))

draw_ruler(2, 4)
