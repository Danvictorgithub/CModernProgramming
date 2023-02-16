#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Dynamically Allocated String
char *concat(char *str1, char *str2) {
	char *result;
	result = malloc(strlen(str1) + strlen(str2) + 1);
	if (result == NULL) { // Applied Memory Allocation checking from referred to chapter 1
		printf("Failed to malloc at function concat");
		exit(EXIT_FAILURE);
	}
	result = strcpy(result, str1);
	result = strcat(result, str2);
	return result;
}
int main(void) {
	char *string1 = "The quick brown fox";
	char *string2 = " jumps over the lazy dog";
	char *string3 = concat(string1,string2);
	printf("%s\n",string3);
	free(string3);// Must be used to free the function
	printf("%s",string3);
	return 0;
}