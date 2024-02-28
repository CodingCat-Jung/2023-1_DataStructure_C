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

	// 1. ���� ����
	stack s;
	stack_init(&s);

	stack s1;
	stack_init(&s);

	// 2. ���ڿ� �Է� ����
	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%s", str);

	// 3. ���ڿ� ����� ���
	for (int i = 0; i < SIZE; i++) {
		char chr = tolower(str[i]);

		// 3-1. ����ְų� ���ڿ��� ���� �� �� ��ҿ� ������
		if (is_empty(&s) || chr == peek(&s)) {
			count++;
			push(&s, chr);
		}
		
		// 3-2. �ٸ� ���ڰ� ������ 
		else if (chr != peek(&s)) {
			printf("%d%c", count, peek(&s));
			count = 0; // count �ʱ�ȭ
			while (!is_empty(&s)) // ���� �����
				pop(&s);
			i--;
		}
	}
	return 0;
}