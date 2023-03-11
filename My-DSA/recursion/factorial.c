#include <stdio.h>

int factorial(int n) {
	if (n < 0) {
		return -1;
	}
	if (n==0) {
		return 1;
	}
	else {
		return n*factorial(n-1);
	}
}

int main(void) {
	printf("%d",factorial(-10));
	return 0;
}