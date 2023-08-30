// CSC105 Endianess Problem - Dan Victor Lofranco 211-00842
#include <stdio.h>
void printLittleEndian(int n) {
    int tempArray[10] = {0};
    int i = 0;
    for ( ; n != 0 ; i++) {
        tempArray[i] = n % 10;
        n /= 10;
    }
    printf("Little Endian: ");
    for (; i > 0 ;printf("%d ",tempArray[--i]));
    printf("\n");
}
void printBigEndian(int n) {
   int tempArray[10] = {0};
    int i = 0;
    for ( ; n != 0 ; i++) {
        tempArray[i] = n % 10;
        n /= 10;
    }
    printf("Big Endian: ");
    for (int j = 0 ; j != i ;printf("%d ",tempArray[j++]));
    printf("\n"); 
}
int main(void) {
    int value = 0;
    printf("Enter any numeric value: ");
    scanf("%d", &value);
    (value != 0) ? printLittleEndian(value),printBigEndian(value):printf("Little Endian: 0\nBig Endian: 0\n");
    return 0;
}
