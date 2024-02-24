// Write a c program for knapsack problem using dynamic programming.


#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                   knapSack(W, wt, val, n - 1));
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];
    printf("Enter the profits for each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter the weights for each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    int W;
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    printf("Maximum value: %d\n", knapSack(W, weight, profit, n));

    return 0;
}