#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
////////////////////////// 단순연결리스트 코드 /////////////////////////////////
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

typedef struct {
	ListNode* head;
	int length;
} ListType;


// 리스트를 초기화
void init(ListType* list)
{
	if (list == NULL)
		return;

	list->head = NULL;
	list->length = 0;
}

int get_length(ListType* list)
{
	return list->length;
}

ListNode* get_node_at(ListType* list, int pos)
{
	int i;
	ListNode* tmp_node = list->head;

	// 없는 위치
	if (pos < 0)
		return NULL;

	// 연결리스트를 pos까지 이동
	for (int i = 0; i < pos; i++) {
		tmp_node = tmp_node->link;
	}

	return tmp_node;
}

// phead : 리스트의 헤드 포인터의 포인터
// p : 선행 노드
// new_node : 삽입할 노드
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
	if (*phead == NULL) {		// 공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {		// 선행노드가 NULL인 경우에 첫번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else {								// p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}

void add(ListType* list, int position, element data)
{
	// 추가할 신규 노드  앞에 있는 노드의 포인터
	ListNode* p;

	// 삽입위치의 유효성 검사
	if ((position >= 0) && (position <= list->length)) {

		// 메모리 동적할당 후 유효성 체크
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) {
			printf("memory allocation failture\n");
			return;
		}

		node->data = data;

		// 신규 노드가 추가될 바로 앞에 위치한 노드 포인터를 얻어온다.
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}

void add_last(ListType* list, element data)
{
	add(list, get_length(list), data);
}

void add_first(ListType* list, element data)
{
	add(list, 0, data);
}

int is_empty(ListType* list)
{
	if (list->head == NULL)
		return TRUE;
	else
		return FALSE;
}

// phead : 헤드포인터에 대한 포인터
// p : 삭제할 노드의 선행 노드
// removed : 삭제될 노드
void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;

	free(removed);
}

void deleteNode(ListType* list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {

		ListNode* p = get_node_at(list, pos - 1);

		remove_node(&(list->head), p, (p != NULL) ? p->link : NULL);
		list->length--;
	}
}

void display(ListType* list)
{
	int i;
	ListNode* node = list->head;

	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}

	printf("\n\n");
}

void clear(ListType* list)
{
	int i;
	for (i = 0; i < list->length; i++) {
		deleteNode(list, i);
	}
}

int search_list(ListType* list, element item)
{
	int nCount = 0;
	ListNode* p;

	p = list->head;

	while (p != NULL) {
		if (p->data == item)
			nCount++;
		p = p->link;
	}

	return nCount;
}

void delete_even(ListType* list)
{
	int i;
	for (i = 0; i < list->length; i+=2) {
		deleteNode(list, i);
	}
}

element listMax(ListType* list)
{
	int max;
	ListNode* p;
	p = list->head;

	// 첫번째 노드의 데이터 값으로 max 셋팅
	if (p != NULL) {
		max = p->data;
		p = p->link;
	}

	while (p != NULL) {
		if (max < p->data)
			max = p->data;
		p = p->link;
	}
	return max;
}

element listMin(ListType* list)
{
	int min;
	ListNode* p;
	p = list->head;

	// 첫번째 노드의 데이터 값으로 min 셋팅
	if (p != NULL) {
		min = p->data;
		p = p->link;
	}

	while (p != NULL) {
		if (min > p->data)
			min = p->data;
		p = p->link;
	}
	return min;
}
////////////////////////// 단순연결리스트 코드 /////////////////////////////////

void main()
{
	FILE* fp;
	int nTemp;
	ListType list; // 연결리스트의 헤드포인터 생성

	init(&list); //  연결리스트 초기화

	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("file not open\n");
		return;
	}

	while (!feof(fp)) {
		fscanf(fp, "%d", &nTemp);

		add_last(&list, nTemp);
	}

	fclose(fp);

	display(&list);

	// 2. 사용자가 입력한 숫자가 몇 개 있는지 출력
	int nCount = 0;

	while (1) {
		printf("값을 입력하세요<0:종료> : ");
		scanf("%d", &nTemp);

		if (nTemp == 0) break;

		nCount = search_list(&list, nTemp);
		
		printf("%d는 리스트에 %d개 있습니다.\n", nTemp, nCount);
	}
	printf("\n");

	// 3. 인덱스상 짝수 번째 위치만 삭제하는 함수 추가
	delete_even(&list);
	display(&list);
	printf("\n");

	// 4. 연결리스트 내에서 최솟값, 최댓값
	nTemp = listMax(&list);
	printf("최대값은 %d입니디.\n", nTemp);


	nTemp = listMin(&list);
	printf("최소값은 %d입니디.\n", nTemp);

	clear(&list);
}