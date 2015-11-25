/* The queue based implementation of breadth first search of graph */
#include <stdbool.h>
#define MAX_VERTICES 10
bool visited[MAX_VERTICES];
/* This implementation is directly from textbook and need to be rewrite to be
complied with complete version of QueueADT */
typedef struct queue *queue_pointer;
struct queue {
    int vertex;
    queue_pointer next;
};

void addq(queue_pointer *, queue_pointer *, int);
int deleteq(queue_pointer *);

void bfs(int v)
{
    node_pointer w;
    queue_pointer front, rear;
    front = rear = NULL;
    printf("%d ", v);
    visited[v] = true;
    addq(&front, &rear, v);
    while (front)
    {
        v = deleteq(&front);
        for (w = graph[v]; w; w = w->next)
            if (!visited[w->vertex])
            {
                printf("%d ", w->vertex);
                addq(&front, &rear, w->vertex);
                visited[w->vertex] = true;
            }
    }
}
