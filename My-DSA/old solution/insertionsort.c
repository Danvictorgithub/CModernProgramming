#include <stdio.h>
void insertionSort(int *array, int arraySize) {
	int i,j;
	for (i = 0; i < arraySize;i++) {
		for (j = 0; j < arraySize;j++) {
			
		}
	}
}
void printArray(int *array, int arraySize) {
	int i;	for( i = 0 ; i < arraySize ;i++) {
		printf("%d ",array[i]);
	}
	printf("%\n");
}

int main() {
	int array[5] = { 3,4,2,1,7};
	printArray(array, sizeof(array)/sizeof(array[0]));
	insertionSort(array, sizeof(array)/sizeof(array[0]));
	printArray(array, sizeof(array)/sizeof(array[0]));
	return 0;
}