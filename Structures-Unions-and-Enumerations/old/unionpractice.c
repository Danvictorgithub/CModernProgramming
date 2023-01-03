#include <stdio.h>

int main(void) {
	// union {
	// 	int i;
	// 	double d;
	// } u;
	// u.i = 25;
	// u.d = 69.4;
	// int variable = (int) u.d;
	// printf("%d", variable);

	typedef union {
		int i;
		double d;
	} Number;
	Number number_array[1000];
	number_array[0].i = 69;
	number_array[1].d = 4.20;
	printf("%d %f", number_array[0].i, number_array[1].d);
	return 0;	
}