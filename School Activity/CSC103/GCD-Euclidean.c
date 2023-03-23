#include <stdio.h>

int gcd(int num1, int num2) {
	if (num2 == 0) {
		return num1;
	}
	else {
		return gcd(num2, num1 % num2);
	}
}
int gcdWhile(int num1,int num2) {
	// int temp;
	while (num2 !=0) {
		num2 = num2*num1;
		num1 = num2/num1;
		num2 = num2/num1;
		num2 = (num2 % num1);
	}
	return num1;
}
// int gcdFor(int num1,num2) {

// }
int gcdTest(int output, int expectedVal) {
	if (expectedVal == output) {
		return 1;
	}
	else {
		return 0;
	}
}
int main(void) {
	printf("%d",gcdWhile(27,33));
	// int num1 = 15;
	// int num2 = 10;
	// num1 = num1*num2;
	// num2 = num1/num2;
	// num1 = num1/num2;
	// printf("%d %d", num1,num2);
}