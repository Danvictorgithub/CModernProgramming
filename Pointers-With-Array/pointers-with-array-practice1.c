#include <stdio.h>

int main(void)
{
	// From Let Us C
	// using pointer for multi dimensional array
	// int array[2][3] = {1,2,3,4,5,6};
	 //int i,j;
	 //for (i = 0; i<2;i++) {
	 //		for(j = 0; j < 3; j++){
	 //    		printf("%d", *(*(array + i) + j));
	 //    	}
	 //}


	// using pointer for single dimensional array
	// int array[6] = {1,2,3,4,5,6};
	// for (int i = 0; i < 6; i++)
	// 	printf("%d", *(array + i));



	// Printing Array with pointers (Modern C)
	// int a[] = {1,2,3,4,5,6,7,8,9,10};
	// for (int *p = a; p < a+10; p++)
	// 	printf("%d\n", *p);

	// int a[][3] = {1,2,3,
	// 			  4,5,6};
	// int *p = &a[0][0];
	// for (;p < a ;p++)
	// 	printf("%d\n",*p);

	int a[][3] = {1,2,3,
				  4,5,6};
	for (int *p = &a[0][0]; p <= &a[1][2];p++)
		printf("%d\n",*p);
	return 0;
}