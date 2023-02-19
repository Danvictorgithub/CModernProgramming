#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void isSorted(int *array, int numArray);
void printArray(int *array, int numArray, char *string);

void merge(int *array, int left_sIndex, int left_lIndex, int right_sIndex, int right_lIndex) {
	int leftSize = left_lIndex - left_sIndex;
	int rightSize = right_lIndex - right_sIndex;
	int left_tempArray[leftSize];
	int right_tempArray[rightSize];
	int l = 0, r = 0;
	// printf("Left Array: ");
	for (int i = 0; i <= leftSize;i++) {
		left_tempArray[i] = array[left_sIndex+i];
		// printf("%d ",left_tempArray[i]);
	}
	// printf("\n");
	// printf("Right Array: ");
	for (int i = 0; i <= rightSize;i++) {
		right_tempArray[i] = array[right_sIndex+i];
		// printf("%d ",right_tempArray[i]);
	}
	printf("\n");
	while (l <= leftSize && r <= rightSize) {
		// printf("comparing [%d] and [%d]\n",left_tempArray[l],right_tempArray[r]);
		if (left_tempArray[l] < right_tempArray[r]) {
			// printf("left is lesser\n");
			array[left_sIndex] = left_tempArray[l];
			l++;
			left_sIndex++;
			// printf("array update:\n");
			// for (int i = 0; i < 8;i++) {
			// 	// printf("%d ",array[i]);
			// }
			// printf("\n");
			}
		else {
			// printf("right is lesser\n");
			array[left_sIndex] = right_tempArray[r];
			r++;
			left_sIndex++;
			// printf("array update:\n");
			// for (int i = 0; i < 8;i++) {
			// 	printf("%d ",array[i]);
			// }
			// printf("\n");
		}
	}
	while (l <= leftSize) {
		array[left_sIndex] = left_tempArray[l];
			l++;
			left_sIndex++;
			// printf("array update:\n");
			for (int i = 0; i < 8;i++) {
				// printf("%d ",array[i]);
			}
			// printf("\n");
	}
	while (r <= rightSize) {
		array[left_sIndex] = right_tempArray[r];
			r++;
			left_sIndex++;
			// printf("array update:\n");
			for (int i = 0; i < 8;i++) {
				// printf("%d ",array[i]);
			}
			// printf("\n");
	}
	// printf("array result:\n");
	// for (int i = 0; i < 8;i++) {
	// 	printf("%d ",array[i]);
	// }
	// printf("\n");
}
void mergeSort(int *array,int sIndex, int lIndex) {
	if (lIndex - sIndex == 0) {
		// printf("sIndex:%d   lIndex:%d ",sIndex,lIndex);
		// printf("Ended\n");
	}
	else {
		int divider = (int)((lIndex-sIndex) / 2);
		// printf("sIndex:%d   lIndex:%d ",sIndex,lIndex);
		// printf("divider:%d\n",divider);
		mergeSort(array,sIndex,lIndex-divider-1);
		mergeSort(array,sIndex+divider+1,lIndex);

		merge(array, sIndex,lIndex-divider-1,sIndex+divider+1,lIndex);

	}
}

int main(void) {
	int unsortedArray[] = {1,5,4,8,3,7,2,6};
	int *sortedArray = malloc(sizeof(int)*8);
	memcpy(sortedArray,unsortedArray,sizeof(int)*8);
	printArray(	
		sortedArray,
		sizeof(unsortedArray)/sizeof(unsortedArray[0]),
		"Sorted Array:"
	);
	mergeSort(sortedArray,0,7);
	printArray(
		unsortedArray,
		sizeof(unsortedArray)/sizeof(unsortedArray[0]),
		"Unsorted Array:"
	);
	printArray(	
		sortedArray,
		sizeof(unsortedArray)/sizeof(unsortedArray[0]),
		"Sorted Array:MERGED"
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