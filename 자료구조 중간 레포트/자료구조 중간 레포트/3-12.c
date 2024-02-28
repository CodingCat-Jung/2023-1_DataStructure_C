#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // 1개의 정수와 최대 크기가 20인 문자열로 이루어진 구조체
	int item;
	char c[20];
}stu;

void main() {
	stu* s; // 구조체 변수 선언

	s = (stu*)malloc(sizeof(stu)); // 동적 메모리 할당
	s->item = 100; //정수 100 대입
	strcpy(s->c, "just testing"); // 문자열 저장

	printf("%d %s\n", s->item, s->c); // 출력
	free(s); // 동적 메모리 반납
}