/* The recursive implementation of depth first search of graph */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedGraph.h"  // organized graph ADT

bool visited[MaxVertexNum];
void dfs_recursive(LGraph graph, Vertex v);

int main(void)
{
    LGraph graph = CreateGraph(MaxVertexNum);
    buildGraph_test(graph);
    dfs_recursive(graph, 0);
    //getchar();
    return 0;
}

void dfs_recursive(LGraph graph, Vertex v)
{
    /* depth first search of a graph beginning with vth vertex */
    nodeptr ptr;
    visited[v] = true;
    printf("visiting vertex: %d\n", v);
    for (ptr = graph->G[v]; ptr; ptr = ptr->next)
        if (!visited[ptr->adjv])
            dfs_recursive(graph, ptr->adjv);
}