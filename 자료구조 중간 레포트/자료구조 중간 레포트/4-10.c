// 배열에 들어있는 정수의 순서를 거꾸로 하는 프로그램
#include <stdio.h>
#define MAX_SIZE 100

// element 쓰면 int형을 뜻하는 문장.
// ex) element hi -> hi변수는 int형
typedef int element;

typedef struct { //스택의 요소를 구조체로 정의
	element stack[MAX_SIZE]; // element형으로 stack 배열 선언
	int top; // top변수 선언
}StackType;

// 스택 초기화
void init(StackType* s)
{
	s->top = -1;
}

// 스택이 비어있는지 체크
int is_empty(StackType* s)
{
	return (s->top == -1); 
}

// 스택이 가득 찼는지 체크
int is_Full(StackType* s)
{
	return (s->top == (MAX_SIZE - 1));
}

// 삽입 함수
void push(StackType* s, element item)
{
	if (is_Full(s)) return;
	else return s->stack[++(s->top)] = item; // 포화상태가 아니면 top이 가리키는 곳보다 하나 증가 시켜서 값을 저장
}

// 제거 함수
element pop(StackType* s)
{
	if (is_empty(s)) return;
	else return s->stack[(s->top)--]; // 공백상태가 아니면 맨 위에 있는 값을 제거
}

void main() {
	int size, n; // 정수 배열 크기 입력 받을 size변수와 정수를 입력받을 n 변수 선언
	StackType s; // 구조체 변수 선언
	init(&s); // 스택 초기화

	printf("정수 배열의 크기: ");
	scanf("%d", &size); // 정수 배열의 크기를 입력받아 size에 저장

	printf("정수를 입력하시오: ");
	for (int i = 0; i < size; i++) { // size 크기만큼 정수 입력 받음
		scanf("%d", &n);
		push(&s, n); // 입력 받은 정수 차례대로 push연산으로 스택에 저장
	}

	printf("반전된 정수 배열: ");
	for (int i = 0; i < size; i++) { // size만큼 반복
		printf("%d ", pop(&s)); // pop 연산을 통해 반환 받는다.
	}

}