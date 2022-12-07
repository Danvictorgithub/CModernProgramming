#include <stdio.h>
void bubbleSort(int *array,int arraysize) {
	int i, switched = 0, temp;
	for (i = 0; i < arraysize-1; i++) {
		if (array[i] > array[i+1]) {
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
			switched = 1;
		}
	} 
	if (switched) {
		bubbleSort(array, arraysize);
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
	printArray(array, sizeof(array)/sizeof(array[0]));
	bubbleSort(array,sizeof(array)/sizeof(array[0]));
	printArray(array, sizeof(array)/sizeof(array[0]));
	return 0;
}