#include <stdio.h>

#define MAX 100

int main() {
    int n, graph[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("Topological Order: ");

    // Process all vertices
    for (int count = 0; count < n; count++) {
        int found = -1;

        // Find vertex with indegree 0 and not visited
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && visited[i] == 0) {
                found = i;
                break;
            }
        }

        // If no such vertex → cycle exists
        if (found == -1) {
            printf("\nGraph has a cycle! No topological sort possible.\n");
            return 0;
        }

        // Print and mark visited
        printf("%d ", found);
        visited[found] = 1;

        // Reduce indegree of adjacent nodes
        for (int j = 0; j < n; j++) {
            if (graph[found][j] == 1)
                indegree[j]--;
        }
    }

    printf("\n");
    return 0;
}