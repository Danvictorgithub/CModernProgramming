#include <stdio.h> //all input and output, including system("cls")
#include <stdlib.h> //exit
#include <conio.h> //getch
#include <string.h> //memcpy

// Use a one-dimensional array topics (of type char *) to store the five causes.
// To summarize the survey responses, use a 5-row, 10-column two-dimensional array responses
// of type int, each row corresponding to an element in the topics array. When the program
// runs, it should ask the user to rate each issue. Then have the program display a summary of the result.
struct Poll {
	char *socialConciousIssuesPtr[5];
	int PollArray[5][10];
	int PollRatings[5];
}PollResult = {{"Discrimination","Gender Equality","Racism","Bullying","Poverty"},{0},{0}};
void reversedBubbleSort(int *array,int arraysize) {
	int i, switched = 0, temp;
	for (i = 0; i < arraysize-1; i++) {
		if (array[i] < array[i+1]) {
			// Swap
			// example [1][0] -> [0][1]
			temp = array[i]; //saved value for swapping
			array[i] = array[i+1];
			array[i+1] = temp;
			switched = 1;
		}
	}
	// if swapped/switched, means not perfectly sorted, else sorted
	if (switched) {
		reversedBubbleSort(array, arraysize);
	}
}
int main(void) {
	//Init variable
	int option;
	int issue = 0;
	int respondent = 1;
	int flagAlreadyVoted = 0;

	int ranking[5] = {1,2,3,4,5};
	memcpy(ranking,PollResult.PollRatings,sizeof(int)*5);
	while (option != 5) {
		system("cls");
		printf("Poll for Social Concious Issues Awareness\n");
		printf("Respondent: %d\n",respondent);
		printf("0. To Vote \n");
		printf("1. Select Issue\n");
		printf("2. Display all Issues\n");
		printf("3. Ranking\n");
		printf("4. Next Voter\n");
		printf("5. to exit\n");
		printf("option: ");
		scanf("%d",&option);
		switch (option) {
			case 0:
				if (flagAlreadyVoted) {
					printf("You have already voted\n");
					getch();
				}
				else {
					for (int i = 0; i < 5;i++) {
					system("cls");
					int pollScale;
					printf("Vote for: %s\n",PollResult.socialConciousIssuesPtr[i]);
					while (1) {
						printf("scale: ");
						scanf("%d",&pollScale);
						if (pollScale < 0 || pollScale > 10) {
								printf("Invalid input\n");
								getch();
								continue;
							}
							PollResult.PollArray[i][pollScale-1]++;
							PollResult.PollRatings[i] += pollScale; 
							printf("Success!\n");
							break;
					}
					flagAlreadyVoted = 1;
					}
					// Sorting routine
					memcpy(ranking,PollResult.PollRatings,sizeof(int)*5);
					reversedBubbleSort(ranking,5);
				}
				break;
			case 1:
				system("cls");
				for (int i = 0; i < 5;i++) {
					printf("%d. %s\n",i+1,PollResult.socialConciousIssuesPtr[i]);
				}
				printf("Choose number to display Issue: ");
				scanf("%d", &issue);
				if (issue >= 0 && issue <=5) {
					system("cls");
					printf("Issue:\n");
					printf("%s\n",PollResult.socialConciousIssuesPtr[issue-1]);
					printf("Poll Result\n");
					printf("%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d\n",1,2,3,4,5,6,7,8,9,10);
					for (int i=0;i < 10;i++) {
						printf("%3d",PollResult.PollArray[issue-1][i]);
					}
					printf("\n\n\n");
					printf("any key to return to menu\n");
					getch();
				}
				else {
					printf("Invalid Input\n");
					getch();
				}
				break;
			case 2:
				system("cls");
				printf("   %16s%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d\n","",1,2,3,4,5,6,7,8,9,10);
				for (int i = 0; i < 5;i++) {
					printf("%d. %16s",i+1,PollResult.socialConciousIssuesPtr[i]);
					for (int j = 0; j < 10;j++)
						printf("%3d",PollResult.PollArray[i][j]);
					printf("\n");
				}
				getch();
				break;
			case 3:
				system("cls");
				int notRank[] = {1,2,3,4,5};
				int rankInterval = 5;
				printf("Ranking: \n");
				for (int i = 0; i < 5;i++) {
					for (int j = 0 ;j < rankInterval;j++) {
						if (ranking[i] == PollResult.PollRatings[j]) {
							printf("%d. %20s ",i+1,PollResult.socialConciousIssuesPtr[j]);
							printf("%d\n",PollResult.PollRatings[j]);

						}
					}
				}
				getch();
				break;
			case 4:
				if (flagAlreadyVoted == 0) {
					printf("You haven't voted yet\n");
					getch();
				}
				else {
					respondent++;
					flagAlreadyVoted = 0;
				}
				break;
			case 5:
				printf("Exiting....");
				getch();
				exit(0);
			break;
			default:
				printf("Invalid Input");
				getch();
				break;
		}
	}


	//testing
	// for (int i = 0; i < 5;i++) {
	// 	printf("%s\n",PollResult.socialConciousIssuesPtr[i]);
	// }
	return 0;
}