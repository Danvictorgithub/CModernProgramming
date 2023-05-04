#include <stdio.h>

int Euler(int a,int b) {
	// if (a % b == 0) {
	// 	return b;
	// }
	// else {
	// 	Euler(b,a % b);
	// }

	//one liner
	return (a % b == 0) ? b:Euler(b,a % b);
}

int main(int argc, char const *argv[])
{
	printf("GCD(560,120): %d",Euler(560,120));
	return 0;
}