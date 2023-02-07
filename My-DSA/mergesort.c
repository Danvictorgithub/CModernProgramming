#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void isSorted(int *array, int numArray);
void printArray(int *array, int numArray, char *string);

int *mergeSort(int *array, int numArray) {
	int *sortedArray = malloc(sizeof(int)*numArray);
	memcpy(sortedArray,array,sizeof(int)*numArray);
	return sortedArray;
}

int main(void) {
	int unsortedArray[] = {12,11,13,5,6};
	int *sortedArray = mergeSort(unsortedArray,sizeof(unsortedArray)/sizeof(unsortedArray[0]));
	printArray(
		unsortedArray,
		sizeof(unsortedArray)/sizeof(unsortedArray[0]),
		"Unsorted Array:"
	);
	printArray(	
		sortedArray,
		sizeof(unsortedArray)/sizeof(unsortedArray[0]),
		"Sorted Array:"
	);
	isSorted(sortedArray, sizeof(unsortedArray)/sizeof(unsortedArray[0]));
	return 0;
}
// Helper Functions
int comparator(const void *a, const void *b);

void isSorted(int *array, int numArray) {
	int *sortedArray = malloc(sizeof(int)*numArray);
	int sortedFlag = 1;
	memcpy(sortedArray,array,sizeof(int)*numArray);
	qsort(sortedArray,numArray,sizeof(int),comparator);
	for (int i = 0; i < numArray;i++) {
		if (sortedArray[i] != array[i]) {
			sortedFlag = 0;
			break;
		} 
	}
	if (sortedFlag) {
		printf("The array is sorted");
	}
	else {
		printf("the array is not sorted");
	}
}
int comparator(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}
void printArray(int *array, int numArray,char *string) {
	printf("%s\n",string);
	printf("{");
	for(int i = 0; i < numArray; i++) {
		if (i != numArray -1) {
			printf("%d,",array[i]);
		}
		else {
			printf("%d",array[i]);
		}
	}
	printf("}\n\n");
}