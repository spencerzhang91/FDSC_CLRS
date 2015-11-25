/* Implementation of graph using adjacency lists */
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
typedef int Vertex;                         // subfix to represent vertex
typedef int Weight;                         // use int to represent weight
typedef char DataType;                      // data type of vertex data

/* definition of edge */
typedef struct Enode *Edge;
struct Enode {
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
void InsertEdge(LGraph gragh, Edge e);
static void MakeEdge(ptr header, ptr newnode);
static void traverselist(ptr header);

int main(void)
{
    LGragh newgraph = CreateGraph(10);
    printf("edge_num: %d\n", newgraph->edge_num);
    printf("vertex_num: %d\n", newgraph->vertex_num);
    printf("adjv: %d\n", newgraph->G[3]->adjv);
    Edge edgeone = (Edge)malloc(sizeof(struct Enode));
    edgeone->vc = 3; edgeone->vr = 8; edgeone->w = 1;
    InsertEdge(newgraph, edgeone);
    for (int i = 0; i < 10; i++)
        traverselist(newgraph->G[i]);
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

void InsertEdge(LGraph graph, Edge e)
{
    /* for directed or undirected gragh to insert a new edge */
    ptr newnode = (ptr)malloc(sizeof(struct adjnode));
    newnode->adjv = e->vc;
    newnode->next = NULL;
    newnode->w = e->w;
    MakeEdge(graph->G[e->vr], newnode);
    // if graph is undirected:
    //MakeEdge(graph->G[e->vc], e->vr);
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
