#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 10
#define NEXT(n) ((n+1) % BUFFER_SIZE) //calculates the next position
int size = 0/*,prev = 0*/;
int buffer[BUFFER_SIZE];
int enqueue(int value) {
    buffer[size++] = value;
}
int dequeue() {
    printf("%d\n",buffer[0]);
    for (int i = 0; i < BUFFER_SIZE-1;i++) {
        buffer[i] = buffer[i+1];
    }
    size--;
}
int isEmpty() {
    return size == 0;
}

void printfArray() {
    printf("\n");
    for (int i = 0; i < BUFFER_SIZE;i++) {
        printf("%d ",buffer[i]);
    }
    printf("\n");
    int temp;
    scanf("%d", &temp);
}

int main(void) {
    int opt = 0;
    int value;
    do {
    printf("1. Produce 2. Consume 3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        if (size == BUFFER_SIZE) {
            printf("Buffer is full\n");
            break;
        }
        printf("Enter the value: ");
        scanf("%d",&value);
        enqueue(value);
        break;
    case 2:
        if (size > 0) {
        printf("The value is \n");
        dequeue();
        } else {
            printf("Buffer is empty\n");
        }
        break;
    case 3:
        goto END;
    default:
        break;
    }
    printfArray();
    } while(opt == 1 || opt == 2);
    END:
    return 0;
}