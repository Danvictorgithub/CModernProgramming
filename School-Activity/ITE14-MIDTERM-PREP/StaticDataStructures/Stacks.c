#include <stdio.h>
#define size 2
#define TRUE 1
#define FALSE 0
#define FULL 1
#define NOTFULL 0
int top = -1;
int stack[size];
int push(int value) {
	if (top + 1 >= size) {
		//Stack Overflow
		return FULL;
	}
	stack[++top] = value;
	return NOTFULL;
}
int pop() {
	if (top < 0) {
		return FULL;
	}
	return stack[top--];
}
int isStackEmpty() {
	return (top < 0) ? 1: -1;
}

int main(void) {
	printf("%d\n",isStackEmpty());
	printf("%d\n",push(5));
	printf("%d\n",pop());
	printf("%d\n",pop());
	return 0;
}