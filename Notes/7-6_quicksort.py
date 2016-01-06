def quicksort(array: list):
    '''
    This function sorts an array of numbers ascendingly using
    quick sort algorithm.
    '''
    n = len(array)
    if n < 2:
        return
    # divide
    p = array[0]
    L, E, G = [], [], []
    while array:
        if array[0] < p:
            L.append(array.pop(0))
        elif array[0] > p:
            G.append(array.pop(0))
        else:
            E.append(array.pop(0))
    # conquer
    quicksort(L)
    quicksort(G)
    # concatenate results
    while L:
        array.append(L.pop(0))
    while E:
        array.append(E.pop(0))
    while G:
        array.append(G.pop(0))


if __name__ == "__main__":
    test = [26, 5, 37, 1, 61, 11, 59, 15, 48, 19]
    print("before sorting: ", test)
    quicksort(test)
    print("after sorting: ", test)