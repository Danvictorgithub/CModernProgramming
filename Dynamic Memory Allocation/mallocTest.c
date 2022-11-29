#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat(const char *str1,const char *str2) {
	char *newString;
	newString = malloc(strlen(str1) + strlen(str2) + 1);
	strcpy(newString,str1);
	strcat(newString,str2);
	return newString;
}
int main(void) {
	char *string1 = "Hello ";
	char *string2 = "World";
	char *string3 = concat(string1,string2);
	printf("%s",string3);
	return 0;
}