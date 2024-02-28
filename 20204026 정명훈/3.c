#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

typedef struct {
	int hak;
	char name[20];
	int gender;
	int grade;
}Student;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->rear = q->front = 0;
}

int is_empty(QueueType* q)
{
	return q->front == q->rear;
}

int is_full(QueueType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);

	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� �������");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� �������");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main() {
	// 1. ���� ����
	FILE* fp = fopen("data02.txt", "r");
	if (fp == NULL) {
		printf("������ ���� �� ����\n");
		return;
	}

	QueueType *q;
	Student stu;
	int count = 0;

	// 2. ���Ͽ� ���� �о ����ť�� ����
	while (!feof(fp)) {
		fscanf("%d", stu.hak);
		strcpy("%s", stu.name);
		fscanf("%d", stu.gender);
		fscanf("%d", stu.grade);
		count++;
	}

	for (int i = 0; i < count; i++) {
		fscanf("%d", stu.hak);
		strcpy("%s", stu.name);
		fscanf("%d", stu.gender);
		fscanf("%d", stu.grade);

		
	}

	// 3. ������ �������� �����ϰ� ���




}