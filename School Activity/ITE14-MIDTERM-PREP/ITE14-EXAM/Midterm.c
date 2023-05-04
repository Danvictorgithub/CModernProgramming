#include <stdio.h>

int sumSubArray(int array[], int startIndex,int endIndex) {
	//sums subArray based on startIndex and endIndex
	int Sum = 0;
	for (int i = startIndex; i <= endIndex;i++) {
		Sum += array[i];
	}
	return Sum;
}
// maxSubArray -> int array[], int size => prints the index range of best maxSubArray 
void maxSubArray(int array[],int size) {
	int startIndex = 0,endIndex = 0,maxValue = 0;
	int sumValue;
	for (int i = 0,j; i < size; i++) {
		for (j = i; j < size;j++) { //the i and j generates range to sum
			// once i and j is identified, summation is involved from i to j
			sumValue = sumSubArray(array,i,j);
			// checks if the initial sumValue is greater than the maxValue else change it
			if (sumValue > maxValue) {
			maxValue = sumValue;
			startIndex = i;
			endIndex = j;
			}
		}
	}
	printf("Max Value: %d\n",maxValue);
	printf("From %d to %d\n", startIndex,endIndex);
}
//Helper Function
int testSum(int array[],int startIndex,int endIndex) {
	int result = 0;
	for (int i = startIndex; i <= endIndex;i++) {
		printf("adding %d\n", array[i]);
		result += array[i];
	}
	return result;
}
int main(void)
{
	//-2,1,-3,4,-1,2,1,-4,
	int array[] = {-2,1,-3,4,-1,2,1,-5,4};
	maxSubArray(array,sizeof(array)/sizeof(array[0]));
	//test-case best result 3 to 6
	// printf("%d",testSum(array,3,6));
	return 0;
}
