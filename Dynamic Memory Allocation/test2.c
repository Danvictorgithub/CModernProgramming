#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char string;
	scanf("%[^\n]s",string);
	printf("The word is %s",string);
	return 0;
}