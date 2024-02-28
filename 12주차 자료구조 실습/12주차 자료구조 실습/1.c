// 교재 p225 원형 연결 리스트 테스트 프로그램
// 문제 1. 원형 리스트를 이용해 리스트에 20,30,40,10을 순서대로 삽입하고 리스트를 출력하는 프로그램
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;

	p = head->link;

	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; 
		head->link = node;
		head = node;
	}
	return head;
}

int main() {
	// 원형리스트에서 항상 헤드포인터는 항상 마지막 노드를 가리킨다.
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);

	print_list(head);
	return 0;
}