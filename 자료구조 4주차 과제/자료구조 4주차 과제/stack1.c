#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화
void init(StackType* s) {
	s->top = -1;
}

// 스택이 비어있는지 체크
int is_empty(StackType* s) {
	return (s->top == -1);
}

// 스택이 포화 상태인지 체크
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 스택에 넣기
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("stack overflow\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

// 스택에서 빼기
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("stack is empty\n");
		return;
	}
	else return s->stack[(s->top)--];
}

int check_matching(char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];

		switch (ch) {
		case '(':
		case '[':
		case '{':
			push(&s, ch);
			break;
		case ')':
		case ']':
		case '}':
			if (is_empty(&s)) return FALSE; // 왼쪽 괄호 없이 오른쪽 괄호만 있는 경우, 괄호 오류
			else {
				// 왼쪽 괄호와 오른쪽 괄호가 일치하지 않는 경우
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']')) return FALSE;
				break;
			}
		}
	}
	if (!is_empty(&s)) return FALSE; // 오른쪽 괄호 없이 왼쪽 괄호만 있는 경우, 괄호 오류

	return TRUE;
}

void main() {
	FILE* fp;
	char buf[1024] = { 0 };

	fp = fopen("data.txt", "r");

	if (fp == NULL) return;

	while (!feof(fp)) {
		fscanf(fp, "%s", buf);

		if (check_matching(buf) == TRUE) printf("괄호검사성공 : ");
		else printf("괄호검사 실패 : ");

		printf("%s\n", buf);
	}

	fclose(fp);
}