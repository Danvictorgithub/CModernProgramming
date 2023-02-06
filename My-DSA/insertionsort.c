#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printArray(int *, int, char *);
void isSorted(int *, int );
int *insertionSort(int *unsortedArray, int numArray) {
	int *sortedArray = malloc(sizeof(int)*numArray);
	memcpy(sortedArray,unsortedArray,numArray*sizeof(int));
	for (int i = 0, temp; i < numArray-1; i++) {
		if (sortedArray[i] > sortedArray[i+1]) {
			for (int j = i+1;j >= 1;j--) {
				if (sortedArray[j] < sortedArray[j-1]) {
					temp = sortedArray[j-1];
					sortedArray[j-1] = sortedArray[j];
					sortedArray[j] = temp;
				}
			}
		}
	}
	return sortedArray;
}
// 12,11,13,5,6
// 11,12,13,5,6
// 11,12,5,13,6
// 11,5,12,13,6
// 5,11,12,13,6
// 5,11,12,6,13
// 5,11,6,12,13
// 5,6,11,12,13
int main(void) {
	int unsortedArray[] = {12,11,13,5,6};
	int *sortedArray = insertionSort(unsortedArray,sizeof(unsortedArray)/sizeof(unsortedArray[0]));
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
// Helper Function
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
	printf("}\n");
}
int comparator(const void *, const void *);
void isSorted(int *array, int numArray) {
	int *sortedArray;
	memcpy(sortedArray,array,sizeof(int)*numArray);
	qsort(array,numArray,sizeof(int),comparator);
	int sortedFlag = 1;
	for (int i = 0; i < numArray;i++) {
		if (sortedArray[i] != array[i]) {
			sortedFlag = 0;
			break;
		}
	}
	if (sortedFlag){
		printf("The array is sorted");
	}
	else {
		printf("The array is not sorted");
	}
}
int comparator(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}