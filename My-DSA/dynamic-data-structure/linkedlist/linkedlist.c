#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node {
	int data;
	struct node *next;
};
void append(struct node **head,int newData) {
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = *head;
	*head = newNode;
};
void orderedInsert(struct node **head,int newData) {
	struct node *newNode = malloc(sizeof(struct node));
	struct node *current = *head;
	newNode->data = newData;
	if (*head == NULL) {
		newNode->next = *head;
		*head = newNode;
	}
	else {
		//if there are less than 1 node
		if (current->next == NULL) {
			if (current->data > newData) { //2 -> NULL
				newNode->next = current; //1 -> 2 -> NULL
				current = newNode;
				*head = current;
			}
			else {
				current->next = newNode;
				newNode->next = NULL;
			}
		}
		// if greater than 1 node, therefore there is no need change the head
		else {
			// if first node is less than 
			if (current->data > newData) {
				newNode->next = current;
				*head = newNode;
				return;
			}
			// searches for current->next->data that is greater than newData
			for (;current->next != NULL && current->next->data < newData;current = current->next);
			newNode->next = current->next;
			current->next = newNode;
		}
	}
}
struct node *searchNode(struct node *head, int search) {
	for (;head != NULL && head->data != search;head = head->next);
	return head;
}
struct node *deleteNode(struct node **head, int delData) {
	struct node *current, *previous;
	for (current = *head, previous = NULL; 
		current != NULL;
		previous = current, current = current->next) {
		if (current->data == delData) {
			if (previous == NULL) {
				*head = (*head)->next;
			}
			else {
				previous->next = current->next;
			}
			break;
		}
	}
	return current;
}

void printList(struct node *head) {
	while (head != NULL) {
		printf("%d\n",head->data);
		head = head->next;
	}
}
int main(void)
{
	struct node *head = NULL;
	struct node *operated;
	int option = 0;
	while (1) {
		printf("1. ordered insert\n");
		printf("2. search node\n");
		printf("3. delete node\n");
		printf("4. update node\n");
		printf("5. print all\n");
		printf("Option: ");
		scanf("%d",&option);
		switch(option) {
			case 1:
				system("cls");
				printf("Enter number to insert: ");
				scanf("%d",&option);
				orderedInsert(&head,option);
				getch();
				system("cls");
				break;
			case 2:
				system("cls");
				printf("Enter number to search: ");
				scanf("%d",&option);
				operated = searchNode(head,option);
				if (operated == NULL) {
					printf("The value doesn't exist\n");
				}
				else {
					printf("It exist!");
				}
				getch();
				system("cls");
				break;
			case 3:
				system("cls");
				printf("Enter number to delete: ");
				scanf("%d",&option);
				operated = deleteNode(&head,option);
				if (operated == NULL) {
					printf("Doesn't Exist\n");
				}
				else {
					printf("--Deleted: %d",operated->data);
					free(operated);
				}
				getch();
				system("cls");
				break;
			case 4:
				system("cls");
				printf("Enter number to update: ");
				scanf("%d",&option);
				operated = searchNode(head,option);
				if (operated == NULL) {
					printf("Doesn't exist\n");
				}
				else {
					printf("Enter number to %d to: ",operated->data);
					scanf("%d",&option);
					deleteNode(&head,operated->data);
					free(operated);
					orderedInsert(&head,option);
				}
				getch();
				system("cls");
				break;
			case 5:
				system("cls");
				printf("----Values----\n");
				printList(head);
				getch();
				system("cls");
				break;
		}
		operated = NULL;
	}
	return 0;
}