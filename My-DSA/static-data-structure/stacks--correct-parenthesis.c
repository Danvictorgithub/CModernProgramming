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
	return (!isEmpty()) ? stack[--top]: (printf("stack underflow\n"),0);
}
int isEmpty() {
	return (top == 0) ? TRUE : FALSE;
}

void checkParen(char string[]) {
	int isValid = 1;
	for (int i = 0; i < strlen(string);i++) {
		switch (string[i]) 
		{
			case '(':
			case '[':
			case '{':
				push(string[i]);
				break;
			case ')':

				if (pop() =='(') {
				}
				else {
					isValid = 0;
					i = strlen(string); //ends loop
					
				}
				break;
			case ']':
				if (pop() == '[');
				else {
					isValid = 0;
					i = strlen(string); //ends loop
				}
				break;
			case '}':
				if (pop() == '{');
				else {
					isValid = 0;
					i = strlen(string); //ends loop
				}
				break;
		}
	}
	printf("top is %d and isValid is %d\n",top,isValid);
	(top == 0 && isValid) ? printf("valid"): printf("not valid");
}

int main(void) {
	char string[100];
	scanf("%s",string);
	checkParen(string);
	return 0;
}