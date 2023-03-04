#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define FULL 1
#define NOTFULL 0
#define MAXSTACK 100
int top = 0;
char stack[MAXSTACK];

int push(char value) {
	if (top >= MAXSTACK-1) {
		return FULL;
	}
	stack[top++] = value;
	return NOTFULL;
}
int isEmpty();
char pop() {
	return (!isEmpty()) ? stack[--top]: printf("stack underflow\n"), 0;
}
int isEmpty() {
	return (top == 0) ? TRUE : FALSE;
}

void checkParen(char string[]) {
	for (int i = 0; i < strlen(string);i++) {
		switch (string[i]) 
		{
			case '(':
			case '[':
			case '{':
				push(string[i]);
				break;
			case ')':
				if (pop() == '(') {
					break;
				}
				else {
					i = strlen(string);
					break;
				}
			case ']':
				if (pop() == '[') break;
				else {
					i = strlen(string);
					break;
				}
			case '}':
				if (pop() == '{') break;
				else {
					i = strlen(string);
					break;
				}
		}
	}
	(top == 0) ? printf("valid"): printf("not valid");
}

int main(void) {
	char string[100];
	scanf("%s",string);
	checkParen(string);
	return 0;
}