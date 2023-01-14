#include <stdio.h>
#include <string.h>
// demo >out.dat
int main(void) {
	FILE *fp = fopen("C:/Users/Dan/Desktop/CProgramming/CModernProgramming/InputOutput/database.txt","a");
	// char str[100];
	// scanf("%[^\n]s",str);
	int h = 1, t = 100;
	char str[] = "You are > your prob";

	if (fp == NULL) {
		printf("File Failed to open");
	}
	else {
		// for(int i = 0; i < strlen(str);i++) {
			if (fputs(str,fp) < 0) {
				printf("Error");
			}
		fprintf(stdout,"%s  Score : %d to %d\n",str,h,t);
		// }
		fclose(fp);
	}
	return 0;
}