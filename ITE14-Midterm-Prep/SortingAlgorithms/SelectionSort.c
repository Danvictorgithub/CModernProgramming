#include <stdio.h>
#include <stdlib.h> //malloc
// #include <stddef.h> //NULL
#include <string.h> //memcpy
void printArray(int array[],int size) {
	for (int i = 0; i < size;i++) {printf("%d ",array[i]);}
	printf("\n");
}

int *SelectionSort(int array[], int size) {
	// copies array
	int *sortedArray = malloc(sizeof(int)*size);
	memcpy(sortedArray,array,sizeof(int)*5);

	int minIndex = 0;
	int temp = 0;
	for (int i = 0; i < 5;i++) {
		minIndex = i; // minimum number base
		for (int j = i+1; j < 5; j++) {
			if (sortedArray[minIndex] > sortedArray[j]) {
				// changes index if the minimum base is greater than the current array value
				minIndex = j;
			}
		}
		if (i == minIndex) { //if case is optional but good for average-case
			continue;
		}
		else {
			//swaps smallest number with the current i index
			temp = sortedArray[i];
			sortedArray[i] = sortedArray[minIndex];
			sortedArray[minIndex] = temp;
		}
	}
	return sortedArray;
}
int main(int argc, char const *argv[])
{
	int array[] = {5,1,3,2,4};
	int *array2 = SelectionSort(array,5);
	printArray(array2,5);
	return 0;
}