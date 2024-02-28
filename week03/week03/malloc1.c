/* 
동적 메모리 할당 : 필요한 만큼 메모리를 운영체제로부터 할당받아서 사용하고, 사용이 끝나면 시스템에 메모리 반납
(실행 도중에 메모리를 할당 , 컴파일때 x)
필요한 만큼만 할당받고 필요한 때에 사용하고 반납하기에 메모리를 효율적으로 사용 가능

int *p;

p = (int *)malloc(sizeof(int));
malloc함수는 size 바이트 만큼의 메모리 블록을 할당, 동적 메모리 블럭의 시작 주소를 반환 -> 반환되는 주소의 타입은 void이므로 적절한 포인터로 형변환시켜줘야함

*p = 1000;
동적 메모리는 포인터로만 사용 가능 , *p는 p가 가리키는 장소이다.
p가 가리키는 장소에 1000이 저장된다.

free(p);
동적 메모리 반납
메모리 블록을 운영체제에 반환
*/


// malloc을 이용해 정수 10을 저장할 수 있는 동적 메모리를 할당하고 free를 이용해 메모리 반납

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main()
{
	int* p;

	p = (int*)malloc(SIZE * sizeof(int));

	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없음\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;

	for (int i = 0; i < SIZE; i++)
		printf("%d ", p[i]);

	free(p);
	return 0;
}