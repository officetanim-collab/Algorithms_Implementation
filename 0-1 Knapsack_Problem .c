#include <stdio.h>

// Function to return the larger of two numbers
int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int solveKnapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = maximum(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                                   dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int maxVal = solveKnapsack(capacity, weights, values, n);
    printf("\nMaximum value that can be obtained in the knapsack = %d\n", maxVal);

    return 0;
}
