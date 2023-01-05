#include <stdio.h>
#include <stdlib.h>
// Linked_List Initialization
struct node {
	int value;
	struct node *next;
};
// Creating a List as a Data Structure
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
// Put values on list
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
// Prints List Recursive Method
void printLinkedListRec(struct node *NODE) {
	printf("%d",NODE->value);
	if (NODE->next != NULL)
		printLinkedListRec(NODE->next);
}
// Prints List Iterative Method
void printLinkedList(struct node *NODE) {
	struct node *p;
	for (p = NODE; p != NULL;p = p->next) {
		printf("%d",p->value);
	}
}
// struct node *search_list(struct node *list, int n) {
// 	struct node *p;

// 	for (p = list; p != NULL; p =  p->next) {
// 		if (p->value == n)
// 			return p;
// 	}
// 	return NULL;
// }

// struct node *search_list(struct node *list,int n) {
// 	for (; list!= NULL; list = list->next){
// 		if (list->value == n) {
// 			return list;
// 		}
// 	}
// 	return NULL;
// }

// struct node *search_list(struct node *list, int n) {
// 	for (;list != NULL && list->value != n; list = list->next);
// 		return list;
// }

struct node *search_list(struct node *list, int n) {
	while (list != NULL && list->value != n) {
		list = list->next;
	}
	return list;
}
int main(void) {
	struct node *first;
	first = read_numbers();
	printf("PRINTING\n");
	// printLinkedList(first);
	// for (struct node *p = first; p != NULL; p = p->next) {
	// 	printf("%d ",p->value);
	// }
	int numSearch; printf("Enter Number to Search: "),scanf("%d",&numSearch);
	
	struct node *result_node = search_list(first, numSearch);
	(result_node != NULL) ? printf("Result Found: %d",result_node->value): printf("Result Does Not Exist");
	return 0;
}