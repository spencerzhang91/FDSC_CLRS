/* 7-6_quicksort_array.c
Actually I have to look up meterial about this algorithm in book DSAP to 
get more specific conduction. Array based implementation.
*/

void quicksort(element list[], int left, int right)
{
    /* sort list[left], ..., list[right] into nondecreasing order on the
    key field. list[left].key is arbitrarily chosen as the pivot key. It
    is assumed that list[left].key <= lsit[right+1].key
    */
    int pivot, i, j;
    element temp;
    if (left < right)
    {
        i = left; j = right + 1;
        pivot = list[left].key;
        do {
            /* search ofr keys from the left and right sublists, swapping
            out-of-order elements until the left and right boundaries cross
            or meet. */
            do i++; while (list[i].key < pivot);
            do j--; while (list[j].key > pivot);
            if (i < j)
                SWAP(list[i], list[j], temp);
        } while (i < j);
        SWAP(list[left], list[j], temp);
        quicksort(list, left, j-1);
        quicksort(list, j+1, right);
    }
}