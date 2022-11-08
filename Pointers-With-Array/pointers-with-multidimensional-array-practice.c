#include <stdio.h>
// Passing MultiDimensional Array to a SingleDimensional Array Function
int largestNumber(int array[], int arraysize) {
	int largest = 0;
	for (int *p = array; p < array + arraysize; p++)
		if (*p > largest)
			largest = *p;
	return largest;
}

int main(void) {
	// Printing Rows Only
	// int array[3][3] = {
	// 				1,2,3,
	// 				4,5,6,
	// 				7,8,9
	// 				};
	
	// for (int *p = array[0];p < array[0] + 3;p++)
	// 	printf("%d", *p);

	// Printing Columns Only
	// int array[3][3] = {
	// 				1,2,3,
	// 				4,5,6,
	// 				7,8,9
	// 				};
	
	// for (int (*p)[3] = array; p < array + 3; p++)
	// 	printf("%d", **p);


	// Pretends MultiDimensional Array as a SingleDimensional Array
	int array[3][3] = {1,2,3,4,5,6,7,8,9};
	printf("%d",largestNumber(array[0],3*3));
	return 0;
}