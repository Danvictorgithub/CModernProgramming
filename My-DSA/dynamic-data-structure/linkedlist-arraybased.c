#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define OK 0
#define NO_SPACE -1

#define BEG -2
#define END -3

#define MAXLEN 20
#define MAXENTRIES 100

int front = END;
int link[MAXENTRIES];
char data[MAXENTRIES][MAXLEN];


int insert (int where,char item[]) {
	int i;
	// Find free slot in data array
	for (i = 0; i < MAXENTRIES && data[i][0] != NULL;i++);
	if (i >= MAXENTRIES)
		return NO_SPACE;
	strncpy(data[i],item,MAXLEN); //stores entry
	if (where == BEG) {
		link[i] = front;
		front = i;
	} else {
		link[i] = link[where];
		link[where] = i;
	}
	return OK;
}

int main(void) {

	return 0;
}