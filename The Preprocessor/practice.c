#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define someString "This is string"
#define MATHPLUS(x,y) x+y

#define MK_ID(n) i##n
// #define ECHO(s) (gets(s),puts(s))
#define ECHO(s) { gets(s); puts(s);}
#define INT_PRINT(n) printf(#n" = %d",n)
int main(void)
{
	// char string[] = "memes";
	// int MK_ID(1) = 59;
	// ECHO(string);
	INT_PRINT(10/2);
	return 0;
}
