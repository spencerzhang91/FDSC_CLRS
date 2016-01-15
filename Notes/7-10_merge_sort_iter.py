"""
Merge sort algorithm python iterative implementation
The core idea is that the elments are transfered between two lists (array &
extra) over and over again until all are sorted.
"""
def merge_sort(array:list)->None:
    """
    Input a unsorted list and will apply merge sort algorithm to
    sort the list in place (O(1) space)
    """
    length = 1
    L = len(array)
    extra = [None] * L
    while length < L:
        merge_pass(array, extra, L, length)
        length *= 2
        merge_pass(extra, array, L, length)
        length *= 2
        

def merge_pass(array:list, sortedl:list, n:int, length:int)->None:
    """
    array is the unsorted list, sortedl is the sorted result, n is
    the number of elements that in array, length is sub list size.
    """
    i = 0
    while i <= n - 2*length:
        merge(array, sortedl, i, i+length-1, i+length*2-1)
        i += 2 * length
    if i + length < n:
        merge(array, sortedl, i, i+length-1, n-1)
    else:
        j = i
        while j < n:
            sortedl[j] = array[j]
            j += 1


def merge(array:list, sortedl:list, i:int, m:int, n:int)->None:
    """
    This function merges two sorted subpart of a list into 
    one inplace. i is the start index of first sublist, m 
    is the end index of first sublist and n is the last 
    index of the array .
    """
    k = i
    j = m + 1
    while i <= m and j <= n:
        if array[i] <= array[j]:
            sortedl[k] = array[i]
            i += 1; k += 1
        else:
            sortedl[k] = array[j]
            j += 1; k += 1
    if i > m:
        t = j
        while t <= n:
            sortedl[k+t-j] = array[t]
            t += 1
    else:
        t = i
        while t <= m:
            sortedl[k+t-i] = array[t]
            t += 1

    
if __name__ == "__main__":
    array = [1,5,77,100,161,11,59,75,148,219]
    print(array)
    merge_sort(array)
    print(array)
