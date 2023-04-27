#include <stdio.h>

int binarySearch(int *array, int size, int search) {
	int l,m,h;
	l = 0;
	h = size-1;
	m = (h + l) / 2;
	int found = 0;
	// printf("%d",m);
	while (l <= h) {
		m = (h + l) / 2;
		if (array[m] == search) {
			found = 1;
			break;
		}
		else if (array[m] > search) {
			h = m-1;
		}
		else {
			l = m+1;
		}
	}
	if (found) {
		printf("found at index %d",m);
	}
	else {
		printf("%d does not exist in the array", search);
	}
}
int main(void) {
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	binarySearch(array,10,4);
	printf("\nHello World");
	return 0;
}