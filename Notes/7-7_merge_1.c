void merge(element list[], element sorted[], int i, int m, int n)
{
    /* merge two sorted files: list[i],...,list[m], and list[m+1],...,list[n].
    These files are sorted to obtain a sorted list: sorted[i],...,sorted[n].
    */
    int j, k, t;
    j = m + 1; // index for the second sublist
    k = i;     // index for the sorted list
    while (i <=m && j <= n)
    {
        if (list[i].key <= list[j].key)
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > m)
    // sorted[k],...,sorted[n] = list[j],...,list[n]
        for (t = j; t <= n; t++)
            sorted[k+t-j] = list[t];
    else
    // sorted[k],...,sorted[n] = list[i],...,list[m]
        for (t = i; t <= m; t++)
            sorted[k+j-1] = list[t];
}