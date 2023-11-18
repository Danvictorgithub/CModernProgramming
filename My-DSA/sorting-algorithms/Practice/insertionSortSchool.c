#include <stdio.h>

void insertionSort(int *array, int size) {
    for (int i = 0; i < size-1; i++) {
        if (array[i] > array[i+1]) {
            for (int j = i+1; j > 0;j--) {
                if (array[j] < array[j-1]) {
                    array[j] = array[j] + array[j-1];
                    array[j-1] = array[j] - array[j-1];
                    array[j] = array[j] - array[j-1];
                }
            }
        }
    }
}

int main(void) {
    int array[] = {8,7,3,1,12,15};
    int sorted[] = {1,3,7,8,12,15};
    int size = sizeof(array)/sizeof(array[0]);
    int isSorted = 1;
    insertionSort(array,size);
    for (int i = 0; i < size;i++) {
        if (array[i] != sorted[i]) isSorted = 0;
        printf("%d ", array[i]);
    }
    if (isSorted) {
        printf("The array is sorted");
    }
    else {
        printf("The array is not sorted");
    }
    return 0;
}