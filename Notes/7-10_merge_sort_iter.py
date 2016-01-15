# merge sort algorithm python implementation
# iterative
def merge(array:list, sortedl:list, i:int, m:int, n:int)->None:
    """
    This function merges two sorted subpart of a list into 
    one inplace. i is the start index of first sublist, m 
    is the end index of first sublist and n is the last 
    index of the array .
    """
    j = m + 1
    while i <= m and j <= n:
        if array[i] <= array[j]:
            sortedl.append(array[i])
            i += 1
        else:
            sortedl.append(array[j])
            j += 1
    sortedl += array[i:m+1]
    sortedl += array[j:n+1]

if __name__ == "__main__":
    array = [1,5,77,100,161,11,59,75,148,219]
    result = []
    print(array)
    merge(array, result, 0, 4, 9)
    print(result)