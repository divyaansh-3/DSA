#include <stdio.h>
#define INF 9999
#define MAX 20

int main() {
    int cost[MAX][MAX];
    int n;
    int visited[MAX] = {0};
    int no_of_edges = 1;
    int min, a, b;
    int total_cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    visited[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (no_of_edges < n) {
        min = INF;
        for (int i = 0; i < n; i++)
            if (visited[i])
                for (int j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }

        printf("Edge %d: (%d -> %d) cost: %d\n", no_of_edges, a, b, min);
        total_cost += min;
        visited[b] = 1;
        no_of_edges++;
    }

    printf("\nMinimum cost = %d\n", total_cost);
    return 0;
}
