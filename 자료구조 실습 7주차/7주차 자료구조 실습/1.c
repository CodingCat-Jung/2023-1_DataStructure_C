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
	else return s->stack[++(s->top)] = item; // 포화상태가 아니면 top이 가리키는 곳보다 하나 증가 시켜서 값을 저장
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

	printf("정수 배열의 크기: ");
	scanf("%d", &size); 

	printf("정수를 입력하시오: ");
	for (int i = 0; i < size; i++) { 
		scanf("%d", &n);
		push(&s, n); 
	}

	printf("반전된 정수 배열: ");
	for (int i = 0; i < size; i++) { 
		printf("%d ", pop(&s)); 
	}

}