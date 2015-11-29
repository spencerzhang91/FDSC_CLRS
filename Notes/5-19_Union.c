/* code list 5-19 on page 153 */
#define MAX_ELEMENTS 100
int parent[MAX_ELEMENTS] = {-1,4,-1,2,-1,2,0,0,0,4};
void union(int i, int j)
{
    /* union the sets with roots i and j, i != j, using the weighting rule.
    parent[i] = -count[i] and parent[j] = -count[j] */
    int temp = parent[i] + parent[j];
    if (parent[i] > parent[j]) // parent[i] and parent[j] are negative
    {
        parent[i] = j;
        parent[j] = temp;      // make j the new root
    }
    else
    {
        parent[j] = i;
        parent[i] = temp;      // make i the new root
    }
}