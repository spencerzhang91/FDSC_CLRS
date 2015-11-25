/* The recursive implementation of depth first search of graph */
#include <stdbool.h>
#define MAX_VERTICES 10
bool visited[MAX_VERTICES];

void dfs(int v)
{
    /* depth first search of a graph beginning with vertex v */
    node_pointer w;
    visited[v] = true;
    printf("%d ", v);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}