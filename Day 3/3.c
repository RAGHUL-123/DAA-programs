
// Using Dynamic programming techniques to find binomial coefficient of a given number

#include <stdio.h>

// Function to calculate the binomial coefficient using dynamic programming
int binomialCoeff(int n, int k) {
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = binomialCoeff(n, k);
    printf("Binomial Coefficient C(%d, %d) is %d\n", n, k, result);

    return 0;
}