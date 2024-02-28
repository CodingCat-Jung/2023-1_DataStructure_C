// �־��� �������� �ݺ��Ǵ� ���ڸ� �����ϴ� ���α׷��� ������ �̿��� �����Ͻÿ�.
#include <stdio.h>
#define MAX_SIZE 100

typedef int element;

typedef struct {
	element stack[MAX_SIZE];
	int top;
}arr;

void init(arr* s) {
	s->top = -1;
}

int is_empty(arr* s) {
	return (s->top == -1);
}

int is_full(arr* s) {
	return s->top == (MAX_SIZE - 1);
}

void push(arr* s, int item) {
	if (is_full(s)) return;
	else s->stack[++(s->top)] = item;
}

element pop(arr* s) {
	if (is_empty(s)) return;
	else return s->stack[(s->top)--];
}

element peek(arr* s) {
	if (is_empty(s)) return;
	else return s->stack[s->top];
}

void main() {
	arr s;
	int n;
	element array[MAX_SIZE];
	init(&s);

	printf("������ �Է��Ͻÿ� : ");
	for (int i = 0; i < 6; i++) {
		scanf("%d", &array[i]);
		if (is_empty(&s)) push(&s, array[i]);
		else {
			array[i] = peek(&s);
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			array[i] = array[j];
			pop(&s,array[j]);
		}
	}

	printf("��� : ");
	for (int i = 0; i < 6; i++) {
		array[i];
	}
}