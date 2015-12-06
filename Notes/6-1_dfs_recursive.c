/* The recursive implementation of depth first search of graph */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedGraph.h"  // organized graph ADT

bool visited[MaxVertexNum];
void dfs_recursive(Vertex v);
int main(void)
{
    LGraph graph = CreateGraph(MaxVertexNum);
    dfs_recursive(0);

    return 0;
}

void dfs_recursive(Vertex v)
{
    /* depth first search of a graph beginning with vth vertex */
    nodeptr w;
    visited[v] = true;
    printf("%d ", v);
    for (w = graph->G[v]; w; w = w->link)
        if (!visited[wt->adjv])
            dfs(w->adjv);
}