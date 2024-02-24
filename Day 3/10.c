// Write a program to find the optimal cost by using appropriate algorithm	

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    int x = *((int *)a);
    int y = *((int *)b);
    return x - y;
}

// Function to calculate the optimal cost
int optimal_cost(int costs[], int n) {
    // Sort the costs array in ascending order
    qsort(costs, n, sizeof(int), compare);

    // Calculate the total cost
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        if (costs[i] > 0) {
            total_cost += costs[i];
            costs[i]--;
        }
    }

    return total_cost;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the costs array
    int *costs = (int *)malloc(n * sizeof(int));

    // Input the costs from the user
    printf("Enter the costs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &costs[i]);
    }

    // Calculate and print the optimal cost
    printf("Optimal cost: %d\n", optimal_cost(costs, n));

    // Free dynamically allocated memory
    free(costs);

    return 0;
}