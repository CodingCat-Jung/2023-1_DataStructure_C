#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
	int nPriority;
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

void addq(int item, int nItems)
{
	int j;

	if (isFull()) {
		printf("queue is full\n");
		exit(0);
	}

	if (nItems == 0) 
		queue[nItems++].nPriority = item;
	else {
		for (j = nItems - 1; j >= 0; j--) {
			if (item < queue[j].nPriority)
				queue[j + 1].nPriority = queue[j].nPriority;
			else
				break;
		}
		queue[j + 1].nPriority = item;
	}

	rear = (rear + 1) % MAX_QUEUE_SIZE;
}

QueueObject deleteq()
{
	if (isEmpty()) {
		printf("queue is empty\n");
		exit(0);
	}
	else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return queue[front];
	}
}

void main() {

	FILE* fp;
	int nCount;
	int nTemp;
	int i;
	QueueObject qobject;

	fp = fopen("data1.txt", "r");
	if (fp == NULL) {
		printf("error\n");
		exit(0);
	}

	nCount = 1;

	while (!feof(fp)) {
		fscanf(fp, "%d", &nTemp);
		addq(nTemp, nCount);
		nCount++;
	}

	for (i = 0; i < nCount - 1; i++) {
		qobject = deleteq();
		printf("%d -> ", qobject.nPriority);
	}
	printf("\n");
	fclose(fp);
}