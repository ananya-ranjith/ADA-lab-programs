#include<stdio.h>

int cost[10][10], n, t[10][2], sum;

void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);

int main(){
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    printf("Edges in the Minimum Spanning Tree:\n");
    for(i=0; i<n-1; i++){
        printf("%d %d\n", t[i][0], t[i][1]);
    }

    printf("Total cost of the Minimum Spanning Tree: %d\n", sum);

    return 0;
}

void kruskal(int cost[10][10], int n){
    int min, u, v, count, k;
    int parent[10];
    int i, j;

    k = 0;
    sum = 0;

    for(i=0; i<n; i++){
        parent[i] = i;
    }

    count = 0;

    while(count < n-1){
        min = 999;

        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(cost[i][j] != 0 && cost[i][j] < min){
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int root_u = find(parent, u);
        int root_v = find(parent, v);

        if(root_u != root_v){
            t[k][0] = u;
            t[k][1] = v;

            sum += min;

            parent[root_v] = root_u; 

            k++;
            count++;
        }

        cost[u][v] = cost[v][u] = 999;  
    }
}

int find(int parent[10], int i){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}