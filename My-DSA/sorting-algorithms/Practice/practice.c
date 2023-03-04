#include <stdio.h>
#include <stdlib.h>
void sortarray(int *array[],int arraysize) {
	int *temp; // Error kagaina hahahahahaha
	int sorted = 1;
	for (int i = 0; i < arraysize - 1;i++) {
		sorted = 1;
		if ( *(array[i] + 1) >  *(array[i+1] + 1)  ) {
			sorted = 0;
		} else if (  *(array[i] + 0) >  *(array[i+1] + 0)  ) {
			sorted = 0;
		}
		if (sorted == 0) {
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
		}
	}
	if (sorted == 0) {
		sortarray(array,3);
	}
}
//Simplified without Days
int main(void) {
	int *tempdate;
	int *datelist[3];
	int mm,yyyy;
	for (int i = 0; i < 3; i++){
		scanf("%d/%d",&mm,&yyyy);
		tempdate = malloc(sizeof(int)*2); // creates array[2] with different address
		tempdate[0] = mm;
		tempdate[1] = yyyy;
		datelist[i] = tempdate; // puts array address to datelist pointer-type-int array
	}
	printf("\n\n");
	printf("Your Input\n");
	for (int i = 0; i < 3; i++){
		printf("%d/%d\n",*(datelist[i]),*(datelist[i] + 1));
	}
	printf("\n\n");
	printf("Sorted\n");
	sortarray(datelist,3);
	for (int i = 0; i < 3; i++){
		printf("%d/%d\n",*(datelist[i]),*(datelist[i] + 1));
	}
	return 0;
}