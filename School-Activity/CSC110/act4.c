#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
	int id;
	int burstTime;
	int pId;
};

struct Process *insertionSort(struct Process *unsortedArray, int numArray) {
        struct Process *sortedArray = malloc(sizeof(struct Process)*numArray);
        memcpy(sortedArray,unsortedArray,numArray*sizeof(struct Process));
	struct Process temp;
        for (int i = 0; i < numArray-1; i++) {
                if (sortedArray[i].pId > sortedArray[i+1].pId) {
                        for (int j = i+1;j >= 1;j--) {
                                if (sortedArray[j].pId < sortedArray[j-1].pId) {
                                        temp = sortedArray[j-1];
                                        sortedArray[j-1] = sortedArray[j];
                                        sortedArray[j] = temp;
                                }
                        }
                }
        }
        return sortedArray;
}

int next(int current, int arraySize) {
	return (current+1) % arraySize;
}

int isProcessNotDone(struct Process *ProcessArray,int numArray) {
	int completedProcess = 0;
	for (int i = 0; i < numArray;i++) {
		if (ProcessArray[i].burstTime == 0) {
			completedProcess++;
		}
	}
	if (completedProcess == numArray) {
		return 0;
	}
	else {
		return 1;
	}
}


int main(void) {
	int numProcess;
	int timeSlice;
	printf("Enter the number of process --\t");
	scanf("%d",&numProcess);
	printf("Enter Time Slice:           --\t");
	scanf("%d",&timeSlice);
	struct Process ProcessList[numProcess];
	for (int i = 0; i < numProcess;i++) {
		printf("Enter Burst time & Priority for Process %d --\t",i);
		scanf("%d %d",&ProcessList[i].burstTime,&ProcessList[i].pId);
		// printf("Enter Priority for Process %d --  \t",i);
		// scanf("%d",&ProcessList[i].pId);
		ProcessList[i].id = i;
	}
	memcpy(ProcessList,insertionSort(ProcessList,numProcess),sizeof(struct Process)*numProcess);
	printf("\n\n%20s%20s%20s%20s%20s\n", "PROCESS","PRIORITY","BURST TIME", "WAITING TIME","TURNAROUND TIME");
	int totalWaitingTime = 0;
	int sumWaitingTime = 0;
	int totalTurnaroundTime = 0;
	int sumTurnaroundTime = 0;
	int currentBurstTime;
	int loopCount = 0;
	for (int i = 0; isProcessNotDone(ProcessList,numProcess);i = next(i,numProcess)) {
		if (ProcessList[i].burstTime == 0) {
			continue;
		}
		if (ProcessList[i].burstTime > timeSlice) {
			currentBurstTime = timeSlice;
			ProcessList[i].burstTime -= currentBurstTime;
		}
		else {
			currentBurstTime = ProcessList[i].burstTime;
			ProcessList[i].burstTime -= currentBurstTime;
		}
		totalTurnaroundTime += currentBurstTime;
		sumTurnaroundTime += totalTurnaroundTime;
		sumWaitingTime += totalWaitingTime;
		printf("%18sP%d%20d%20d%20d%20d\n","",ProcessList[i].id,ProcessList[i].pId,currentBurstTime,totalWaitingTime,totalTurnaroundTime);
		totalWaitingTime += currentBurstTime;
		loopCount++;
	}
	printf("\n%d %d %d",sumWaitingTime, sumTurnaroundTime,loopCount);
	float totalWaitingTimeAvg = (float) sumWaitingTime / (float) loopCount;
	float totalTurnaroundTimeAvg = (float) sumTurnaroundTime / (float) loopCount;
	printf("\nAverage Waiting Time--   \t%f\n",totalWaitingTimeAvg);
	printf("Average Turnaround Time -- \t%f\n",totalTurnaroundTimeAvg);
	return 0;
}
