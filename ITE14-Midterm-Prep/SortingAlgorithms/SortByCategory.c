#include <stdio.h>
#include <stdlib.h>

void printArray(char array[],int size) {
	for (int i = 0; i < size;i++) {printf("%c ",array[i]);}
	printf("\n");
}

// without the use of stacks
char *SortByCategory(char array[],int size) {
	char Category[size];
	int CategoryContent = 0;
	char *Result = malloc(sizeof(char)*size);
	int ResultContent = 0;

	int found = 0;
	// checks if the element is in the category else add it in the category
	for (int i = 0; i < size;i++) {
		found = 0;
		for (int j = 0; j < CategoryContent;j++) {
			if (array[i] == Category[j]) {
				found = 1;
				break;
			}
		}
		if (found) {
			continue;
		}
		else {
			Category[CategoryContent++] = array[i];
		}
	}
	// run through the Category and add the Category Element to Result
	for (int i = 0 ; i <= CategoryContent;i++) {
		for (int j = 0;j < size;j++) {
			if (array[j] == Category[i]) {
				Result[ResultContent++] = array[j];
			}
		}
	}
	return Result;
}

int main(int argc, char const *argv[])
{	// expected result
	// r r r r w w w w w z z z
	char array[] = {'r','w','w','w','z','r','z','r','r','z','w','w'};
	char *array2 = SortByCategory(array,12);
	printArray(array2,12);
	return 0;
}