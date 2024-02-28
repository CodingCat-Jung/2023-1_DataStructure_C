// 1번. 정수를 입력 받아서 순서를 거꾸로 하는 프로그램

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

    // 마지막 노드를 찾기 위해 끝까지 이동
    while (current->next != NULL) {
        current = current->next;
    }

    // 마지막 노드부터 역순으로 출력
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("\n");
}

int main() {
    // 1. 정수 배열 크기 입력 받음
    int size;
    printf("정수 배열의 크기는? ");
    scanf("%d", &size);

    // 2. 입력한 정수 개수 만큼 정수를 입력받음

    // 이중 연결 리스트 생성 및 데이터 추가
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < size; i++) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

        int n;
        printf("정수를 입력하세요: ");
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

    // 3. 이중 연결 리스트를 역순으로 출력
    printf("반전된 정수 배열 : ");
    printReverseList(head);

    // 이중 연결 리스트 메모리 해제
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
