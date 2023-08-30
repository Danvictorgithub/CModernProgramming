// CSC105 Endianess Problem - Dan Victor Lofranco 211-00842
#include <stdio.h>
void printLittleEndian(int n) {
    int tempArray[10] = {0};
    int i = 0;
    // Gets Individual Digit and stored in Array in reversed order
    for ( ; n != 0 ; i++) {
        tempArray[i] = n % 10;
        n /= 10;
    }
    // Prints the Array in reversed order
    printf("Little Endian: ");
    for (; i > 0 ;printf("%d ",tempArray[--i]));
    printf("\n");
}
void printBigEndian(int n) {
   int tempArray[10] = {0};
    int i = 0;
    // Gets Individual Digit and stored in Array in reversed order
    for ( ; n != 0 ; i++) {
        tempArray[i] = n % 10;
        n /= 10;
    }
    // Prints Array in normal order
    printf("Big Endian:    ");
    for (int j = 0 ; j != i ;printf("%d ",tempArray[j++]));
    printf("\n"); 
}
int main(void) {
    int value = 0;
    printf("Enter any numeric value: ");
    scanf("%d", &value);
    // Added Edge case if the input value is 0 to avoid Segmentation Fault
    (value != 0) ? printBigEndian(value),printLittleEndian(value):printf("Little Endian: 0\nBig Endian: 0\n");
    return 0;
}
