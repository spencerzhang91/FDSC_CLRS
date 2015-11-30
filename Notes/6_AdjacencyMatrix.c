/* implementation of graph using adjacency matrix */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;                         // subfix to represent vertex
typedef int Weight;                         // use int to represent weight
typedef char DataType;                      // data type of vertex data

/* definition of edge */
typedef struct edge *Edgeptr;
struct edge {
    Vertex vr;                              // row subfix
    Vertex vc;                              // col subfix
    Weight w;                               // weight of the edge
};
/* definition of graph */
typedef struct graph *MGraph;
struct graph {
    int vertex_num;
    int edge_num;
    Weight G[MaxVertexNum][MaxVertexNum];   // the adjacency matix
    DataType Data[MaxVertexNum];            // data saved on vertexes
};

MGraph CreateGraph(int vn);
void InsertEdge(MGraph g, Edgeptr e);
void buildGraph(MGraph newgra);
void showmatrix(MGraph graph);

int main(void)
{
    MGraph map = CreateGraph(10);
    buildGraph(map);
    showmatrix(map);

    return 0;
}

MGraph CreateGraph(int vn)                  // vn for vertex number
{
    /* initialize a graph with vn vertexes but no edges */
    Vertex i, j;
    MGraph Graph = (MGraph)malloc(sizeof(struct graph));
    Graph->vertex_num = vn;
    Graph->edge_num = 0;
    /* initialize the adjacency matrix */
    for (i = 0; i < vn; i++)
        for (j = 0; j < vn; j++)
            Graph->G[i][j] = INFINITY; // initialization weight
    return Graph;
}

void InsertEdge(MGraph g, Edgeptr e)
{
    g->G[e->vr][e->vc] = e->w;
    //g->G[e->vc][e->vr] = e->w; // if graph is undirected add this line
    g->edge_num++;
}

void buildGraph(MGraph newgra)
{
    /* This function builds an directed graph adjacency matrix by taking
     pairs of connections */
    int row, col, weight;
    printf("Please input a pair of connected nodes(vr-vc:w)"
        " to the %d nodes graph:\n", newgra->vertex_num);
    while (scanf("%d-%d:%d", &row, &col, &weight) == 3)
    {
        Edgeptr newedge = (Edgeptr)malloc(sizeof(struct edge));
        newedge->vr = row; newedge->vc = col; newedge->w = weight;
        InsertEdge(newgra, newedge);
        printf("New edge inserted to the graph.\n");
    }
}

void showmatrix(MGraph graph)
{
    int i, j;
    int max = graph->vertex_num;
    for (i = 0; i < max; i++)
        for (j = 0; j <max; j++)
            printf("%d ", graph->G[i][j]);
    printf("\n");
}
