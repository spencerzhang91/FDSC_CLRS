/* excercise 6.2.2.c */
/* implementation of bfs algorithm of adjacency matrix based graph */

void bfs_iterative(MGraph graph, Vertex start, void (*func)(int p))
{
    int visited[graph->vertex_num];
    Queue queue = CreateQueue(graph->vertex_num);
    int curr;
    curr = start; // 
    visited[curr] = 1;
    enqueue(queue, curr);
    
    while (!QIsEmpty(queue))
    {        
        for (int i = 0; i < graph->vertex_num; i++)
            if ((graph->G[curr][i] == 1) && (visited[i] != 1))
            {
                enqueue(queue, i);
                visited[i];
            }
        curr = dequeue(queue);
        (*func)(curr);
    }
}

void visit(int p)
{
    printf("visiting vertext %d\n", p);
}
