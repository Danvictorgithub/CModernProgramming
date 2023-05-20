#include <stdio.h>
#include <stdlib.h>
struct node {
	struct node *next;
	int value;
};

struct node *deleteNode(struct node *list, int n) {
	struct node *current, *previous;
	for (current = list, previous = NULL; current != NULL; previous = current,current = current->next) {
		if (current -> value == n) {\
			if (previous == NULL) {
				if (current->next != NULL) {
					current = current->next;
					free(current);
					return list;
				}
				else {}
			}
			previous->next = current->next;
			free(current);
			return list;
		}
	}
	return NULL;
}
struct node *searchList(struct node *list,int n) {
	for (;list != NULL;list = list->next) {
		if (list->value == n) {
			return list;
		}
	}
	return NULL;
}
struct node *add_to_list(struct node *list, int n) {
	struct node *newNode = malloc(sizeof(struct node));
	newNode->value = n;
	newNode->next = list;
	return newNode;
}
struct node *insertList(struct node * list, int n, int value) {
	struct node *current, *previous;
	struct node *newNode = malloc(sizeof(struct node));
	
	for (current = list, previous = NULL; current != NULL;previous = current, current = current->next) {
		if (current-> value == n) {
			newNode->value = value;
			newNode->next = previous->next;
			previous->next = newNode;
		}
	}
}
void printlinkedList(struct node *list) {
	if (list != NULL) {
		printf("%d\n",list->value);
		printlinkedList(list->next);
	}
}

int main(void) {
	// # Creating a Node
	// 1. Allocate memory for the node
	// 2. Store data in the node
	// 3. Insert the node into the list
	struct node *first = NULL;
	first = add_to_list(first, 10);
	first = add_to_list(first, 20);
	// first = add_to_list(first, 30);
	// printlinkedList(first);
    // [NULL,10] -> [1,20] -> [2,30]
    // 1              2
	// struct node *result = NULL;
	// result = searchList(first,20);
	// printf("%d\n",result->value);
	deleteNode(first, 10);
	deleteNode(first, 20);
	add_to_list(first, 20);
	// insertList(first,10,20);
	printlinkedList(first);
	return 0;
}
