// 1��. ������ �Է� �޾Ƽ� ������ �Ųٷ� �ϴ� ���α׷�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* prev;
    struct ListNode* next;
} ListNode;

void printReverseList(ListNode* head) {
    ListNode* current = head;

    // ������ ��带 ã�� ���� ������ �̵�
    while (current->next != NULL) {
        current = current->next;
    }

    // ������ ������ �������� ���
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("\n");
}

int main() {
    // 1. ���� �迭 ũ�� �Է� ����
    int size;
    printf("���� �迭�� ũ���? ");
    scanf("%d", &size);

    // 2. �Է��� ���� ���� ��ŭ ������ �Է¹���

    // ���� ���� ����Ʈ ���� �� ������ �߰�
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < size; i++) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

        int n;
        printf("������ �Է��ϼ���: ");
        scanf("%d", &n);
        newNode->data = n;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 3. ���� ���� ����Ʈ�� �������� ���
    printf("������ ���� �迭 : ");
    printReverseList(head);

    // ���� ���� ����Ʈ �޸� ����
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
