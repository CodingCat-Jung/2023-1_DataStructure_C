#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element; // typedef으로 int형을 element형으로 정의
typedef struct { // 큐의 요소들을 구조체로 정의
	int front, rear; // front와 rear 정의
	element data[MAX_SIZE]; // 큐 1차원 배열로 정의
}QueueType; // 큐타입

void error(char* message) // 에러 메세지 출력 함수
{
	fprintf(stderr, "%s\n", message); // 매개변수로 입력 받은 message 출력
	exit(1); // 종료
}

// 초기화 함수
void init(QueueType* q)
{
	q->front = 0; // 원형큐 : front와 rear을 0으로 초기화
	q->rear = 0;
}

// 포화상태인지 체크
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front); //front가 rear보다 하나 앞이면 포화상태
}

// 공백상태인지 체크
int is_empty(QueueType* q)
{
	return (q->front == q->rear); // front와 rear가 같으면 공백상태
}

// 삽입 함수
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태."); // is_full로 포화상태인지 체크 만약 포화상태이면 에러 메세지 내보내고 
		return; // 종료
	}
	q->rear = (q->rear + 1) % MAX_SIZE; // q->rear를 하나 증가시키고 
	q->data[q->rear] = item; // 증가시킨 q->rear 위치의 q->data에 item 추가 
}

// 삭제 함수
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태."); // is_empty로 공백상태인지 체크 만약 공백상태이면 에러 메세지 내보내고
		return -1; // 종료
	}
	q->front = (q->front + 1) % MAX_SIZE; // q->front를 하나 증가시키고
	return q->data[q->front]; // 증가시킨 q->front 위치의 q->data에 해당하는 내용 반환
}

// 삭제 함수
element peek(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태."); // is_empty로 공백상태인지 체크 만약 공백상태이면 에러 메세지 내보내고
		return -1; // 종료
	}
	return q->data[(q->front + 1) % MAX_SIZE]; // q->front를 하나 증가시키고 해당 위치의 q->data 내용 반환
}

void main() {
	QueueType q; // 구조체 변수 선언

	init(&q); // 원형큐 초기화

	// 큐에 F(0) 과 F(1)의 값 초기화
	// 큐는 선입선출
	enqueue(&q, 0);
	enqueue(&q, 1);
	enqueue(&q, 1);

	element e1, e2, e3; //element형 변수 e1, e2, e3 선언

	printf("F(0): %d\n", dequeue(&q)); // F(0) 출력
	printf("F(1): %d\n", dequeue(&q)); // F(1) 출력
	enqueue(&q, 0);
	enqueue(&q, 1);
	

	e1 = dequeue(&q);
	e2 = dequeue(&q);
	e3 = e1 + e2; // F(2) = F(1) - F(0) 
	printf("F(2): %d\n", e3); // F(2) 출력
	enqueue(&q, e3); //F(2) 값을 다시 넣어줌
	enqueue(&q, e3);

	// i는 2부터 9까지 8번 반복
	for (int i = 2; i < 10; i++) {
		// 큐에서 F(n-1)과 F(n-2) 꺼냄
		element e1 = dequeue(&q);
		element e2 = dequeue(&q);
		element e3 = e1 + e2; // F(n) = F(n-1) - F(n-2) 계산

		printf("F(%d):", i + 1); // F(i+1) 출력
		printf(" %d\n", e3); // F(n) 출력
		enqueue(&q, e3); //F(n) 값을 다시 넣어줌
		enqueue(&q, e3); 
	}
}