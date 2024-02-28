/*
   3. 큐를 사용하여 피보나치 수열을 계산하시오. 큐에 처음에는 F(0)와 F(1)값이 들어가 있어
   다음에 F(2)를 계산할 때 F(0)을 큐에서 제거한다. 그 다음에 계산된 F(b)를 다시 큐에 넣는다.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_SIZE];
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태.");
		return -1;
	}
	return q->data[(q->front + 1) % MAX_SIZE];
}

void queue_print(QueueType* q)
{
	printf("QUEUE (front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_SIZE;
			printf("%d |", q->data[i]);

			if (1 == q->rear) break;

		} while (1 != q->front);
	}
	printf("\n");
}

void main() {
	QueueType q;

	init(&q);
	enqueue(&q, 0);
	enqueue(&q, 1);
	enqueue(&q, 1);

	for (int i = 0; i < 10; i++) {
		element e1 = dequeue(&q);
		element e2 = dequeue(&q);
		element e3 = e1 + e2;
		printf("%d ", e3);
		enqueue(&q, e3);
		enqueue(&q, e3);
	}
}