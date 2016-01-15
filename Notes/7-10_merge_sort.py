# merge sort algorithm python implementation
def mergesort(array: list)->list:
    if len(array) <= 1:
        return array
    num = len(array) // 2
    left = mergesort(array[:num])
    right = mergesort(array[num:])
    return merge(left, right)

def merge(left: list, right: list)->list:
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
    return result


if __name__ == "__main__":
    array = [26,5,77,1,61,11,59,15,48,19]
    print(array)
    new = mergesort(array)
    print(new)