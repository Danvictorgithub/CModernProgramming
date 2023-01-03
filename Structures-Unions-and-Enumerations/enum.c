#include <stdio.h>

int main(void) {
	enum {CLUBS, DIAMONDS, HEARTS, SPADES}s1,s2;
	s1 = DIAMONDS;
	printf("%d",s1);
	return 0;
}