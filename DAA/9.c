// Write a program for calculating time complexity for multiply two Matrix.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Define the size of the matrices

// Function to allocate memory for a 2D array
int** allocate_2d_array(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
    return arr;
}

// Function to free memory allocated for a 2D array
void free_2d_array(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Function to multiply two matrices A and B
void multiply_matrices(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int **A, **B, **C;
    int i, j;

    // Allocate memory for matrices A, B, and C
    A = allocate_2d_array(N, N);
    B = allocate_2d_array(N, N);
    C = allocate_2d_array(N, N);

    // Initialize matrices A and B with random values
    srand(time(NULL)); // Seed the random number generator
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 100; // Generate random values between 0 and 99
            B[i][j] = rand() % 100;
        }
    }

    // Measure the time taken for matrix multiplication
    clock_t start_time = clock();
    multiply_matrices(A, B, C, N);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the time taken for matrix multiplication
    printf("Time taken for matrix multiplication: %f seconds\n", time_taken);

    // Free memory allocated for matrices A, B, and C
    free_2d_array(A, N);
    free_2d_array(B, N);
    free_2d_array(C, N);

    return 0;
}
