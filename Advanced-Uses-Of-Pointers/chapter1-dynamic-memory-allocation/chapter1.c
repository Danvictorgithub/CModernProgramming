#include <stdio.h>
#include <stdlib.h> /*This is the library used for memory allocation*/

// # Memory Allocation Functions
	// malloc - Allocates a block of memory but doesn't initialize it
	// calloc - Alloctes a block of memory and clears it
	// realloc - Resizes a previously allocated block of memory

int main(void) {
	int *p = malloc(10000);
	if (p == NULL) {
		printf("Memory Allocation failed unexpectedly");
		exit(EXIT_FAILURE);
	}
	return 0;
}
// Notes: When testing Memory allocation it is recommended to create test to
// Check if the memory allocation function is successful by checking if it is 
// Not Null