#include <stdio.h>
#define MAX_SIZE 100

typedef int element;

typedef struct { 
	element stack[MAX_SIZE]; 
	int top; 
}StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_Full(StackType* s)
{
	return (s->top == (MAX_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_Full(s)) return;
	else return s->stack[++(s->top)] = item; // ��ȭ���°� �ƴϸ� top�� ����Ű�� ������ �ϳ� ���� ���Ѽ� ���� ����
}

element pop(StackType* s)
{
	if (is_empty(s)) return;
	else return s->stack[(s->top)--];
}

void main() {
	int size, n; 
	StackType s; 
	init(&s); 

	printf("���� �迭�� ũ��: ");
	scanf("%d", &size); 

	printf("������ �Է��Ͻÿ�: ");
	for (int i = 0; i < size; i++) { 
		scanf("%d", &n);
		push(&s, n); 
	}

	printf("������ ���� �迭: ");
	for (int i = 0; i < size; i++) { 
		printf("%d ", pop(&s)); 
	}

}