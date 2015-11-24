/* implementation of gragh using adjacency matrix */
#define MaxVertexNum 100
#define INFINITY 65535
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
/* definition of gragh */
typedef struct Gnode *MGragh;
struct Gnode {
    int vertex_num;
    int edge_num;
    Weight G[MaxVertexNum][MaxVertexNum];   // the adjacency matix
    DataType Data[MaxVertexNum];            // data saved on vertexes
};

MGragh CreateGragh(int vn)                  // vn for vertex number
{
    /* initialize a gragh with vn vertexes but no edges */
    Vertex i, j;
    MGragh Gragh = (MGragh)malloc(sizeof(struct Gnode));
    Gragh->vertex_num = vn;
    Gragh->edge_num = 0;
    /* the initial vertex subfix starts from 0 */
    for (i = 0; i < vn; i++)
        for (j = 0; j < vn; j++)
            Gragh->G[i][j] = INFINITY;
    return Gragh;
}
