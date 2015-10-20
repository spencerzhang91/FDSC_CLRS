'''
Python implementation of merge sort algorithm (list based)
'''
def merge(left, right):
    '''
    helper function that merges two sorted sub lists(right and left)
    '''
    i, j = 0, 0
    result = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    print('current result:', result, '\n')
    return result

def merge_sort(lists):
    '''
    merge sort algorithm
    '''
    if len(lists) <= 1:
        return lists
    center = len(lists) // 2
    left = merge_sort(lists[:center])
    right = merge_sort(lists[center:])
    return merge(left, right)

if __name__ == '__main__':
    A = [10, 4, 2, 14, 44, 1, 20, 40]
    B = merge_sort(A)
    print("A:", A)
    print("B:", B)


