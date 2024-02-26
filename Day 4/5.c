// Write a program to perform sum of subsets problem using backtracking.
#include <stdio.h>
#include <stdbool.h>

void printSubset(int subset[], int size) {
    printf("Subset: { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void subsetSumUtil(int set[], int n, int targetSum, int subset[], int subsetSize, int sum, int index) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    for (int i = index; i < n; i++) {
        if (sum + set[i] > targetSum) {
            continue; 
        }

        subset[subsetSize] = set[i];
        subsetSumUtil(set, n, targetSum, subset, subsetSize + 1, sum + set[i], i + 1);
    }
}

void subsetSum(int set[], int n, int targetSum) {
    int subset[n]; 
    subsetSumUtil(set, n, targetSum, subset, 0, 0, 0);
}

int main() {
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum %d:\n", targetSum);
    subsetSum(set, n, targetSum);

    return 0;
}
