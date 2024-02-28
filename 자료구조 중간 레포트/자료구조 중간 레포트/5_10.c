#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element; // typedef���� int���� element������ ����
typedef struct { // ť�� ��ҵ��� ����ü�� ����
	int front, rear; // front�� rear ����
	element data[MAX_SIZE]; // ť 1���� �迭�� ����
}QueueType; // ťŸ��

void error(char* message) // ���� �޼��� ��� �Լ�
{
	fprintf(stderr, "%s\n", message); // �Ű������� �Է� ���� message ���
	exit(1); // ����
}

// �ʱ�ȭ �Լ�
void init(QueueType* q)
{
	q->front = 0; // ����ť : front�� rear�� 0���� �ʱ�ȭ
	q->rear = 0;
}

// ��ȭ�������� üũ
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front); //front�� rear���� �ϳ� ���̸� ��ȭ����
}

// ����������� üũ
int is_empty(QueueType* q)
{
	return (q->front == q->rear); // front�� rear�� ������ �������
}

// ���� �Լ�
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("ť�� ��ȭ����."); // is_full�� ��ȭ�������� üũ ���� ��ȭ�����̸� ���� �޼��� �������� 
		return; // ����
	}
	q->rear = (q->rear + 1) % MAX_SIZE; // q->rear�� �ϳ� ������Ű�� 
	q->data[q->rear] = item; // ������Ų q->rear ��ġ�� q->data�� item �߰� 
}

// ���� �Լ�
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("ť�� �������."); // is_empty�� ����������� üũ ���� ��������̸� ���� �޼��� ��������
		return -1; // ����
	}
	q->front = (q->front + 1) % MAX_SIZE; // q->front�� �ϳ� ������Ű��
	return q->data[q->front]; // ������Ų q->front ��ġ�� q->data�� �ش��ϴ� ���� ��ȯ
}

// ���� �Լ�
element peek(QueueType* q)
{
	if (is_empty(q)) {
		error("ť�� �������."); // is_empty�� ����������� üũ ���� ��������̸� ���� �޼��� ��������
		return -1; // ����
	}
	return q->data[(q->front + 1) % MAX_SIZE]; // q->front�� �ϳ� ������Ű�� �ش� ��ġ�� q->data ���� ��ȯ
}

void main() {
	QueueType q; // ����ü ���� ����

	init(&q); // ����ť �ʱ�ȭ

	// ť�� F(0) �� F(1)�� �� �ʱ�ȭ
	// ť�� ���Լ���
	enqueue(&q, 0);
	enqueue(&q, 1);
	enqueue(&q, 1);

	element e1, e2, e3; //element�� ���� e1, e2, e3 ����

	printf("F(0): %d\n", dequeue(&q)); // F(0) ���
	printf("F(1): %d\n", dequeue(&q)); // F(1) ���
	enqueue(&q, 0);
	enqueue(&q, 1);
	

	e1 = dequeue(&q);
	e2 = dequeue(&q);
	e3 = e1 + e2; // F(2) = F(1) - F(0) 
	printf("F(2): %d\n", e3); // F(2) ���
	enqueue(&q, e3); //F(2) ���� �ٽ� �־���
	enqueue(&q, e3);

	// i�� 2���� 9���� 8�� �ݺ�
	for (int i = 2; i < 10; i++) {
		// ť���� F(n-1)�� F(n-2) ����
		element e1 = dequeue(&q);
		element e2 = dequeue(&q);
		element e3 = e1 + e2; // F(n) = F(n-1) - F(n-2) ���

		printf("F(%d):", i + 1); // F(i+1) ���
		printf(" %d\n", e3); // F(n) ���
		enqueue(&q, e3); //F(n) ���� �ٽ� �־���
		enqueue(&q, e3); 
	}
}