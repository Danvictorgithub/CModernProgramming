#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void openfile(char *, FILE **);
int main(void) {
	// FILE *fp;
	// openfile("MyFile.txt",&fp);	


	FILE *fp;
	char str[80];
	fp = fopen("try.c","r");
	// while ( fgets(str,80,fp) != EOF)
		fputs(str);
		fclose(fp);

	return 0;
}
void openfile(char *fn, FILE **f) {
	*f = fopen(fn,"r");
}