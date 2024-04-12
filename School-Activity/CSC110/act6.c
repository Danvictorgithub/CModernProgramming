#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct process {
    int id;
    int arrivalTime;
    int burstTime;
    int done;
};
struct process *insertionSort(struct process *unsortedArray, int numArray) {
	struct process *sortedArray = malloc(sizeof(struct process)*numArray);
	memcpy(sortedArray,unsortedArray,numArray*sizeof(struct process));
    struct process temp;
	for (int i = 0; i < numArray-1; i++) {
		if (sortedArray[i].burstTime > sortedArray[i+1].burstTime) {
			for (int j = i+1;j >= 1;j--) {
				if (sortedArray[j].burstTime < sortedArray[j-1].burstTime) {
					temp = sortedArray[j-1];
					sortedArray[j-1] = sortedArray[j];
					sortedArray[j] = temp;
				}
			}
		}
	}
	return sortedArray;
}
struct process *insertionSortByArrivalTime(struct process *unsortedArray, int numArray) {
	struct process *sortedArray = malloc(sizeof(struct process)*numArray);
	memcpy(sortedArray,unsortedArray,numArray*sizeof(struct process));
    struct process temp;
	for (int i = 0; i < numArray-1; i++) {
		if (sortedArray[i].arrivalTime > sortedArray[i+1].arrivalTime) {
			for (int j = i+1;j >= 1;j--) {
				if (sortedArray[j].arrivalTime < sortedArray[j-1].arrivalTime) {
					temp = sortedArray[j-1];
					sortedArray[j-1] = sortedArray[j];
					sortedArray[j] = temp;
				}
			}
		}
	}
	return sortedArray;
}
//helper function

void printArray(struct process array[],int numArray) {
    for (int i = 0; i < numArray;i++) {
        printf("\n{\n");
        printf("\tid: %d\n",array[i].id);
        printf("\tarrivalTime: %d\n",array[i].arrivalTime);
        printf("\tburstTime: %d\n",array[i].burstTime);
        printf("\tdone: %d\n",array[i].done);
        printf("}\n");
    }
}

int isProcessFinished(struct process array[], int numArray) {
    for (int i = 0;i < numArray; i++) {
       if (array[i].done == 0) {
        return 0;
       }
    }
    return 1;
}

int slotIndex = 0;
int *getArrivalTimeArray(struct process array[],int numArray) {
    int slot[100];
    for (int i = 0; i < numArray;i++) {
        int unique = 1;
        for (int j = 0; j < slotIndex;j++) {
            if (array[i].arrivalTime == slot[j]) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            slot[slotIndex++] = array[i].arrivalTime;
        }
    }
    for (int i = 3; i < 3;i++){
        printf("%d",slot[i]);
    }
    int *slotMemory = malloc(sizeof(int)*slotIndex);
    memcpy(slotMemory,slot,sizeof(int)*slotIndex);
    return slotMemory;
}

// Edge Cases
// 1. arrive
// 2. done

