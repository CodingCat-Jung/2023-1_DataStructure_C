/*
구조체에 대한 포인터를 선언하고 포인터를 통해 구조체 멤버에 접근 가능 , 표기법은 ->
ps가 구조체를 가리키는 포인터일 때 (*ps).i 보다 ps->i
*/

// 동적 메모리 할당을 이용해 구조체를 생성하고 여기에 데이터를 저장
// 동적으로 생성된 구조체는 포인터를 통해서만 접근

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
	char name[10];
	int age;
	double gpa; // 평균평점을 나타내는 실수값
}student;

int main()
{
	student* s; // 구조체를 가리키는 포인터

	s = (student*)malloc(sizeof(student));

	if (s == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없음\n");
		exit(1);
	}

	strcpy(s->name, "Park");
	s->age = 20;

	free(s);
	return 0;
}