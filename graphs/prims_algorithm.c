#include <stdio.h>
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];
int main()
{
    printf("\n Enter the number of nodes:");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    visited[1] = 1;
    printf("\n");
    while (ne < n) //while all vertices are covered i.e no of edges is less than number of nodes
    {
        for (i = 1, min = 999; i <= n; i++) //set min=999
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min) //if cost of i to j is less than min
                    if (visited[i] != 0) //and its unvisited
                    {
                        min = cost[i][j]; //make min = cost[i][j]
                        a = u = i; //make copies of i and j
                        b = v = j;
                    }
        /* The purpose of this check is to ensure that the algorithm is selecting edges that connect vertices from the set of visited vertices to the set of unvisited vertices.this is to avoid selection of already selected edges*/
        if (visited[u] == 0 || visited[v] == 0) 
        {
            printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);//print the selected edge
            mincost += min;//adds the cost of the edge to total minimum cost
            visited[b] = 1; //marks the selected edge as visited
        }
        cost[a][b] = cost[b][a] = 999;//to avoid self loops
    }
    printf("\n Minimun cost=%d\n", mincost);
}