#include <stdio.h>

int binarySearch(int sortedArray[],int num, int size) {
	int h,l,m;
	h = size;
	l = 0;
	m = (l + h)/2;

	int flagFound = 0;
	// scanf("%d",&num);
	while (l <= h) {
		m = (l + h)/2;
		if (sortedArray[m] == num) {
			flagFound = 1;
			break;
		}
		else if (sortedArray[m] > num) {
			h = m-1;
			// printf("%d\n",sortedArray[m]);
		}
		else {
			l = m+1;
			// printf("%d\n",sortedArray[m]);
		}
	}
	if (flagFound) {
		printf("found at index %d\n",m);
		return 1;
	}
	else {
		printf("Doesn't exist in array\n");
		return -1;
	}
}
int main(void) {
	// Binary Search Test
	int sortedArray[] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; i++) {
		binarySearch(sortedArray,sortedArray[i],10-1);
	}
}