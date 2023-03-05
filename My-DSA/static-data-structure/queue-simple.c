#include <stdio.h>
#include <stdlib.h> //exit
#define MAXQUEUE 2
int front = 0, rear = 0;
int queue[MAXQUEUE];
int enqueue(int value) {
	if (rear >= MAXQUEUE) {
		printf("queue is full");
		exit(0);
		return 0;
	}
	queue[rear++] = value; 
	return 1;
}
int dequeue() {
	if (front == front) {
		printf("queue is empty");
		exit(0);
	}
	return queue[front++];
}
int isEmpty() {
	return (rear == front) ? 1 : 0;
}
int main(void) {
	enqueue(5);
	enqueue(6);
	for (int i = 0; i < 2; i++) {
		printf("%d ",dequeue());
	}
	return 0;
}