#include <stdio.h>

int Factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n*Factorial(n-1);
	}
}

int main(int argc, char const *argv[])
{
	//prints of 0-9 factorial series
	for (int i = 0 ; i < 10;i++) {
		printf("%d ", Factorial(i));
	}
	return 0;
}