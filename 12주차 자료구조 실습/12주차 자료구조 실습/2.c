// 교재 228 멀티 플레이어 게임
// 문제 2. 5명의 플레이어가 게임을 한다. 게임에 빠지면 누구 순서인지 잊을 수 있다. 원형 리스트를 이용하여 프로그램을 작성해 현재 누구 순서인지 출력
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef char element[100];
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);

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

int main() {
	ListNode* head = NULL;

	head = insert_first(head, "KIM");
	head = insert_first(head, "PARK");
	head = insert_first(head, "CHOI");
	head = insert_first(head, "LEE");
	head = insert_first(head, "MIN");

	ListNode* p = head;

	for (int i = 0; i < 10; i++) {
		printf("현재 차례 = %s \n", p->data);
		p = p->link;
	}
	return 0;
}