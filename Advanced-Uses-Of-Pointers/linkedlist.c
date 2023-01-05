#include <stdio.h>
#include <stdlib.h>
struct node {
	int value;
	struct node *next;
};
struct node *add_to_list(struct node *list,int n) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->value = n;
	new_node->next = list;
	if 	(new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}
	return new_node;
}
int main(void) {
	struct node *first = NULL;
	return 0;
}