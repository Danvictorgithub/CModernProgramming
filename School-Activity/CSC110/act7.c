#include <stdio.h>

int main(void){
    int totalMem;
    int blockSize;
    int numProcess;

    printf("Enter the total memory available (in Bytes): ");
    scanf("%d",&totalMem);
    printf("Enter the block size (in Bytes): ");
    scanf("%d", &blockSize);
    printf("Enter the number of processes: ");
    scanf("%d", &numProcess);

    int numBlock = totalMem / blockSize;
    int totalExtFragmentation = totalMem - (numBlock * blockSize);
    int totalIntFragmentation = 0;
    int processArr[numProcess];
    for (int i = 0; i < numProcess;i++) {
        printf("Enter memory required for process %d (in Bytes): ",i+1);
        scanf("%d",&processArr[i]);
    }
    printf("\nNo. of Blocks available in memory %d\n",numBlock);
    for (int i = 0; numProcess > 0;i++, numProcess--) {
        if (numBlock <= 0 && numProcess >= 0) {
            printf("Memory is Full. Remaining Processes cannot be accommodated\n");
            break;
        }
        else if (numBlock <= 0 && numProcess <= 0){
            break;
        }
            printf("%s%20s%20s%20s\n","Process","Mem Required", "Allocated", "Int Fragmentation");
        if (processArr[i] <= blockSize) {
            int fragmentationDiff = blockSize - processArr[i];
            printf("%d%20d%20s%20d\n",i+1,processArr[i],"YES",fragmentationDiff);
            totalIntFragmentation += fragmentationDiff;
            numBlock--;
        }
        else {
            printf("%d%20d%20s%20s\n",i+1,processArr[i],"NO","---");
        }
            
    }
    if (numProcess > 0 && numBlock <= 0) {
        printf("There are %d process remaining\n",numProcess);
    }
        if (numProcess < 0 && numBlock >= 0) {
        printf("There are %d blocks remaining\n",numBlock);
    }
    printf("\nTotal Internal Fragmentation is %d\n",totalIntFragmentation);
    printf("Total External Fragmentation is %d\n",totalExtFragmentation);
    return 0;
}