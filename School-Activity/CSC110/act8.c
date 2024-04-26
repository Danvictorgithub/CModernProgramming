#include <stdio.h>
#include <stdlib.h>

int main(void){
    int totalMem;
    int remainingMem;
    int noProcess = 0;
    int memoryAllocated[100] = {0};
    char opt;
    int mem;
    int invalidInput = 0;
    // int memFull = 0;
    printf("Enter the total memory available (in Bytes) -- ");
    scanf("%d",&totalMem);
    remainingMem = totalMem;
    do {
        printf("Enter memory required for process %d (in Bytes) -- ",noProcess + 1);
        scanf("%d",&mem);
        if (mem <= remainingMem) {
            remainingMem -= mem;
            memoryAllocated[noProcess++] = mem;
            if (remainingMem <= 0) {
                goto end;
            }
            invalid:
            if (invalidInput) {
                printf("Invalid input\n");
                invalidInput  = 0;
            }
            printf("Do you want to continue(y/n) -- ");
            scanf(" %c",&opt);
            if (opt == 'y') {
            }
            else if (opt == 'n') {
            }
            else {
                invalidInput = 1;
                goto invalid;
            }
        }
        else {
            end:
            printf("Memory is Full\n");
            break;
        }
    } while (opt == 'y');
    printf("\nTOtal Memory Available -- %d\n",totalMem);
    printf("%s%20s","PROCESS","MEMORY-ALLOCATED\n");
    for (int i = 0; i < noProcess;i++){
        printf("%d%20d\n",i+1,memoryAllocated[i]);
    }
    printf("Total Memory Allocated is %d\n",totalMem - remainingMem);
    printf("Total External Fragmentation is %d\n",remainingMem);
    return 0;
}