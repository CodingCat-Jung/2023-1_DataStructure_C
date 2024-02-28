#include<stdio.h>

#define max_size 100

typedef int element; // int���� element������ ����
// ���� ��ҵ��� ����ü�� ����
typedef struct { 
	element stack[max_size]; // element�� ���� �迭 ����
	int top; // top���� ����
}Stacktype;

// ���� �ʱ�ȭ �Լ�
void Stack_init(Stacktype* s) {
	s->top = -1; // �����̹Ƿ� top������ -1�� �ʱ�ȭ
}

// ���� �Լ�
void Stack_push(Stacktype* s, element item) {
	s->stack[++(s->top)] = item; // s->top�� ������Ų �� item�� �־���
	return;
}

// ������ ����ִ��� üũ
int is_empty(Stacktype* s) {
	return s->top == -1; // s->top�� -1�̸� �������
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top]; // t�� ���� s->top�� ����Ű�� s->stack�� ��Ҹ� ����
	s->stack[s->top] = 0; // ���� s->top�� ����Ű�� �� ��� �ʱ�ȭ ��
	s->top--; // ����
	return t; // t��ȯ
}

int main(void) {
	Stacktype s; // ����ü ���� ����
	Stack_init(&s); // ���� �ʱ�ȭ

	char input[max_size]; // ���� �Է� ���� char�� �迭 ����

	printf("���� : ");
	scanf_s("%s", input, sizeof(input)); // input�迭�� ���� �Է¹���

	printf("��ȣ �� : ");

	int i = 0, count = 1; // ��ȣ�� ��ȣ ����Ű�� count���� ����

	// input �迭 ���������� �ݺ�
	while (input[i] != NULL) {

		// input[i]�� �ش��ϴ� ��Ұ� (�̸�
		if (input[i] == '(') {
			Stack_push(&s, count); // push�� count �־���
			printf("%d ", count); // count ���
			count++; // count �ϳ� ����������
		}
		else {
			printf("%d ", Stack_pop(&s)); // pop���� ������ count ���
		}
		i++; // i ���� ���� ��ҷ�
	}
	Stack_init(&s); // ���� �ʱ�ȭ

	return 0;
}