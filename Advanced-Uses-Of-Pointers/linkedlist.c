#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *add_to_list(struct node *list, int n) {
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in allocating memory");
		exit(EXIT_FAILURE);
	}
	new_node->value = n;
	new_node->next = list;
	return new_node;
}

struct node *read_numbers(void) {
	struct node *first = NULL;
	int n;
	printf("Enter a series of integers (0 to terminate): \n");
	for (;;){
		scanf("%d",&n);
		if (n==0){
			return first;
		}
		first = add_to_list(first, n);
	}
}

void printLinkedList(struct node *NODE) {
	printf("%d",NODE->value);
	if (NODE->next != NULL)
		printLinkedList(NODE->next);
} 

int main(void) {
	struct node *first;
	first = read_numbers();
	printf("PRINTING\n");
	printLinkedList(first);
	return 0;
}