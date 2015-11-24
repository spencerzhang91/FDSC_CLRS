/* Implementation of gragh using adjacency lists */
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

/* definition of linked lists based gragh */
typedef struct Gnode *LGragh;
struct Gnode {
    int vertex_num;
    int edge_num;
    ptr G[MaxVertexNum];                    // adjacency linked list
};

LGragh CreateGragh(int vn);
static void MakeEdge(ptr header, ptr newnode);
static void traverselist(ptr header);

int main(void)
{
    LGragh newgragh = CreateGragh(10);
    printf("edge_num: %d\n", newgragh->edge_num);
    printf("vertex_num: %d\n", newgragh->vertex_num);
    printf("adjv: %d\n", newgragh->G[3]->adjv);
    return 0;
}

LGragh CreateGragh(int vn)
{
    /* initialize a gragh with vn vertexes but no edges */
    Vertex i;
    LGragh Gragh = (LGragh)malloc(sizeof(struct Gnode));
    Gragh->vertex_num = vn;
    Gragh->edge_num = 0;
    for (i = 0; i < vn; i++)
    {
        Gragh->G[i] = (ptr)malloc(sizeof(struct adjnode));
        Gragh->G[i]->adjv = i;
        Gragh->G[i]->next = NULL;
    }
    return Gragh;
}

void InsertEdge(LGragh gragh, Edge e)
{
    /* for directed or undirected gragh to insert a new edge */
    ptr newnode = (ptr)malloc(sizeof(struct adjnode));
    newnode->adjv = e->vc;
    newnode->next = NULL;
    newnode->w = e->w;
    MakeEdge(gragh->G[e->vr], newnode);
    // if gragh is undirected:
    //MakeEdge(gragh->G[e->vc], e->vr);
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
        printf("%d ", header->adjv);
    printf("\n");
}
