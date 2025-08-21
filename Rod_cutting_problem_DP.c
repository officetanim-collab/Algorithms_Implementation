#include <stdio.h>

// Function to find maximum of two numbers using if-else
int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// Function to solve the Rod Cutting problem
int solveRodCutting(int prices[], int length) {
    int dp[length + 1];
    dp[0] = 0;

    for (int i = 1; i <= length; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] = maximum(dp[i], prices[j] + dp[i - j]);
        }
    }

    return dp[length];
}

int main() {
    int n;
    printf("Enter the rod length: ");
    scanf("%d", &n);

    int price[n + 1];
    printf("Enter price of each piece (length 1 to %d):\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }

    int maxProfit = solveRodCutting(price, n);
    printf("\nMaximum Profit obtainable for rod of length %d is: %d\n", n, maxProfit);

    return 0;
}
