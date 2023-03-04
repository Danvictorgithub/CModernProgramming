#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *p = malloc(sizeof(int));
	int *q = malloc(sizeof(int));
	free(p); 
	p = q; // if planning to change pointer it is suggested to free the memory manually
	// by using the free() function, or memory leak will happen
	*q = 5;
	free(q);
	*q = 7;
	printf("%d", *q);
	return 0;
}