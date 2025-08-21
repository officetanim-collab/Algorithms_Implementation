#include <stdio.h>

typedef struct {
    int value;
    int weight;
} Item;

// Function to calculate value/weight ratio
double ratio(Item item) {
    return (double)item.value / item.weight;
}

// Swap two items
void swapItems(Item* x, Item* y) {
    Item temp = *x;
    *x = *y;
    *y = temp;
}

// Sort items in descending order of value/weight ratio
void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ratio(items[j]) < ratio(items[j+1])) {
                swapItems(&items[j], &items[j+1]);
            }
        }
    }
}

// Solve Fractional Knapsack
double solveKnapsack(Item items[], int n, int capacity) {
    sortByRatio(items, n);
    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &items[i].value);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &items[i].weight);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    double maxVal = solveKnapsack(items, n, W);
    printf("Maximum value in knapsack = %.2lf\n", maxVal);

    return 0;
}
