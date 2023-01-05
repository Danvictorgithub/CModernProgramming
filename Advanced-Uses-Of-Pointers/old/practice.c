#include <stdio.h>


int main(void) {
	struct book{
		float x,y,z;
	} s[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8};
	int *i;
	i = s;
	printf("%f", s[ (int)(s + 2)->y / 3[ i ] ].y);

	return 0;
}