/*
�ڷᱸ�� 8���� ���� 4�� - 20204026 ������
���� ����Ʈ���� Ư���� ������ ���� ���� ����� ������ ����ϴ� �Լ��� �ۼ��϶�
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element; // int�� element�� ����
// ��� Ÿ���� ����ü�� ����
typedef struct {
	element data; // ������ ������
	struct LinkNode* link; // ���� ��带 ����ų ������
}ListNode;

// ���Ḯ��Ʈ ���� �ڿ� ���� �Լ�
// newnode�� ���� �� ������ ����� link �����Ͱ� newnode�� ����Ű����
ListNode* insert(ListNode* head, element item) {
	// 1. ������ ��带 ����
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // ���ο� ���
	ListNode* ptr = (ListNode*)malloc(sizeof(ListNode)); // ������ ���

	// 2. ��忡 ������ ����
	p->data = item; // p�� ������ �ʵ忡 item�� �����ϰ�
	p->link = NULL; // ��ũ �ʵ�� ���� ����Ű�� ��尡 �����Ƿ� NULL�Ҵ�

	// 3. ���Ḯ��Ʈ ���� �������� �����ϱ� ���ؼ�
	// ���� ���Ḯ��Ʈ�� ������ ��� 
	// ��� ��尡 p�� ����ų �� �ֵ��� ��ũ �ʵ忡 p�� �ּҰ� �����ϰ� ����
	if (head == NULL) {
		head = p;
		return;
	}
	// ���� ���Ḯ��Ʈ�� ������ �ƴ� ��� - ������ ��带 ã�´�
	// ��� ������ �����ؼ� ��ũ�� ���� ���� ���� �̵�
	// ���� ����� ��ũ�� NULL�� �ƴ� �� ���� �ݺ��Ͽ� ������ ��带 ã�´�
	else {
		ptr = head;
		while (ptr->link != NULL) {
			ptr = ptr->link;
		}
		// ������ ����� ��ũ �ʵ忡 p�� �ּҰ��� �����Ͽ� p�� ����Ű�� ��
		ptr->link = p;
	}

	return head;
}

// Ư���� ������ ���� ���� ����� ������ ���
int list_count(ListNode* head, element key)
{
	// 1. ����� ���� ������ count ���� ����
	int count = 0;

	// 2. head���� ������ ������
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == key) count++;
	}
	return count;
}

void main() {
	// 1. ���� ����Ʈ  ����� ���� �Է� �ޱ�
	int size; // ����� ���� �Է� ���� size ���� ����
	printf("����� ���� : ");
	scanf("%d", &size);

	// 1-1. ����Ʈ ����
	ListNode* head = NULL; // ��� ������ ���� , ���Ḯ��Ʈ �ʱ�ȭ

	// 2. ����� ������ŭ ������ �Է� �ް� ���Ḯ��Ʈ�� ����
	int d; // ������ �Է� ���� ���� ����
	for (int i = 0; i < size; i++) { // size��ŭ
		printf("��� #%d ������ : ", i + 1);
		scanf("%d", &d);
		head = insert(head, d); // head�� ������ ����
	}

	// 3. ���
	int key;
	printf("Ž���� ���� �Է��Ͻÿ� : ");
	scanf("%d", &key);
	printf("%d�� ���� ����Ʈ���� %d�� ��Ÿ���ϴ�.\n", key, list_count(head, key));
}