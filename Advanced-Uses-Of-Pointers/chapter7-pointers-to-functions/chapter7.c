#include <stdio.h>
#include <stdlib.h>

int comparator (const void *p, const void *q) {
	if (*(int *)p < *(int *)q) {
		return -1;
	} else if ((int *)p == (int *)q) {
		return 0;
	} else {
		return 1;
	}
}
void sampleFunction(void *a, void *b) {
	printf("%d",(int *)a);
}
int main(void) {
	int array[5] = {5,2,3,1,4};
	qsort(array,5,sizeof(int),comparator);
	for (int i = 0; i < 5;i++) {
		printf("%d\n",array[i]);
	}
	sampleFunction((void *)5,(void *)2);
	return 0;
}