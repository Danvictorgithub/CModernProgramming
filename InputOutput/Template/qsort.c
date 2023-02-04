#include <stdio.h>
#include <stdlib.h>

int comparator (const void * p1, const void * p2) {
	return (*(int*)p1 - *(int*)p2);
}
int main(void) {
	int array[] = {6,3,12,41,5,11,8};
	qsort(array, 7, sizeof(int),comparator);
	for (int i = 0; i < sizeof(array)/sizeof(int);i++)
		printf("%d\n",array[i]);
	return 0;
}