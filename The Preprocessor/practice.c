#include <stdio.h>
#include <ctype.h>
#define someString "This is string"
#define MATHPLUS(x,y) x+y

#define MK_ID(n) i##n

#define INT_PRINT(n) printf(#n,n)
int main(void)
{
	int MK_ID(1) = 59;
	printf("%d",i1);	
	return 0;
}
