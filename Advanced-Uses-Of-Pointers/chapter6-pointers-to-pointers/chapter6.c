#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int value;
	struct node *next;
} node;
node *oldAddToList(node *list, int n) {
	node *newNode = malloc(sizeof(node));
	newNode->value = n;
	newNode->next = list;
	return newNode;
};
void addToList(node **list, int n) {
	node *newNode = malloc(sizeof(node));
	newNode->value = n;
	newNode-> next = *list;
	*list = newNode;
}
void printLinkedList(node *list) {
	for (;list != NULL;list = list->next) {
		printf("%d\n",list->value);
	}
}
void changeArray(int **array1) {
	*array1 = NULL;
}
void changeValue(int *val) {
	*val = 6;
}
int addNumber(int a, int b) {
	// printf("%d",a+b);
	return a + b;
}
int subtractNumber(int a, int b) {
	return a - b;
}
void addThreeNumbers(int (*addNumberF)(int,int),int a,int b, int c) {
	addNumberF = subtractNumber;
	printf("%d\n",addNumberF(addNumberF(1,2),3));
}
int main(void) {
	node *first = NULL;
	addToList(&first,10);
	addToList(&first,20);
	printLinkedList(first);
	addThreeNumbers(addNumber,1,2,3);
	return 0;
}