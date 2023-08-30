#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
	char sentence[100];
	char substr[100];
	char *stringList[25] = {0};
	char *temp;
	int stringNum[25] = {0};
	int current = 0,i, j, k;
	int wordCount = 0;
	int recurr = 0;
	printf("Enter a sentence: ");
	scanf("%[^\n]s",sentence);
	for (i = 0; i < strlen(sentence);i++){

		if (sentence[i] == ' '){
			for (j = 0; j < i-current;j++) {
				substr[j] = sentence[j+current];
			}
			substr[i-current] = '\0';

			for (k = 0; k < wordCount;k++) {
				if (strcmp(substr,stringList[k]) == 0) {
					stringNum[wordCount] += 1;
					current = i+1;
					recurr = 1;
					break;
				}
			}
			if (recurr == 0) {
				temp = malloc(strlen(substr) + 1);
				strcpy(temp,substr);
				stringList[wordCount] = temp;
				stringNum[wordCount]++;
				wordCount++;
			}
			printf("%s",substr);
			current = i+1;
			recurr = 0;
		}
		// if (i == strlen(sentence)-1 ){
		// 	i++;
		// 	for (j = 0; j < i-current;j++) {
		// 		substr[j] = sentence[j+current];
		// 	}
		// 	substr[i-current] = '\0';

		// 	for (k = 0; k < wordCount;k++) {
		// 		if (strcmp(substr,stringList[k]) == 0) {
		// 			stringNum[wordCount]++;
		// 			current = i+1;
		// 			recurr = 1;
		// 			break;
		// 		}
		// 	}
		// 	if (recurr == 0) {
		// 		temp = malloc(strlen(substr) + 1);
		// 		strcpy(temp,substr);
		// 		stringList[wordCount] = temp;
		// 		stringNum[wordCount]++;
		// 		wordCount++;
		// 	}

		// 	current = i+1;
		// }
	}
	printf("There are %d\n", wordCount);
	
	for (i = 0; i < wordCount;i++) {
		printf("word: %s count: %d",stringList[i],stringNum[i]);
	}
	return 0;
}