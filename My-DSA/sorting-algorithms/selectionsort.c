#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void isSorted(int *array, int numArray);
void printArray(int *array, int numArray, char *string);

int *selectionSort(int *array, int numArray) {
	int *sortedArray = malloc(sizeof(int)*numArray);
	memcpy(sortedArray,array,sizeof(int)*numArray);
	int min,minIndex,temp = 0;
	for (int i = 0; i < numArray;i++) {
		min = sortedArray[i];
		for (int j = i; j < numArray;j++) {
			if (sortedArray[j] <= min) {
				min = sortedArray[j];
				minIndex = j;
			}
		}
		temp = sortedArray[i];
		sortedArray[i] = sortedArray[minIndex];
		sortedArray[minIndex] = temp;
	}
	return sortedArray;
}
// 64, 25, 12, 22, 11
// 11, 25, 12, 22, 64
// 11, 12, 25, 22, 64
// 11, 12, 22, 25, 64
// 11, 12, 22, 25, 64
int main(void) {
	int unsortedArray[] = {64, 25, 12, 22, 11};
	int arraySize = sizeof(unsortedArray)/sizeof(unsortedArray[0]);
	int *sortedArray = selectionSort(unsortedArray,arraySize);
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
	isSorted(sortedArray,arraySize);
	return 0;
}
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