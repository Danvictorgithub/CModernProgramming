#include <stdio.h>
int fib(int n) {
	// if (n < 0) {
	// 	return 0;
	// }
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return fib(n-1)+fib(n-2);
	}
}
int main(void) {
	for (int i = 0; i < 8; i++) {
		printf("%d ",fib(-1));
	}
	return 0;
}