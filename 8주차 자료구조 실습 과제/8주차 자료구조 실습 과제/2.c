/*
자료구조 8주차 문제 2번 - 20204026 정명훈
다음과 같이 단순 연결 리스트의 노드들의 개수를 계산하는 프로그램을 작성하라
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element; // int를 element로 정의
// 노드 타입을 구조체로 정의
typedef struct {
	element data; // 저장할 데이터
	struct LinkNode* link; // 다음 노드를 가리킬 포인터
}ListNode;

// 연결리스트 제일 뒤에 삽입 함수
// newnode를 만든 후 마지막 노드의 link 포인터가 newnode를 가리키도록
ListNode* insert(ListNode* head, element item) {
	// 1. 삽입할 노드를 생성
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드
	ListNode* ptr = (ListNode*)malloc(sizeof(ListNode)); // 마지막 노드

	// 2. 노드에 데이터 저장
	p->data = item; // p의 데이터 필드에 item을 저장하고
	p->link = NULL; // 링크 필드는 아직 가리키는 노드가 없으므로 NULL할당

	// 3. 연결리스트 제일 마지막에 삽입하기 위해서
	// 현재 연결리스트가 공백인 경우 
	// 헤드 노드가 p를 가리킬 수 있도록 링크 필드에 p의 주소값 저장하고 종료
	if (head == NULL) {
		head = p;
		return;
	}
	// 현재 연결리스트가 공백이 아닌 경우 - 마지막 노드를 찾는다
	// 헤드 노드부터 시작해서 링크를 따라 다음 노드로 이동
	// 다음 노드의 링크가 NULL이 아닐 때 까지 반복하여 마지막 노드를 찾는다
	else {
		ptr = head;
		while (ptr->link != NULL) {
			ptr = ptr->link;
		}
		// 마지막 노드의 링크 필드에 p의 주소값을 저장하여 p를 가리키게 함
		ptr->link = p;
	}

	return head;
}

// 노드의 개수를 계산
int list_count(ListNode* head)
{
	// 1. 노드의 개수 저장할 count 변수 선언
	int count = 0;
	
	// 2. head부터 마지막 노드까지
	for (ListNode* p = head; p != NULL; p = p->link) {
		count++;
	}
	return count;
}

void main() {
	// 1. 연결 리스트  노드의 개수 입력 받기
	int size; // 노드의 개수 입력 받을 size 변수 선언
	printf("노드의 개수 : ");
	scanf("%d", &size);

	// 1-1. 리스트 생성
	ListNode* head = NULL; // 헤드 포인터 선언 , 연결리스트 초기화

	// 2. 노드의 개수만큼 데이터 입력 받고 연결리스트에 저장
	int d; // 데이터 입력 받을 변수 선언
	for (int i = 0; i < size; i++) { // size만큼
		printf("노드 #%d 데이터 : ", i + 1);
		scanf("%d", &d);
		head = insert(head, d); // head에 데이터 삽입
	}

	// 3. 노드의 개수 출력
	printf("연결 리스트 노드의 개수 = %d\n", list_count(head));
}