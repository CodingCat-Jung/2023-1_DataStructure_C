#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
	int nNum;
	char name[100];
}QueueObject;

QueueObject queue[MAX_QUEUE_SIZE];
int front, rear;

void initilize()
{
	front = rear = 0;
}

int isEmpty()
{
	return(front == rear);
}

int isFull()
{
	return((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addq(QueueObject item)
{
	if (isFull()) {
		printf("queue is full\n");
	}

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

QueueObject deleteq()
{
	if (isEmpty()) {
		printf("queue is empty\n");
	}

	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

void get_count(QueueObject item)
{
	int count = 0;

	if (front <= rear) {
		for (int i = front + 1; i <= rear; i++) {
			count++;
		}
	}
	
	printf("원형큐에 존재하는 요소 개수는 %d\n", count);
}

void main() {
	FILE* fp;

	int nCount;
	QueueObject temp;

	fp = fopen("data2.txt", "r");
	if (fp == NULL) {
		printf("error\n");
		exit(0);
	}

	nCount = 0;

	while (!feof(fp)) {

		fscanf(fp, "%d%s", &temp.nNum, temp.name);
		addq(temp);
		nCount++;
	}
	printf("front = %d, rear = %d\n", front, rear);

	for (int i = 0; i < nCount; i++) {
		get_count(temp);
		temp = deleteq();
		printf("%d | %s\n", temp.nNum, temp.name);
	}

	printf("front = %d, rear = %d\n", front, rear);

	fclose(fp);
}