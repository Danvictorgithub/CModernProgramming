#include <stdio.h>
#define MAXQUEUE 10
#define TRUE 1
#define FALSE 0
#define FULL 1
#define NOTFULL 0
int front = -1;
int rear = -1;
int queue[MAXQUEUE];

int isQueueEmpty() {
	return (front-rear == 0) ? TRUE : FALSE;
}
int enqueue(int value) {
	if (rear + 1 >= MAXQUEUE) {
		return FULL;
	}
	queue[++rear] = value;
	return NOTFULL;
}
int dequeue() {
	return (!isQueueEmpty()) ? queue[++front]: -1;
}

int main(void) {
	printf("%d\n",dequeue());
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	printf("%d",dequeue());
	return 0;
}