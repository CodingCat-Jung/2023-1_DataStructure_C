#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // 1���� ������ �ִ� ũ�Ⱑ 20�� ���ڿ��� �̷���� ����ü
	int item;
	char c[20];
}stu;

void main() {
	stu* s; // ����ü ���� ����

	s = (stu*)malloc(sizeof(stu)); // ���� �޸� �Ҵ�
	s->item = 100; //���� 100 ����
	strcpy(s->c, "just testing"); // ���ڿ� ����

	printf("%d %s\n", s->item, s->c); // ���
	free(s); // ���� �޸� �ݳ�
}