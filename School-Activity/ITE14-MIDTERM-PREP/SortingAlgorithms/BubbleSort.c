#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //memcpy
void printArray(int array[],int size) {
	for (int i = 0; i < size;i++) {printf("%d ",array[i]);}
	printf("\n");
}

int *BubbleSort(int array[],int size) {
	int *sortedArray = malloc(sizeof(int)*size);
	memcpy(sortedArray,array,sizeof(int)*size);
	int swapped = 0;
	int temp;
	for (int i = 0; i < size-1; i++) {
		if (sortedArray[i] > sortedArray[i+1]) {
			temp = sortedArray[i];
			sortedArray[i] = sortedArray[i+1];
			sortedArray[i+1] = temp;
			swapped = 1;
		}
		else {
			continue;
		}
	}
	if (swapped) {
		BubbleSort(sortedArray,size);
	}
	else {
		return sortedArray;
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {9,1,5,2,4,8,7,3,6,10};
	int *array2 = BubbleSort(array,10);	
	printArray(array2,10);
	return 0;
}