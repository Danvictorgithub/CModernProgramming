#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_LEN 10 + 1

// The choice is to use multidimensional string via pointer, 
// so it reduces code significantly and also efficiently.
int main(void)
{
	char string[STR_LEN]; // This is where the string input is stored
	char *temp,*temp2; // The temp is a variable that copies string, but assigned with a different 
	int numString = 0, i,j, shift;
	printf("Number of words must be >= 3 or <= 10\n");
	do {
		printf("How many words would you like to input: "), scanf("%d", &numString);
	} while (numString < 3 || numString > 10);
	char *stringList[numString];
	for (i = 0; i < numString;i++)
	{
		printf("Word %d: ",i+1), scanf("%s",string);
		temp = malloc(strlen(string) + 1); // defines the size of the pointer/array, with different memory location
		strcpy(temp,string);
		stringList[i] = temp;
	}
	printf("\n");

	printf("How many shift would you like: "), scanf("%d",&shift);
	shift = (shift > 0) ? (shift) : (shift + numString); // Allows flexibility on -1 shifts
	// for (i = 0; i < shift;i++) {
	// 	temp = stringList[numString-1];
	// 		for(j = numString - 1; j > 0 ;j--) {
	// 			stringList[j] = stringList[j-1];
	// 		}
	// 	stringList[0] = temp;
	// }
	for (i = 0; i < shift;i++){
		temp = stringList[1];
		stringList[1] = stringList[0];
		for (j = 2; j < numString;j++){
			temp2 = stringList[j];
			stringList[j] = temp;
			temp = temp2;
		}
		stringList[0] = temp;
	}
	for (i = 0; i < numString;i++)
		printf("Word %d: %s ",i+1,stringList[i]);
	return 0;
}