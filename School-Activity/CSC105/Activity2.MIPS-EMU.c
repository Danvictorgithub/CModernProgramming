#include <stdio.h>

void intToBinary(int n) {
    int fiveBits[5] = {0};
    for (int i = 4; n != 0;i--) {
        fiveBits[i] = n%2;
        n /= 2;
    }
    for (int i = 0;i < 5;i++){
        printf("%d",fiveBits[i]);
    }
}

int main(void) {
    int option;

    printf("Enter value: ");
    scanf("r%d",&option);
    if (option >= 0 || option < 32) {
        printf("Output: You have entered register number %d with machine code equivalent of ",option);
        intToBinary(option);
        printf(", a five bits representation\n");
    }
    else {
        printf("Invalid Register\n");
    }
    return 0;
}