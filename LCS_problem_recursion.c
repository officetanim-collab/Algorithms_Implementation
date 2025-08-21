#include <stdio.h>
#include <string.h>

// Recursive function to compute LCS length
int computeLCS(char str1[], char str2[], int len1, int len2) {
    if (len1 == 0 || len2 == 0)
        return 0;

    if (str1[len1 - 1] == str2[len2 - 1])
        return 1 + computeLCS(str1, str2, len1 - 1, len2 - 1);
    else {
        int option1 = computeLCS(str1, str2, len1 - 1, len2);
        int option2 = computeLCS(str1, str2, len1, len2 - 1);
        if (option1 > option2)
            return option1;
        else
            return option2;
    }
}

int main() {
    char string1[100], string2[100];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    int len1 = strlen(string1);
    int len2 = strlen(string2);

    int lcsLength = computeLCS(string1, string2, len1, len2);

    printf("\nLength of the Longest Common Subsequence: %d\n", lcsLength);

    return 0;
}
