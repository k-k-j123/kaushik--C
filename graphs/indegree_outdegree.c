#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adj_matrix[n][n];

    printf("Enter the adjacency matrix (use 0 for no edge and 1 for edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    printf("Vertex\tIndegree\tOutdegree\n");
    for (int i = 0; i < n; i++)
    {
        int indegree = 0;
        int outdegree = 0;

        for (int j = 0; j < n; j++)
        {
            if (adj_matrix[i][j] == 1)
            {
                outdegree++;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (adj_matrix[j][i] == 1)
            {
                indegree++;
            }
        }

        printf("%d\t%d\t\t%d\n", i, indegree, outdegree);
    }

    return 0;
}
