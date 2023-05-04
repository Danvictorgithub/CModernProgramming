#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXQUEUE 3
#define NEXT(n) ((n+1) % MAXQUEUE) //calculates the next position
int front = 0, rear = 0, size = 0/*,prev = 0*/;
int queue[MAXQUEUE];

int enqueue(int value) {
	if (size == MAXQUEUE) {
		printf("\nqueue is full\n");
		exit(0);
	}
	queue[rear] = value;
	rear = NEXT(rear);
	size++;
	return 1;
}
int dequeue() {
	if (size ==  0) {
		printf("\nqueue is empty\n");
		exit(0);
	}
	// prev = front;
	front = NEXT(front);
	size--;
	// return queue[prev];
	return queue[(front == 0) ? MAXQUEUE-1 : front-1];
}
int main(void) {
	int option;
	int value;
	while (1) {
		system("cls");
		printf("\n1. Enqueue\n");
		printf("\n2. Dequeue\n");
		printf("\n3. Display\n");
		printf("option: ");
		scanf("%d",&option);
		switch(option) {
		case 1:
			system("cls");
			printf("Enter value: ");
			scanf("%d",&value);
			enqueue(value);
			getch();
			break;
		case 2:
			system("cls");
			printf("value dequeued is %d",dequeue());
			getch();
			break;
		case 3:
			system("cls");
			for (int j = front, i = 0; i < MAXQUEUE;i++,j=NEXT(j)) {
				printf("%d ",queue[j]);
			}
			getch();
			system("cls");
			break;
		case 0:
			system("cls");
			exit(0);
			break;
		}

	}
	return 0;
}