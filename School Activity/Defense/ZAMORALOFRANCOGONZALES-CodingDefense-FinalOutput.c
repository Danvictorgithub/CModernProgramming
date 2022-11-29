#include <stdio.h> // Collaboration with Jelbert Zamora, Diana Gonzales, and Dan Victor Lofranco in Coding Defense
#include <string.h>
#include <stdlib.h>
#define STR_LEN 10 + 1
// The choice is to use char pointer array, 
// so it reduces code significantly and also efficiently.
int main(void)
{
	char string[STR_LEN]; // This is where the string input is stored
	char *temp; // The temp is a variable that copies string, but assigned with a different 
	int numString = 0, i, shift;

	printf("Number of words must be >= 3 or <= 10\n");
	do {
		printf("How many words would you like to input: "), scanf("%d", &numString);
	} while ( numString < 3 || numString > 10);


	char *stringList[numString]; // Initializes a char pointer array after getting its dimension

	for (i = 0; i < numString;i++)
	{
		printf("Word %d: ",i+1), scanf("%s",string);
		temp = malloc(strlen(string) + 1); // defines the size of the pointer/array, with different memory location
		strcpy(temp,string);
		stringList[i] = temp; // passes a pointer to a pointer array (char *)
	}	// Note: Without the use of malloc, the stringList pointer array will only contain single memory location.

	printf("\n");
	printf("How many shift would you like: "), scanf("%d",&shift);

	(shift > 0) ? (printf("Shift Direction:Right\n")) : (printf("Shift Direction: Left\n"));
	// shift = (shift > 0) ? (shift) : (shift + numString); // Allows flexibility on -1 shifts
	// if( shift < 0) {
	// 	shift*= -1;
	// } Old Solution Discarded


	// Positive Shift
	// Visualization [The numbers given are memory locations]
	// 1 2 3 4 -> 4 1 2 3
	// 1 2 3 4
	// 1 2 4 3
	// 1 4 2 3
	// 4 1 2 3 // Ends 1 Shift which is logically equivalent to shifting elements to the right
	if (shift > 0) {
		for (;shift != 0;shift--)
			for (i = numString - 1; i > 0; i--) {
				temp = stringList[i];
				stringList[i] = stringList[i-1];
				stringList[i-1] = temp;
			}
	}
	// Negative Shift [Modified]
	// Visualization [The numbers given are memory locations]
	// 1 2 3 4 -> 2 3 4 1
	// 1 2 3 4
	// 2 1 3 4
	// 2 3 1 4
	// 2 3 4 1 // Ends 1 Shift which is logically equivalent to shifting elements to the left
	else {
		shift *= -1;
		for (;shift !=0;shift--)
			for (i = 0; i < numString-1;i++){
				temp = stringList[i];
				stringList[i] = stringList[i+1];
				stringList[i+1] = temp;
			}
	}
  // Visualization Results
	for (i = 0; i < numString ;i++)
		printf("Word %d: %s \n",i+1,stringList[i]);
	return 0;
}

// Old Attempts
// for (i = 0; i < shift;i++) {
	// 	temp = stringList[numString-1];
	// 		for(j = numString - 1; j > 0 ;j--) {
	// 			stringList[j] = stringList[j-1];
	// 		}
	// 	stringList[0] = temp;
	// }


	// for (i = 0; i < shift;i++){
	// 	temp = stringList[1];
	// 	stringList[1] = stringList[0];
	// 	for (j = 2; j < numString;j++){
	// 		temp2 = stringList[j];
	// 		stringList[j] = temp;
	// 		temp = temp2;
	// 	}
	// 	stringList[0] = temp;
	// }