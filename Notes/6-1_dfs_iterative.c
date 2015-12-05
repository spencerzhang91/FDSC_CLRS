/* The iterative implementation of depth first search of graph */
#include <stdio.h>
#include <stdlib.h>
#include "StackADT.h"

#define MaxVertexNum 100
#define MaxStackSize 100
typedef int Vertex;                         // subfix to represent vertex
typedef int Weight;                         // use int to represent weight
typedef char DataType;                      // data type of vertex data

/* definition of edge */
typedef struct edge *Edge;
struct edge {
    Vertex vr;                              // row subfix
    Vertex vc;                              // col subfix
    Weight wt;                              // weight of the edge
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
    nodeptr G[MaxVertexNum];                // adjacency linked list
};

/* Modified definition of dfs: support function pointer as an argument */
void dfs_iterative(LGraph graph, Vertex start, void (*func)(nodeptr p));
nodeptr nextunvisited(nodeptr curr, int visited[]);
void visit(nodeptr p);

int main(void)
{
    int vertices = 10;
    LGraph tg = CreateGraph(vertices);
    dfs_iterative(tg, 0, visit);

    return 0;
}

void dfs_iterative(LGraph graph, Vertex start, void (*func)(nodeptr p))
{
    int visited[graph->vertex_num] = {0}; // rest elements init automaticly
    nodeptr stack = CreateStack(MaxStackSize);
    nodeptr curr, startnode;
    curr = startnode = graph->G[start];
    
    push(stack, curr);
    visited[curr->adjv] = 1;
    while (curr->adjv != start || stack)
    {
        curr = nextunvisited(curr, visited);
        if (curr)
        {
            (*func)(curr);
            visited[curr->adjv] = 1;
            push(stack, curr);
        }
        else curr = pop(stack);
    }
}

nodeptr nextunvisited(nodeptr curr, int visited[])
{
    curr = curr->next;
    while (curr)
    {
        if (visited[curr->adjv])
            curr = curr->next;
        else break;
    }
    return curr;
}

void visit(nodeptr p)
{
    printf("visiting vertext %d\n", p->adjv);
}