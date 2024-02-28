// 3��. ���� ���� ���Ḯ��Ʈ�� �̿��Ͽ� �ܾ����� ����

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

// ���� ���� ����Ʈ �ʱ�ȭ �Լ�
void initList(wordList* list)
{
	list->listSize = 0;
}

// ���� ���� �˻�
int isEmpty(wordList* list)
{
	if (list->listSize == 0) return TRUE;
	else return FALSE;
}

// ��ȭ ���� �˻�
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
		// ����Ʈ�� ����ִ� ���, ù ��
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

	printf("�ܾ��? ");
	gets(tempNode->word);
	printf("�ǹ̴�? ");
	gets(tempNode->mean);
	insert(list, tempNode);
	printf("�Է¿Ϸ�\n");
}

void search(wordList* list)
{
	ListNode* temp = list;
	char key;
	printf("�˻��� �ܾ��? ");
	gets(key);

	while (temp != NULL) {
		if (temp->word == key) {
			printf("%s : %s\n", temp->word, temp->mean);
			return;
		}
		temp = temp->next;
	}
	printf("ã�� ���߽��ϴ�.\n");
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
	printf("��¿Ϸ�\n");
}


int main() {

	wordList list; // �÷��̸���Ʈ
	char cmd; // ����� ��ɾ�

	char name[1024];
	initList(&list);

	do {
		printf("��ɾ �Է��Ͻÿ�. (i:�Է�, s:�˻�, p:���, q:����) : ");

		cmd = getchar();
		getchar(); // newline handing

		switch (cmd)
		{
		case'i':
			insertWord(&list);
			break;

		case 's':
			search(&list);
			printf("�˻� �Ϸ�\n");
			break;

		case'p':
			printList(&list);
			break;

		case'q':
		case'Q':
			break;

		default:
			printf("��ɾ� ����\n");
		}

	} while (cmd != 'q');

	return 0;
}