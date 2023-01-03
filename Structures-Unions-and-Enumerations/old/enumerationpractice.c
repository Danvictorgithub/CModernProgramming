#include <stdio.h>

int main(void) {
	typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} SUIT;

	SUIT s1,s2;
	s1 = DIAMONDS;
	printf("%d", s1);

	return 0;
}