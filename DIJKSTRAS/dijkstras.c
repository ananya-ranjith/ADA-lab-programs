#include <stdio.h>
#define INF 9999

int main() {
    int n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n], dist[n], visited[n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source: ");
    scanf("%d", &src);


    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;


    for (int i = 0; i < n - 1; i++) {
        int min = INF, u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int j = 0; j < n; j++) {
            if (graph[u][j] && !visited[j] &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}
