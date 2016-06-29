# merge sort algorithm on FDSC chap 7 page 213
def counter():
    init = 0
    def add():
        nonlocal init
        init += 1
        return init
    return add

def merge(list1, list2):
    """
    Input: two sorted lists of various length
    Output: a sorted list which is merged from list1 and list2
    """
    len1 = len(list1)
    len2 = len(list2)
    i = j = 0
    sorted_list = []
    c = counter()
    while i < len1 and j < len2:
        if list1[i] <= list2[j]:
            sorted_list.append(list1[i])
            i += 1
            c()
        else:
            sorted_list.append(list2[j])
            j += 1
            c()
    while i < len1:
        sorted_list.append(list1[i])
        i += 1
        c()
    while j < len2:
        sorted_list.append(list2[j])
        j += 1
    res = c()
    print(res)
    return sorted_list

if __name__ == "__main__":

    L1 = [1,3,4,5,7,8]
    L2 = [2,6,9,10,11]
    res = merge(L1, L2)
    print(res)
    c = counter()
    
