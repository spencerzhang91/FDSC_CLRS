/* Implementation of graph using adjacency lists */
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
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

/* definition of adjacency node */
typedef struct adjnode *ptr;
struct adjnode {
    Vertex adjv;
    Weight w;
    DataType data;
    ptr next;
};

/* definition of linked lists based graph */
typedef struct Gnode *LGraph;
struct Gnode {
    int vertex_num;
    int edge_num;
    ptr G[MaxVertexNum];                    // adjacency linked list
};

LGragh CreateGraph(int vn);
void InsertEdge(LGraph gragh, Edgeptr e);
void buildGraph(LGraph newgra);
void showmatrix(LGraph graph);
static void MakeEdge(ptr header, ptr newnode);
static void traverselist(ptr header);

int main(void)
{
    LGragh newgraph = CreateGraph(10);
    buildGraph(newgraph);
    showmatrix(newgraph);

    return 0;
}

LGragh CreateGragh(int vn)
{
    /* initialize a gragh with vn vertexes but no edges */
    Vertex i;
    LGraph Graph = (LGraph)malloc(sizeof(struct Gnode));
    Graph->vertex_num = vn;
    Graph->edge_num = 0;
    for (i = 0; i < vn; i++)
    {
        Graph->G[i] = (ptr)malloc(sizeof(struct adjnode));
        Graph->G[i]->adjv = i;
        Graph->G[i]->next = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph graph, Edgeptr e)
{
    /* for directed or undirected gragh to insert a new edge */
    ptr newnode = (ptr)malloc(sizeof(struct adjnode));
    newnode->adjv = e->vc;
    newnode->next = NULL;
    newnode->w = e->w;
    MakeEdge(graph->G[e->vr], newnode);
    // if graph is undirected:
    //MakeEdge(graph->G[e->vc], e->vr);
    graph->vertex_num++;
}

void buildGraph(LGraph newgra)
{
    /* This function builds an directed graph adjacency lists by taking
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

void showmatrix(LGraph graph)
{
    int i;
    for (i = 0; i < graph->vertex_num; i++)
    {
        ptr curr = graph->G[i];
        while (curr)
        {
            printf("%d ", curr->w);
            curr = curr->next;
        }
        printf("\n");
    }
}

static void MakeEdge(ptr header, ptr newnode)
{
    if (!header)
    {
        fprintf(stderr, "arg1 of MakeEdge() if NULL.\n");
        exit(EXIT_FAILURE);
    }
    while (header->next)
        header = header->next;
    header->next = newnode;
}

static void traverselist(ptr header)
{
    while (header)
    {
        printf("%d ", header->adjv);
        header = header->next;
    }      
    printf("\n");
}
