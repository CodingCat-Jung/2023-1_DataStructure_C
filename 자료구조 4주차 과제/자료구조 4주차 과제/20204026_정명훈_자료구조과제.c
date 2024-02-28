// ����2�� ����3�� ��ġ�� ����������� ����Ͽ� ������ ���� ����� ������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ������ ����
#define MAX_STACK_SIZE 100

// element ���� int���� ���ϴ� ����.
// ex) element hi -> hi������ int��
typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ
void init(StackType* s) {
	s->top = -1;
}

// ������ ����ִ��� üũ
int is_empty(StackType* s) {
	return (s->top == -1);
}

// ������ ��ȭ �������� üũ
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// ���ÿ� �ֱ�
void push(StackType* s, element item) {
	if (is_full(s)) return;
	else s->stack[++(s->top)] = item;
}

// ���ÿ��� ����
element pop(StackType* s) {
	if (is_empty(s)) exit(1);
	else return s->stack[(s->top)--];
}

// ���࿡ s ���ÿ� �ƹ��͵� ������ �׳� ����
// else ���� ��ġ�� �̵�
element peek(StackType* s) {
	if (is_empty(s)) exit(1);
	else return s->stack[(s->top)];
}

// ��ȣ Ȯ�� ����
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
			// ���ÿ� �ִ� �����ڿ� ���ڿ��� ������ �켱���� �ľ�
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(': // ���� ��ȣ�� ������ ���ÿ� �ִ´�.
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: // �ǿ�����
			printf("%c", ch);
			break;
		}
		// end of switch
		// �������� ��� 
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
			value = ch - '0'; // ������ ���ڿ� 0�� ���� int������ �ٲ� (���ڷ� �� ��ȯ)
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
		printf("���� ǥ����� %s\n", buf);
		
		printf("����ǥ����� ");
		infix_to_postfix(buf);
		printf("\n");

		fscanf(fp2, "%s", buf);
		result = eval(buf);
		printf("������� %d\n\n", result);
	}

	fclose(fp1);
	fclose(fp2);
}