// �迭�� ����ִ� ������ ������ �Ųٷ� �ϴ� ���α׷�
#include <stdio.h>
#define MAX_SIZE 100

// element ���� int���� ���ϴ� ����.
// ex) element hi -> hi������ int��
typedef int element;

typedef struct { //������ ��Ҹ� ����ü�� ����
	element stack[MAX_SIZE]; // element������ stack �迭 ����
	int top; // top���� ����
}StackType;

// ���� �ʱ�ȭ
void init(StackType* s)
{
	s->top = -1;
}

// ������ ����ִ��� üũ
int is_empty(StackType* s)
{
	return (s->top == -1); 
}

// ������ ���� á���� üũ
int is_Full(StackType* s)
{
	return (s->top == (MAX_SIZE - 1));
}

// ���� �Լ�
void push(StackType* s, element item)
{
	if (is_Full(s)) return;
	else return s->stack[++(s->top)] = item; // ��ȭ���°� �ƴϸ� top�� ����Ű�� ������ �ϳ� ���� ���Ѽ� ���� ����
}

// ���� �Լ�
element pop(StackType* s)
{
	if (is_empty(s)) return;
	else return s->stack[(s->top)--]; // ������°� �ƴϸ� �� ���� �ִ� ���� ����
}

void main() {
	int size, n; // ���� �迭 ũ�� �Է� ���� size������ ������ �Է¹��� n ���� ����
	StackType s; // ����ü ���� ����
	init(&s); // ���� �ʱ�ȭ

	printf("���� �迭�� ũ��: ");
	scanf("%d", &size); // ���� �迭�� ũ�⸦ �Է¹޾� size�� ����

	printf("������ �Է��Ͻÿ�: ");
	for (int i = 0; i < size; i++) { // size ũ�⸸ŭ ���� �Է� ����
		scanf("%d", &n);
		push(&s, n); // �Է� ���� ���� ���ʴ�� push�������� ���ÿ� ����
	}

	printf("������ ���� �迭: ");
	for (int i = 0; i < size; i++) { // size��ŭ �ݺ�
		printf("%d ", pop(&s)); // pop ������ ���� ��ȯ �޴´�.
	}

}