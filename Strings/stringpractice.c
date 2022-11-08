#include <stdio.h>
#include <string.h>
#define STR_LEN 80
int read_line(char str[],int n){
	int ch, i;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}
int count_spaces(const char str[]){
	int count = 0;
	for(;*str != '\0';str++)
		if (*str == ' ')
			count++;
	return count;
}
int main(void){ 
	char string[] = "aa";
	char string1[] = "ab";
	printf("%d\n", strcmp(string,string1));
	if (strcmp(string,string1) == 0 ) {
		printf("string is equal string1");
	}
	else if (strcmp(string,string1) < 0) {
		printf("string is less than string1");
	}
	else {
		printf("string is greater than string1");
	}
	return 0;
}