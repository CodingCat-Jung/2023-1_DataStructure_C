/*
����ü�� ���� �����͸� �����ϰ� �����͸� ���� ����ü ����� ���� ���� , ǥ����� ->
ps�� ����ü�� ����Ű�� �������� �� (*ps).i ���� ps->i
*/

// ���� �޸� �Ҵ��� �̿��� ����ü�� �����ϰ� ���⿡ �����͸� ����
// �������� ������ ����ü�� �����͸� ���ؼ��� ����

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
	char name[10];
	int age;
	double gpa; // ��������� ��Ÿ���� �Ǽ���
}student;

int main()
{
	student* s; // ����ü�� ����Ű�� ������

	s = (student*)malloc(sizeof(student));

	if (s == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� ����\n");
		exit(1);
	}

	strcpy(s->name, "Park");
	s->age = 20;

	free(s);
	return 0;
}