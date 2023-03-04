#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define FULL 1
#define NOTFULL 0
#define MAXSTACK 100

int top = 0;
int stacks[MAXSTACK];

// Stacks Operations:
// 	push
// 	pop
// 	isEmpty

int push(int value) {
	if (top + 1 >= MAXSTACK) { //stack overflow
		return (FULL);
	}
	stacks[top++] = value;
	return (NOTFULL);
}
int pop() {
	return stacks[--top];
}
int empty() {
	return (top == 0) ? TRUE : FALSE;
}
int full() {
	return !empty();
}
int main(void) {
	// application of stacks: Reversing the number
	int digit;
	while (1) {
		scanf("%d",&digit);
		if (digit != 0) push(digit);
		else break;
	}
	printf("Reversing: ");
	while (!empty()) {
		printf("%d ",pop());
	}
	return 0;
}