int main(void) {
    int timeFrame = 0;
    int numberOfProcess = 0;
    int size;
    struct process processArrayInput[100] = {};
    struct process processArray[100] = {};

    int error = 0;
    int increment = 0;
    int input;
    printf("Enter number of process: ");
    scanf("%d",&size);
    for (int i = 0; i < size;i++) {
        do {
            if (error) {
                printf("Invalid input\n");
            }
            error = 0;
            printf("Enter process [id]: ");
            scanf("%d",&input);
            for (int j = 0; j < increment;j++) {
                if (input == processArrayInput[j].id) {
                    error = 1;
                    break;
                }
            }
        } while (error);
        increment++;
        processArrayInput[i].id = input;
        printf("Enter process [%d] arrival time: ",processArrayInput[i].id);
        scanf("%d",&processArrayInput[i].arrivalTime);
        printf("Enter process [%d] burst time: ",processArrayInput[i].id);
        scanf("%d",&processArrayInput[i].burstTime);
        processArrayInput[i].done = 0;
    }
    memcpy(processArrayInput,insertionSortByArrivalTime(processArrayInput,size),sizeof(struct process)*size);
    int waitingTimeArray[100] = {};
    int waitingTimeSize = 0;
    float WaitingTimeAvg;
    
    int turnAroundTimeArray[100] = {};
    int turnAroundTimeSize = 0;
    float TurnaroundTimeAvg;

    int waitingTimeInterval = 0;
    int *arrivalTimeFrameArray = getArrivalTimeArray(processArrayInput,size);
    int arrivalTimeFrameArrayIndex = 0;


    printf("\n%s%20s%20s%20s\n","Process","Burst Time", "Waiting Time","Turn-around Time");
    int referenceProcess = -1;
    int referenceProcessTemp = -1;
    while (!isProcessFinished(processArrayInput,size)) {
        // if within the arrival time frame, a new process will be added to the processArray
        if (timeFrame == arrivalTimeFrameArray[arrivalTimeFrameArrayIndex]) {
            for (int i = 0; i < size;i++) {
                if (processArrayInput[i].arrivalTime == timeFrame) {
                    processArray[numberOfProcess++] = processArrayInput[i];
                }
            }
            arrivalTimeFrameArrayIndex++;
        }
        if (numberOfProcess <= 0) {
            timeFrame++;
            // If empty also update the waiting time interval
            waitingTimeInterval = timeFrame;
            continue;
        }
        // This will hold if the process is replaced by another process
        referenceProcess = processArray[0].id;
        memcpy(processArray,insertionSort(processArray,numberOfProcess),sizeof(struct process)*numberOfProcess);
        if (referenceProcess != processArray[0].id) {
            // If replaced by another process print
            for (int i = 0; i < numberOfProcess;i++){
                if (processArray[i].id == referenceProcess) {
                    referenceProcessTemp = i;
                    break;
                }
            }
            // int relProcessArrayTemp;
            // for (int i = 0; i < numberOfProcess;i++) {
            //     if ( processArrayInput[i].id == processArray[referenceProcessTemp].id) {
            //         relProcessArrayTemp = i;
            //         break;
            //     }
            // }
            // printf("this is called %d %d - %d", relProcessArrayTemp, processArrayInput[relProcessArrayTemp].burstTime, processArray[referenceProcessTemp].burstTime);
            printf("P%d",processArray[referenceProcessTemp].id);
            printf("%20d", timeFrame - waitingTimeInterval);
            printf("%20d",waitingTimeInterval);
            printf("%20d",timeFrame);
            printf("\n");
            waitingTimeArray[waitingTimeSize] = waitingTimeInterval;
            waitingTimeSize += 1;
            turnAroundTimeArray[turnAroundTimeSize] = timeFrame;  
            turnAroundTimeSize += 1;
            waitingTimeInterval = timeFrame;
        }
        // if done
        if (processArray[0].burstTime == 0) {
            // int relProcessArrayTemp;
            for (int i = 0; i < size;i++){
                if (processArrayInput[i].id == processArray[0].id) {
                    // relProcessArrayTemp = i;
                    processArrayInput[i].done = 1;
                    break;
                }
            }
            printf("P%d",processArray[0].id);
            // printf("%20d",processArrayInput[relProcessArrayTemp].burstTime - waitingTimeInterval);
            printf("%20d",timeFrame- waitingTimeInterval);
            printf("%20d",waitingTimeInterval);
            printf("%20d",timeFrame);
            printf("\n");
            waitingTimeArray[waitingTimeSize] = waitingTimeInterval;
            waitingTimeSize += 1;
            turnAroundTimeArray[turnAroundTimeSize] = timeFrame;  
            turnAroundTimeSize += 1;
            waitingTimeInterval = timeFrame;
            // Shift Array
            for (int i = 0; i < numberOfProcess-1;i++) {
                processArray[i] = processArray[i+1];
            }
            numberOfProcess--;
        }
        processArray[0].burstTime--;
        timeFrame++;
    }
    for (int i = 0 ;i < waitingTimeSize;i++) {
        WaitingTimeAvg += waitingTimeArray[i];
        TurnaroundTimeAvg += turnAroundTimeArray[i];
    }
    WaitingTimeAvg = WaitingTimeAvg/waitingTimeSize;
    TurnaroundTimeAvg = TurnaroundTimeAvg/turnAroundTimeSize;

    printf("\nAverage Waiting Time--   \t%f\n",WaitingTimeAvg);
	printf("Average Turnaround Time -- \t%f\n",TurnaroundTimeAvg);
    return 0;
}


    // processArrayInput[0].id = 1;
    // processArrayInput[0].arrivalTime = 0;
    // processArrayInput[0].burstTime = 15;
    // processArrayInput[0].done = 0;

    // processArrayInput[1].id = 2;
    // processArrayInput[1].arrivalTime = 15;
    // processArrayInput[1].burstTime = 25;
    // processArrayInput[1].done = 0;

    // processArrayInput[2].id = 3;
    // processArrayInput[2].arrivalTime = 25;
    // processArrayInput[2].burstTime = 5;
    // processArrayInput[2].done = 0;
    // p1 and p2 and p3
    // Expected Output
    // Process         Burst Time        Waiting Time    Turn-around Time
    // P1              15                0                 15
    // P2              10                15                25
    // P3              5                 25                30
    // P2              15                35                45

    // Expected Output
    // Process         Burst Time        Waiting Time    Turn-around Time
    // P1              15                0                15
    // P2              25                15               40

    // Test Case
    // processArrayInput[0].id = 1;
    // processArrayInput[0].arrivalTime = 0;
    // processArrayInput[0].burstTime = 15;
    // processArrayInput[0].done = 0;

    // processArrayInput[1].id = 2;
    // processArrayInput[1].arrivalTime = 0;
    // processArrayInput[1].burstTime = 20;
    // processArrayInput[1].done = 0;

    // processArrayInput[2].id = 3;
    // processArrayInput[2].arrivalTime = 20;
    // processArrayInput[2].burstTime = 20;
    // processArrayInput[2].done = 0;

    // processArrayInput[3].id = 4;
    // processArrayInput[3].arrivalTime = 25;
    // processArrayInput[3].burstTime = 20;
    // processArrayInput[3].done = 0;

    // processArrayInput[4].id = 5;
    // processArrayInput[4].arrivalTime = 45;
    // processArrayInput[4].burstTime = 5;
    // processArrayInput[4].done = 0;

    // processArrayInput[5].id = 6;
    // processArrayInput[5].arrivalTime = 55;
    // processArrayInput[5].burstTime = 15;
    // processArrayInput[5].done = 0;