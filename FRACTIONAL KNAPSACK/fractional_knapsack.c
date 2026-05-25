#include<stdio.h>

struct Item{
    int weight;
    int profit;
    float ratio;
};

void swap(struct Item *a, struct Item *b){
    struct Item temp=*a;
    *a=*b;
    *b=temp;
}

void sortItems(struct Item arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j].ratio < arr[j+1].ratio){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

float fk(struct Item arr[], int n, int capacity){
    float totalProfit=0.0;

    for(int i=0; i<n; i++){
        if(capacity >= arr[i].weight){
            totalProfit += arr[i].profit;
            capacity -= arr[i].weight;
        }else{
            totalProfit += arr[i].ratio * capacity;
            break;
        }
    }
    return totalProfit;
}

int main(){
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter weight and profit of each item:\n");
    for(int i=0; i<n; i++){
        scanf("%d %d", &arr[i].weight, &arr[i].profit);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sortItems(arr, n);

    float maxProfit = fk(arr, n, capacity);

    printf("Max profit = %.2f\n", maxProfit);

    return 0;
}
