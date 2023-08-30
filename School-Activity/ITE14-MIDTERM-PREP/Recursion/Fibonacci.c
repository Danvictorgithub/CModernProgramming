#include <stdio.h>

int Fibonnaci(int n) {
	if (n < 0) { // edge-case
		return 0;
	}
	else if (n == 1){
		return n;
	}
	else {
		return Fibonnaci(n-2)+Fibonnaci(n-1);
	}
}

int main(int argc, char const *argv[])
{
	// prints the first 10 fibonacci numbers
	for (int i = 0;i < 10;i++) {
		printf("%d ",Fibonnaci(i));
	}
	return 0;
}