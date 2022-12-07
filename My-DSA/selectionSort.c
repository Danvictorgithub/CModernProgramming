#include <stdio.h>
#include <stdlib.h> //malloc
void selectionSort(int *array, int arraySize) {
	int *sortedArray = malloc(sizeof(int)*arraySize);
	int min;
	int i;
	for (i = 0; i < arraySize;i++) {

	}
}

void printArray(int *array, int arraySize) {
	int i;	for( i = 0 ; i < arraySize ;i++) {
		printf("%d ",array[i]);
	}
	printf("%\n");
}

int main(void) {
	int array[5] = { 3,4,2,1,7};
	// printArray(array, sizeof(array)/sizeof(array[0]));
	// selectionSort(array,sizeof(array)/sizeof(array[0]));
	// printArray(array, sizeof(array)/sizeof(array[0]));
	return 0;

}