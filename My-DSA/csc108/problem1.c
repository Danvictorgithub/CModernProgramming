#include <stdio.h>
#include <stdlib.h>
// Do the following on each of the problem provided below. Create a tree that visualizes the algorithm that
// solves the problem.
// a. Create a brute force recursive algorithm that solves the problem.
// b. Modify your brute force algorithm in which memoization is applied.
// c. Modify your brute force algorithm in which tabulation is applied.
// d. Explain the difference in the time and space complexity between the brute force approach and the
// dynamic programming approach ( memorization/tabulation )


// Problem #1: Write a function howSum(targetSum, numbers) that takes a targetSum and an array of
// numbers as arguments. The function should return an array containing any combination of elements that
// add up exactly the targetSum. If there is no combination that adds up to targetSum , then return null. If
// there are multiple combinations possible, you may return any single one.


// result[] => combination result 

int howSum(int targetSum, int numbers[], int size, int result[]) {
    // inspired from camsum problem
    // I also tried using pointer array but the solution is too long and difficult to memoize and tabulate
    if (targetSum == 0) {
        return 1; // Target sum reached
    }
    if (targetSum < 0) {
        return 0; // Target sum not possible
    }

    for (int i = 0; i < size; i++) {
        int remainder = targetSum - numbers[i];
        if (howSum(remainder, numbers, size, result)) {
            result[targetSum] = numbers[i];
            return 1;
        }
    }
    return 0;
}

// Memoization
int howSumMemoization(int targetSum, int numbers[], int size, int memo[], int result[]) {
    if (memo[targetSum] != -1) {
        return memo[targetSum];
    }
    if (targetSum == 0) {
        return 1; // Target sum reached
    }
    if (targetSum < 0) {
        return 0; // Target sum not possible
    }

    for (int i = 0; i < size; i++) {
        int remainder = targetSum - numbers[i];
        if (howSumMemoization(remainder, numbers, size, memo, result)) {
            result[targetSum] = numbers[i];
            memo[targetSum] = 1;
            return 1;
        }
    }

    memo[targetSum] = 0;
    return 0;
}

void howSumTabulation(int targetSum, int numbers[], int size, int result[]) {
    // I found out that this particular problem doesn't have a proper solution for tabulation 
    // since coming from bottom-up approach, we can't calculate the next sum, since it the aray is relative and not predetermined
    int* table = (int*)malloc((targetSum + 1) * sizeof(int));
    for (int i = 0; i <= targetSum; i++) {
        table[i] = -1; // Initialize to indicate no combination
    }
    table[0] = 1; // Base case: an empty set sums to 0

    for (int i = 0; i <= targetSum; i++) {
        if (table[i] != -1) {
            for (int j = 0; j < size; j++) {
                if (i + numbers[j] <= targetSum) {
                    table[i + numbers[j]] = j; // Store the index for backtracking
                }
            }
        }
    }

    // Print the combination using the result array
    if (table[targetSum] != -1) {
        printf("Combination found: ");
        int current = targetSum;
        while (current > 0) {
            printf("%d ", numbers[table[current]]);
            result[current] = numbers[table[current]];
            current -= result[current];
        }
    } else {
        printf("No combination found.");
    }

    free(table);
}

int* OldSolutionHowSum(int targetSum, int* numbers, int size) {
    // Solution inspired from previous camsum algorithm, I found this to be very difficult to tabulate or memoize
    if (targetSum == 0) {
        //empty array
        int* combination = (int*)malloc(sizeof(int));
        return combination;
    }
    if (targetSum < 0) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        int remainder = targetSum - numbers[i];
        int* combination = OldSolutionHowSum(remainder, numbers, size); // array result of recursion
        if (combination != NULL) {
            // Adds number to combination array
            int dynamicSize = 0;
            while (combination[dynamicSize] != 0) { // since I can't use sizeof inside a function this is the only way to check the array dynamically
                dynamicSize++;
            }
            combination = (int*)realloc(combination, (dynamicSize + 2) * sizeof(int));
            combination[dynamicSize] = numbers[i];
            combination[dynamicSize + 1] = 0;
            return combination;
        }
    }
    return NULL;
}




int main(void) {
    int targetSum = 7;
    int numbers[] = {2, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result[100] = {0}; // Assuming maximum size

    // Brute Force
    if (howSum(targetSum, numbers, size, result)) {
        printf("Brute Force - Combination found: ");
        for (int i = targetSum; i > 0; i -= result[i]) {
            printf("%d ", result[i]);
        }
    } else {
        printf("Brute Force - No combination found.");
    }
    printf("\n");

    // Memoization
    int memo[100];
    for (int i = 0; i < 100; i++) {
        memo[i] = -1;
    }
    if (howSumMemoization(targetSum, numbers, size, memo, result)) {
        printf("Memoization - Combination found: ");
        for (int i = targetSum; i > 0; i -= result[i]) {
            printf("%d ", result[i]);
        }
    } else {
        printf("Memoization - No combination found.");
    }
    printf("\n");

    // Tabulation
    howSumTabulation(targetSum, numbers, size, result);

    return 0;
}
