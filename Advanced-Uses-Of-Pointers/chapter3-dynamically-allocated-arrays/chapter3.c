#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a. application of malloc
void mallocApplication() {
	int *a;
	int n = 5; //number of element in an array
	a = malloc(sizeof(int)*n);
	int tempArray[] = {1,2,3,4,5};
	memcpy(a,tempArray,n*sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("%d\n",a[i]);
	}
}

struct sample {
	int number;
	char *string;
};
//b. application of calloc
// calloc can be used instead of malloc, like for example
// if we want to initialize our memory allocation to fill in the garbage values
// instead of malloc that fills garbage vallue, calloc initializes everything to 0
// for example in this struct s1 the s1 number and string are set to 0
void callocApplication() {
	struct sample *s1;
	s1 = calloc(1,sizeof(struct sample));
	printf("%d %s",s1->number,s1->string);
}
// application of realloc
// realloc allows pointer sizes to be "reallocate" to selected sizes in which
// this allows us to update arrays or objects elements
void reallocApplication() {
	int *array = malloc(sizeof(int) *2);
	int *reallocTemp; 
	// array = malloc(sizeof(int)*2); // This array for example can only allocate 5 int elements
	int tempArray[] = {1,2};
	// memcpy(array,tempArray,sizeof(tempArray));
	memcpy(array,tempArray,sizeof(tempArray));
	for (int i = 0; i < 2;i++) {
		printf("%d\n",array[i]);
	}
	printf("Realloc Applied\n");
	reallocTemp = realloc(array,sizeof(int)*5); // now array can get at most 5 elements
	if (reallocTemp != NULL) {
		array = reallocTemp; //this is done to avoid segmentation fault
	}
	else {
		printf("Error found in reallocTemp");
		exit(EXIT_FAILURE);
	}
	int tempArray2[] = {2,1,3,4,5};
	for (int i = 0;  i < 5; i++) {
		*(array + i) = tempArray2[i];
	}
	// int number;
	for (int i = 0; i < 5;i++) {
		printf("%d\n",array[i]);
	}
}
int main(void) {
	// mallocApplication();
	// callocApplication();
	reallocApplication();
	return 0;
}