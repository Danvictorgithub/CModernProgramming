#include <stdio.h>
#define MAXQUEUE 3
#define NEXT(n) ((n+1) % MAXQUEUE)

#define OK 0
#define QUEUE_FULL -1
#define QUEUE_EMPTY -2

int queue[MAXQUEUE];
int rear = 0, front = 0;
int size = 0;
int enqueue(int value) {
	if (size == MAXQUEUE) {
		return (QUEUE_FULL);
	}
	size++;
	queue[rear] = value;
	rear = NEXT(rear);
	return OK;
}
int dequeue() {
	if (size == 0) {
		return (QUEUE_EMPTY);
	}
	size--;
	front = NEXT(front);
	return queue[front];
}
int circQueueSize() {
	return size;
}
int main(void) {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	enqueue(4);
	for (int i = 0; i < MAXQUEUE; i++)
		printf("%d ",queue[i]);
	return 0;
}