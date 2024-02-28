// 주어진 정수에서 반복되는 숫자를 제거하는 프로그램을 스택을 이용해 구현하시오. - 교수님 해답 코드
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef int element;

typedef struct {
	element stack[MAX_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return s->top == (MAX_SIZE - 1);
}

void push(StackType* s, int item) {
	if (is_full(s)) return;
	else s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) return;
	else return s->stack[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) return;
	else return s->stack[s->top];
}

void main() {
	char line[100]; // 사용자 입력 스트링 저장
	int length;
	StackType s;

	init(&s);

	printf("문자열를 입력하시오: ");
	gets_s(line, 100);

	printf("출력 : ");
	length = strlen(line);

	for (int i = 0; i < length; i++) {
		if (is_empty(&s)) {
			push(&s, line[i]);
			printf("%c", line[i]);
		}
		else {
			if (peek(&s) != line[i]) {
				printf("%c", line[i]);
				push(&s, line[i]);
			}
		}
	}
}