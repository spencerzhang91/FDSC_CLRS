int mlist[] merge(int list1[], int list2[], int n, int m)
{
    /* merge two sorted lists list1 & list2 with length n and m, 
    return a sorted merged mlist with length n+m
    */
    int i = 0, j = 0, k = 0;
    int *sorted = (int *)malloc(sizeof(int)*(m + n));
    while (i < n && j < m)
    {
        if (list1[i] <= list2[j])
            sorted[k++] = list1[i++];
        else
            sorted[k++] = list2[j++];
    }
    while (i < n)
        sorted[k++] = list1[i++];
    while (j < m)
        sorted[k++] = list2[j++];
    return sorted;
}