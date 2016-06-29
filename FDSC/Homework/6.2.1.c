/* excercise 6.2.1.c */
/* implementation of dfs algorithm of adjacency matrix based graph */

void dfs_iterative(MGraph graph, Vertex start, void (*func)(int p))
{
    int visited[graph->vertex_num];
    Stack stack = CreateStack(MAX_STACK_SIZE);
    int curr;
    curr = start; // here curr marks current vertex
    
    (*func)(curr);
    push(stack, curr);
    visited[curr] = 1;
    
    while (curr != start || !IsEmpty(stack))
    {
        int flag = 0;
        for (int i = 0; i < graph->vertex_num; i++)
            if ((graph->G[curr][i] == 1) && (visited[i] != 1))
            {
                curr = i;
                flag++;
                break;
            }
        if (flag)
        {
            (*func)(curr);
            visited[curr] = 1;
            push(stack, curr);
            display(stack); // check point
        }    
        else
            curr = pop(stack);
    }
}

void visit(int p)
{
    printf("visiting vertext %d\n", p);
}
