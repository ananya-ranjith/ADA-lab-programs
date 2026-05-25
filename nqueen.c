#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX], n;
int solutionCount = 0;


int place(int row)
{
    int i;

    for(i = 1; i < row; i++)
    {
        // Same column or diagonal
        if(board[i] == board[row] ||
           abs(board[i] - board[row]) == abs(i - row))
        {
            return 0;
        }
    }

    return 1;
}


void printSolution()
{
    int i, j;

    solutionCount++;

    printf("\nSolution %d:\n\n", solutionCount);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(board[i] == j)
                printf(" 1 ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}


void queen(int row)
{
    int col;

    for(col = 1; col <= n; col++)
    {
        board[row] = col;

        if(place(row))
        {
            if(row == n)
            {
                printSolution();
            }
            else
            {
                queen(row + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    queen(1);

    printf("\nTotal Possible Solutions = %d\n", solutionCount);

    return 0;
}