/* determine the connected components of a graph */
void connected(void)
{
    int i;
    for (i = 0; i < n; i++) // n is the number of vertices
        if (!visited[i])
        {
            dfs(i);
            printf("\n");
        }
}