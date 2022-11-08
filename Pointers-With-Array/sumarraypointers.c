#include <stdio.h>

int main(void)
{	

	int *a = (int []){1,2,3,4,5,6,7,8,9,10};
	int sum = 0;
	for (int *p = a; p < &a[10];p++)
		sum += *p;
	printf("%d",sum);


	return 0;
}