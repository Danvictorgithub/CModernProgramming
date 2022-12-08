#include <stdio.h>
#include <stdlib.h> //malloc
int *selectionSort(int *array, int arraySize) {
	int *sortedArray = malloc(sizeof(int)*arraySize);
	int min = 0, minIndex;
	int i,j;
	int currentArraySize = arraySize;
	for (i = 0; i < arraySize;i++) {
		min = array[0];
		for (j = 0; j < currentArraySize;j++) {
			if (min >= array[j]) {
				min = array[j];
				minIndex = j;
			}
		}
		sortedArray[i] = min;
		currentArraySize--;
		for (j = minIndex; j < currentArraySize;j++) {
			array[j] = array[j+1];
		}
	}
	return sortedArray;
}

void printArray(int *array, int arraySize) {
	int i;	for( i = 0 ; i < arraySize ;i++) {
		printf("%d ",array[i]);
	}
	printf("%\n");
}

int main(void) {
	int array[5] = { 3,4,2,1,7};
	printArray(array, sizeof(array)/sizeof(array[0]));
	int *newArray = selectionSort(array,sizeof(array)/sizeof(array[0]));
	printArray(newArray, sizeof(array)/sizeof(array[0]));
	return 0;

}