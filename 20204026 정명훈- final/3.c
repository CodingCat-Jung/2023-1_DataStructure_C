// 3번. 동적 이중 연결리스트를 이용하여 단어장을 구현

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef struct ListNode {
	char* word;
	char* mean;
	struct ListNode* next; // rlink
	struct ListNode* previous; // llink
}ListNode;

typedef struct PlayList {
	struct Listnode* now;
	int listSize; 
}wordList;

// 이중 연결 리스트 초기화 함수
void initList(wordList* list)
{
	list->listSize = 0;
}

// 공백 상태 검사
int isEmpty(wordList* list)
{
	if (list->listSize == 0) return TRUE;
	else return FALSE;
}

// 포화 상태 검사
int isFull(wordList* list)
{
	if (list->listSize == NULL) return TRUE;
	else return FALSE;
}

void insert(wordList* list, ListNode* node)
{
	if (isFull(list)) {
		return;
	}
	else {
		// 리스트가 비어있는 경우, 첫 곡
		if (isEmpty(list)) {

			list->now = node;

			node->next = NULL;
			node->previous = NULL;
		}

		list->listSize++;

	}//end of else

}

void insertWord(wordList* list)
{
	ListNode* tempNode;
	tempNode = (ListNode*)malloc(sizeof(ListNode));
	tempNode->word = (char*)malloc(sizeof(char) * 512);
	tempNode->mean = (char*)malloc(sizeof(char) * 512);

	printf("단어는? ");
	gets(tempNode->word);
	printf("의미는? ");
	gets(tempNode->mean);
	insert(list, tempNode);
	printf("입력완료\n");
}

void search(wordList* list)
{
	ListNode* temp = list;
	char key;
	printf("검색할 단어는? ");
	gets(key);

	while (temp != NULL) {
		if (temp->word == key) {
			printf("%s : %s\n", temp->word, temp->mean);
			return;
		}
		temp = temp->next;
	}
	printf("찾지 못했습니다.\n");
}

void printList(wordList* list)
{
	ListNode* temp;
	temp = list->now;

	int num = 1;

	if (isEmpty(list)) {
		printf("PlayList is empty!!\n");
		return;
	}
	else {
		
		do {
			printf("--------------------------------------\n");
			printf("%s : %s\n", temp->word, temp->mean);
			temp = temp->next;
			num++;
		} while (temp != NULL);
		printf("--------------------------------------\n");
	}
	printf("출력완료\n");
}


int main() {

	wordList list; // 플레이리스트
	char cmd; // 사용자 명령어

	char name[1024];
	initList(&list);

	do {
		printf("명령어를 입력하시오. (i:입력, s:검색, p:출력, q:종료) : ");

		cmd = getchar();
		getchar(); // newline handing

		switch (cmd)
		{
		case'i':
			insertWord(&list);
			break;

		case 's':
			search(&list);
			printf("검색 완료\n");
			break;

		case'p':
			printList(&list);
			break;

		case'q':
		case'Q':
			break;

		default:
			printf("명령어 오류\n");
		}

	} while (cmd != 'q');

	return 0;
}