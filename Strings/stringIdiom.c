#include <stdio.h>
int mystrlen(const char *s) {
	const char *p = s;
	while (*s)
		s++;
	return s - p;
}
int main(int argc, char const *argv[])
{
	/* code */
	printf("%d", mystrlen("memes"));
	return 0;
}