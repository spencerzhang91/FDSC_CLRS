/* Implementation of gragh using adjacency lists */
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

LGragh CreateGragh(int vn)
{
    /* initialize a gragh with vn vertexes but no edges */
    Vertex i;
    LGragh Gragh = (LGragh)malloc(sizeof(struct Gnode));
    Gragh->vertex_num = vn;
    Gragh->dege_num = 0;
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

}