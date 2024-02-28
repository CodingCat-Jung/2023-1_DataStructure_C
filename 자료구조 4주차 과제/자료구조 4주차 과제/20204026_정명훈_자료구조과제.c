// 문제2와 문제3을 합치고 파일입출력을 사용하여 다음과 같은 결과를 보여라

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 스택 사이즈 선언
#define MAX_STACK_SIZE 100

// element 쓰면 int형을 뜻하는 문장.
// ex) element hi -> hi변수는 int형
typedef int element;

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
	if (is_full(s)) return;
	else s->stack[++(s->top)] = item;
}

// 스택에서 빼기
element pop(StackType* s) {
	if (is_empty(s)) exit(1);
	else return s->stack[(s->top)--];
}

// 만약에 s 스택에 아무것도 없으면 그냥 종료
// else 스택 위치를 이동
element peek(StackType* s) {
	if (is_empty(s)) exit(1);
	else return s->stack[(s->top)];
}

// 괄호 확인 구문
int prec(char op) {
	switch (op) {
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case'/':
		return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);

	StackType s;

	init(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
			// 스택에 있는 연산자와 문자열의 연산자 우선순위 파악
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(': // 왼쪽 괄호는 무조건 스택에 넣는다.
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: // 피연산자
			printf("%c", ch);
			break;
		}
		// end of switch
		// 연산자의 경우 
	} // end of while

	while (!is_empty(&s))
		printf("%c", pop(&s));
}

element eval(char exp[]) {
	int op1, op2, value, i;
	int len = strlen(exp);
	char ch;
	StackType s;

	init(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0'; // 문자형 숫자에 0을 빼면 int형으로 바뀜 (숫자로 형 변환)
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	} // end of for loop

	return pop(&s);
}

void main() {
	char buf[1024] = { 0 };
	int result;
	FILE* fp1 = fopen("data01.txt", "r");
	FILE* fp2 = fopen("data02.txt", "r");

	if (fp1 == NULL) return;
	if (fp2 == NULL) return;

	while (!feof(fp1) || (!feof(fp2))) {
		fscanf(fp1, "%s", buf);
		printf("중위 표기식은 %s\n", buf);
		
		printf("후위표기식은 ");
		infix_to_postfix(buf);
		printf("\n");

		fscanf(fp2, "%s", buf);
		result = eval(buf);
		printf("결과값은 %d\n\n", result);
	}

	fclose(fp1);
	fclose(fp2);
}