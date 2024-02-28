#include<stdio.h>
#include<ctype.h>
#pragma warning (disable : 4996)
#define STACK_SIZE 100
#define SIZE 20
typedef char element;
typedef struct {
	element data[STACK_SIZE];
	int top;
} stack;

void stack_init(stack* s) {
	s->top = -1;
}
int is_full(stack* s) {
	return (s->top == (STACK_SIZE - 1));
}
int is_empty(stack* s) {
	return (s->top == -1);
}
void push(stack* s, element item) {
	s->data[++(s->top)] = item;
}
element pop(stack* s) {
	return s->data[(s->top)--];
}
element peek(stack* s) {
	return s->data[s->top];
}

int main() {

	char str[SIZE] = "";
	int count = 0;
	int count1 = 0;

	// 1. 스택 정의
	stack s;
	stack_init(&s);

	stack s1;
	stack_init(&s);

	// 2. 문자열 입력 받음
	printf("문자열을 입력하시오: ");
	scanf("%s", str);

	// 3. 문자열 압축과 출력
	for (int i = 0; i < SIZE; i++) {
		char chr = tolower(str[i]);

		// 3-1. 비어있거나 문자열이 스택 맨 위 요소와 같으면
		if (is_empty(&s) || chr == peek(&s)) {
			count++;
			push(&s, chr);
		}
		
		// 3-2. 다른 문자가 나오면 
		else if (chr != peek(&s)) {
			printf("%d%c", count, peek(&s));
			count = 0; // count 초기화
			while (!is_empty(&s)) // 스택 비워줌
				pop(&s);
			i--;
		}
	}
	return 0;
}