#include <stdio.h>
void printArray(int *array, int size) {
    for (int i = 0 ;i < size;i++) printf("%d ",array[i]);
    printf("\n");
}
void selectionSort(int *array, int size) {
    int temp,min = 0;
    printArray(array,size);
    for (int i = 0, j = 0; i < size; i++) {
        min = i;
        for (j = i;j < size;j++) {
            // printf("comparing:%d and %d", array[sizeJ])
            
            if (array[j] < array[(j+1)%size]) {
                min = j;
                break;
            }
        }
        if (j == size) { // already sorted
            break;
        }
        if (min == i) { // not found a min
            continue;
        }
        //Swapping w/o temp
        temp = array[i];
		array[i] = array[min];
		array[min] = temp;
        printArray(array,size);
    } 
}

int main(void) {
    int array[] = {1,7,6,8,12,10};
    int sortedArray[] = {0,3,7,8,12,15};
    int size = sizeof(array)/sizeof(array[0]);
    selectionSort(array,size);
    int isSorted = 1;
    for (int i = 0; i < size; i++) {
        if (array[i] != sortedArray[i]) {
            isSorted = 0;
        }
        // printf("%d ",array[i]);
    }
    return 0;
}