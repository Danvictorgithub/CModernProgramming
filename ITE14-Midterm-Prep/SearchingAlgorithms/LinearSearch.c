#include <stdio.h>

int LinearSearch(int array[], int size,int item) {
	//LinearSearch -> a[], s => -1 || index
	int index = -1;
	for (int i = 0 ; i < size;i++) {
		if (array[i] == item) {
			index = i;
			break;
		}
	}
	return index;
}

int main(void) {
	int array[] = {1,6,8,2,3,9,10,5}; // non ordered-list
	printf("Search(11): %d\n",LinearSearch(array,8,11));
	printf("Search(1): %d\n",LinearSearch(array,8,1));
	printf("Search(9): %d\n",LinearSearch(array,8,9));


}