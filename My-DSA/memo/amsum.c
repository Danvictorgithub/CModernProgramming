#include <stdio.h>

int cansum(int target, int array[],int arrSize,int *memo) {
    int rem = 0;
    if (target == 0) {
        return 1;
    }
    if (target < 0) {
        return 0;
    }
    for (int i = 0; i < arrSize;i++) {
        if (memo[target] != -1) {
            rem = target - array[i];
            memo[target] = cansum(rem,array,arrSize,memo);
            if (memo[target] == 1) {
                return 1;
            }
        }
    }
}

int main() {
    int array[] = {5,3,4,7};
    int arrSize = sizeof(array, array[0]);
    int memo[arrSize] = {-1};
    printf("%d\n",cansum(7,array,arrSize,memo));
    return 0;
}
//Howsum