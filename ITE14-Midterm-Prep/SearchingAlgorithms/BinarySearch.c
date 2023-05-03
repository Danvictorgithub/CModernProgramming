#include <stdio.h>

int BinarySearch(int array[], int size, int item) {
	int index = -1;
	int high = size-1;
	int low	= 0;
	int mid;
	while (low <= high) {
		mid = (high+low)/2;
		if (array[mid] == item) {
			index = mid;
			break;
		}
		else if (array[mid] > item) {
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	return index;
}

int main(int argc, char const *argv[])
{
	int array[] = {1,2,3,4,5,6,7,8,9,10}; //ordered list
	printf("Search(5): %d\n",BinarySearch(array,10,5));
	printf("Search(7): %d\n",BinarySearch(array,10,7));
	printf("Search(2): %d\n",BinarySearch(array,10,2));
	printf("Search(-1): %d\n",BinarySearch(array,10,-1));
	return 0;
}