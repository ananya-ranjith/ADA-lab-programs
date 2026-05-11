#include<stdio.h>

int n,m,w[10],p[10],v[20][20];

int max(int a,int b){
    return (a>b)?a:b;
}

void knapsack(int n, int m, int w[],int p[]){
    int i,j;

    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0 || j==0){
                v[i][j]=0;
            }
            else if(w[i-1] > j){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=max(v[i-1][j],
                           p[i-1] + v[i-1][j - w[i-1]]);
            }
        }
    }
}

int main(){
    int i,j;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter capacity: ");
    scanf("%d",&m);

    printf("Enter weights:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("Enter profits:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    knapsack(n,m,w,p);

    printf("\nDP Table:\n");
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", v[n][m]);

    return 0;
}