#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *result = malloc(sizeof(int) * 2);
	*returnSize = 2;
	for (int i = 0;i < numsSize;i++) {
		for (int j = i+1; j < numsSize;j++) {
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				break;
			}
		}
	}
	return result;
}
int main(void) {
	int array[] = {3,2,4};
	int size1 = 2;
	int *size = &size1;
	int *twoSumRes = twoSum(array,sizeof(array)/sizeof(array[0]),7,size);
	for (int i = 0; i < 2;i++) 
		printf("%d ",twoSumRes[i]);
	return 0;
}
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
