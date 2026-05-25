#include <stdio.h>

int getMobile(int a[], int dir[], int n)
{
    int mobile = 0, mobile_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (dir[a[i]] == -1 && i != 0 && a[i] > a[i-1] && a[i] > mobile)
        {
            mobile = a[i];
            mobile_index = i;
        }

        if (dir[a[i]] == 1 && i != n-1 && a[i] > a[i+1] && a[i] > mobile)
        {
            mobile = a[i];
            mobile_index = i;
        }
    }

    return mobile_index;
}

void printPermutation(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n)
{
    int a[n], dir[n+1];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int i = 1; i <= n; i++)
        dir[i] = -1;  // -1 = left, 1 = right

    printPermutation(a, n);

    while (1)
    {
        int mobile_index = getMobile(a, dir, n);

        if (mobile_index == -1)
            break;

        int mobile = a[mobile_index];
        int swap_index = mobile_index + dir[mobile];

        int temp = a[mobile_index];
        a[mobile_index] = a[swap_index];
        a[swap_index] = temp;

        mobile_index = swap_index;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > mobile)
                dir[a[i]] = -dir[a[i]];
        }

        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
