#include <stdio.h>

void towersofhanoi(int n, char start, char aux, char dest) {
	if (n==1) {
		printf("Move %c to %c\n",start,dest);
	}
	else {
		towersofhanoi(n-1,start,dest,aux);
		printf("Move %c to %c\n",start,dest);
		towersofhanoi(n-1,aux,start,dest);
	}
}
int main(void) {
	towersofhanoi(2,'a','b','c');
	return 0;
}