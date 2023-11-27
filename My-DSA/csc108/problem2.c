#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Brute Force Recursive Algorithm
int shortestSumBruteForce(int targetSum, int numbers[], int size, int result[]) {
    if (targetSum == 0) {
        return 0;
    }

    if (targetSum < 0) {
        return -1;
    }

    int shortestLen = INT_MAX;

    for (int i = 0; i < size; ++i) {
        int remainingSum = targetSum - numbers[i];
        int remainingLen = shortestSumBruteForce(remainingSum, numbers, size, result);

        if (remainingLen >= 0 && remainingLen + 1 < shortestLen) {
            shortestLen = remainingLen + 1;
            result[0] = numbers[i];
            for (int j = 0; j < remainingLen; ++j) {
                result[j + 1] = result[j];
            }
        }
    }

    return (shortestLen == INT_MAX) ? -1 : shortestLen;
}

// Memoization Algorithm
int shortestSumMemoizationHelper(int targetSum, int numbers[], int size, int result[], int memo[]) {
    if (memo[targetSum] != -1) {
        return memo[targetSum];
    }

    if (targetSum == 0) {
        memo[targetSum] = 0;
        return 0;
    }

    if (targetSum < 0) {
        memo[targetSum] = -1;
        return -1;
    }

    int shortestLen = INT_MAX;

    for (int i = 0; i < size; ++i) {
        int remainingSum = targetSum - numbers[i];
        int remainingLen = shortestSumMemoizationHelper(remainingSum, numbers, size, result, memo);

        if (remainingLen >= 0 && remainingLen + 1 < shortestLen) {
            shortestLen = remainingLen + 1;
            result[0] = numbers[i];
            for (int j = 0; j < remainingLen; ++j) {
                result[j + 1] = result[j];
            }
        }
    }

    memo[targetSum] = (shortestLen == INT_MAX) ? -1 : shortestLen;
    return memo[targetSum];
}

int shortestSumMemoization(int targetSum, int numbers[], int size, int result[]) {
    int memo[targetSum + 1];
    for (int i = 0; i <= targetSum; ++i) {
        memo[i] = -1;
    }

    int length = shortestSumMemoizationHelper(targetSum, numbers, size, result, memo);

    return (length > 0) ? length : -1;
}

// Tabulation Algorithm
int shortestSumTabulation(int targetSum, int numbers[], int size, int result[]) {
    int table[targetSum + 1];
    int prevIndex[targetSum + 1];

    for (int i = 0; i <= targetSum; ++i) {
        table[i] = -1;
        prevIndex[i] = -1;
    }

    table[0] = 0;

    for (int i = 0; i <= targetSum; ++i) {
        if (table[i] != -1) {
            for (int j = 0; j < size; ++j) {
                if (i + numbers[j] <= targetSum) {
                    if (table[i + numbers[j]] == -1 || table[i] + 1 < table[i + numbers[j]]) {
                        table[i + numbers[j]] = table[i] + 1;
                        prevIndex[i + numbers[j]] = j;
                    }
                }
            }
        }
    }

    if (table[targetSum] == -1) {
        return -1;
    }

    int currentIndex = targetSum;
    int length = table[targetSum];

    for (int i = 0; i < length; ++i) {
        result[i] = numbers[prevIndex[currentIndex]];
        currentIndex -= result[i];
    }

    return length;
}

int main() {
    int targetSum = 6;
    int numbers[] = {2, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result[size];

    // Brute Force
    int lengthBruteForce = shortestSumBruteForce(targetSum, numbers, size, result);
    if (lengthBruteForce > 0) {
        printf("Brute Force: Shortest combination: {");
        for (int i = 0; i < lengthBruteForce; ++i) {
            printf("%d", result[i]);
            if (i < lengthBruteForce - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    } else {
        printf("Brute Force: No valid combination found.\n");
    }

    // Memoization
    int lengthMemoization = shortestSumMemoization(targetSum, numbers, size, result);
    if (lengthMemoization > 0) {
        printf("Memoization: Shortest combination: {");
        for (int i = 0; i < lengthMemoization; ++i) {
            printf("%d", result[i]);
            if (i < lengthMemoization - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    } else {
        printf("Memoization: No valid combination found.\n");
    }

    // Tabulation
    int lengthTabulation = shortestSumTabulation(targetSum, numbers, size, result);
    if (lengthTabulation > 0) {
        printf("Tabulation: Shortest combination: {");
        for (int i = 0; i < lengthTabulation; ++i) {
            printf("%d", result[i]);
            if (i < lengthTabulation - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    } else {
        printf("Tabulation: No valid combination found.\n");
    }

    return 0;
}
