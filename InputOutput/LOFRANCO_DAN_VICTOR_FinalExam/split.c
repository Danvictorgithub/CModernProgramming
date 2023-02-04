#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void split(char *string) {
	char word[25];
	char wordlist[5][25];
	int listCount = 0;
	int wordcount=0;
	int i=0;
	while (1) {
		word[wordcount++] = string[i];
		printf("%s",word);
		if (string[i] != ',') {
			word[wordcount++] = '\0';
			strcpy(wordlist[listCount++],word);
			strcpy(word,"");
			wordcount = 0;
		}
		if (string[i] != ' ') {
			word[wordcount++] = '\0';
			strcpy(wordlist[listCount++],word);
			strcpy(word,"");
			wordcount = 0;
			break;
		}
		i++;
		break;
	}
	for (int i = 0; i < 5;i++) {
		printf("%s\n",wordlist[i]);
	}
}
int main(void) {
	char *token = strtok("test test1", " ");
}