#include <stdio.h>

long long unsigned fib(unsigned n, unsigned int *memo) {
    if (n <= 1) {
        return n;
    } else {
        if (memo[n] != -1) {
            return memo[n];
        } else {
            memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
            return memo[n];
        }
    }
}

int main(void) {
    unsigned option = 0;

    printf("Fibonacci Code\n");
    printf("Enter the option number: ");
    scanf("%d", &option);

    // Validate the input
    if (option < 0) {
        printf("Invalid option. Please enter a non-negative number.\n");
        return 1;  // indicating an error
    }

    // Initialize the memoization array
    unsigned int memo[option + 1];
    for (int i = 0; i <= option; i++) {
        memo[i] = -1;
    }

    printf("Fibonacci(%d) = %llu\n", option, fib(option, memo));

    return 0;
}