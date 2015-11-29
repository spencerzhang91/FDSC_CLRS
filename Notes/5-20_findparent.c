/* code list 5-20: find parent of the set */
#define MAX_ELEMENTS 100
int parent[MAX_ELEMENTS] = {-1,4,-1,2,-1,2,0,0,0,4};

int find(int i)
{
    /* find the root of the tree containing element i. Use the collapsing rule
    to collapse all nodes from i to root. */
    int root, trail, lead;
    for (root = i; parent[root] >= 0; root = parent[root])
        continue;
    for (trail = i; trail != root; trail = lead)
    {
        lead = parent[trail];
        parent[trail] = root;
    }
    return root;
}