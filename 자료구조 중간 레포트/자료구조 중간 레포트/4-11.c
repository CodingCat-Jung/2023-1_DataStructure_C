#include<stdio.h>

#define max_size 100

typedef int element; // int형을 element형으로 정의
// 스택 요소들을 구조체로 정의
typedef struct { 
	element stack[max_size]; // element형 스택 배열 선언
	int top; // top변수 선언
}Stacktype;

// 스택 초기화 함수
void Stack_init(Stacktype* s) {
	s->top = -1; // 스택이므로 top변수를 -1로 초기화
}

// 삽입 함수
void Stack_push(Stacktype* s, element item) {
	s->stack[++(s->top)] = item; // s->top을 증가시킨 후 item을 넣어줌
	return;
}

// 스택이 비어있는지 체크
int is_empty(Stacktype* s) {
	return s->top == -1; // s->top이 -1이면 공백상태
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top]; // t에 현재 s->top이 가리키는 s->stack의 요소를 저장
	s->stack[s->top] = 0; // 현재 s->top이 가리키는 곳 요소 초기화 후
	s->top--; // 제거
	return t; // t반환
}

int main(void) {
	Stacktype s; // 구조체 변수 선언
	Stack_init(&s); // 스택 초기화

	char input[max_size]; // 수식 입력 받을 char형 배열 선언

	printf("수식 : ");
	scanf_s("%s", input, sizeof(input)); // input배열에 수식 입력받음

	printf("괄호 수 : ");

	int i = 0, count = 1; // 괄호의 번호 가리키는 count변수 선언

	// input 배열 마지막까지 반복
	while (input[i] != NULL) {

		// input[i]에 해당하는 요소가 (이면
		if (input[i] == '(') {
			Stack_push(&s, count); // push로 count 넣어줌
			printf("%d ", count); // count 출력
			count++; // count 하나 증가시켜줌
		}
		else {
			printf("%d ", Stack_pop(&s)); // pop으로 마지막 count 출력
		}
		i++; // i 증가 다음 요소로
	}
	Stack_init(&s); // 스택 초기화

	return 0;
}