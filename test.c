#include <stdio.h>

int main()
{
	int n[3][3] = {
		2,4,3,
		6,8,5,
		3,5,1
	};
	int i, *ptr;
	ptr = (int *) n;
	for (i = 0; i<= 8; i++)
		printf("%d", ptr[i]);
	return 0;
}