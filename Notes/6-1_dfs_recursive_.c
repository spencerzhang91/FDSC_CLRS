/* The recursive implementation of depth first search of graph */
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
bool visited[MAX_VERTICES];

typedef int Vertex;                         // subfix to represent vertex
typedef int Weight;                         // use int to represent weight
typedef char DataType;                      // data type of vertex data

/* definition of edge */
typedef struct edge *Edge;
struct edge {
    Vertex vr;                              // row subfix
    Vertex vc;                              // col subfix
    Weight wt;                               // weight of the edge
};

/* definition of adjacency node */
typedef struct node *nodeptr;
struct node {
    Vertex adjv;
    Weight wt;
    DataType data;
    nodeptr next;
};

/* definition of linked lists based graph */
typedef struct Gnode *LGraph;
struct Gnode {
    int vertex_num;
    int edge_num;
    nodeptr G[MaxVertexNum];                    // adjacency linked list
};

void dfs_recursive(LGraph graph, Vertex v)
{
    /* depth first search of a graph beginning with vth vertex */
    nodeptr w;
    visited[v] = true;
    printf("%d ", v);
    for (w = graph->G[v]; w; w = w->link)
        if (!visited[w->adjv])
            dfs(graph, w->adjv);
}