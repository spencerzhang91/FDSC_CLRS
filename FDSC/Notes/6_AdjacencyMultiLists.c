/* Implementation of gragh using multiple adjacency lists */
/* This implementation is refined for undirected gragh */
typedef int Vertex;                         // subfix to represent vertex
typedef int Weight;                         // use int to represent weight
typedef char DataType;                      // data type of vertex data

typedef struct edgenode *Edge;
struct edgenode {
    short int marked;
    Vertex v1;
    Vertex v2;
    Edge path1;
    Edge path2;
};
