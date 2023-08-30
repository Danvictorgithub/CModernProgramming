#include <stdio.h>
#include <stdlib.h>
struct LNode {
	int data;
	struct LNode *next;
};
struct BNode {
	int data;
	struct BNode *left;
	struct BNode *right;
};
int LNodeCounter(struct LNode *head) {
	int count = 0;
	struct LNode *current = NULL;
	for (;head != NULL;head = head->next ) {
		count = count + 1;
	}
	return count;
}
void orderedInsert(struct LNode **head,int newData) {
	struct LNode *newNode = malloc(sizeof(struct LNode));
	struct LNode *current = *head;
	newNode->data = newData;
	if (*head == NULL) {
		newNode->next = *head;
		*head = newNode;
	}
	else {
		//if there are less than 1 LNode
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
		// if greater than 1 LNode, therefore there is no need change the head
		else {
			// if first LNode is less than 
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
void printList(struct LNode *head) {
	while (head != NULL) {
		printf("%d\n",head->data);
		head = head->next;
	}
}void slTobst(struct LNode *Lhead, struct Bnode **BHead) {
	int length = LNodeCounter(Lhead);
	slToBstRer(Lhead, BHead,length);
}
void slToBstRer(struct LNode *Lhead, struct BNode **BHead, int length) {
	
}
int main(void) {
	struct LNode *Lhead = NULL;
	struct BNode *Bhead = NULL;
	orderedInsert(&Lhead,1);
	orderedInsert(&Lhead,5);
	orderedInsert(&Lhead,4);
	orderedInsert(&Lhead,2);
	orderedInsert(&Lhead,3);
	int length = LNodeCounter(Lhead);
	
	printf("%d\n",length);
	return 0;
}