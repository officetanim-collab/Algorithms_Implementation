#include <stdio.h>
#include <string.h>

// Function to return maximum of two integers using if-else
int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// Function to compute length of LCS
int longestCommonSubsequence(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int table[len1 + 1][len2 + 1];

    // Initialize first row and column to 0
    for (int i = 0; i <= len1; i++) table[i][0] = 0;
    for (int j = 0; j <= len2; j++) table[0][j] = 0;

    // Fill the DP table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = maximum(table[i - 1][j], table[i][j - 1]);
        }
    }

    return table[len1][len2];
}

int main() {
    char string1[100], string2[100];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    int lcsLength = longestCommonSubsequence(string1, string2);
    printf("\nLength of the Longest Common Subsequence: %d\n", lcsLength);

    return 0;
}
