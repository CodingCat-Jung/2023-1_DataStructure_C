// 다항식의 0이 아닌 항들은 (계수, 차수)의 형식으로 구조체 배열에 저장
// ex) 10x^5 + 6x^1 + 3 -> ((10,5),(6,1),(3,0))

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct {
	float coef;
	int expon;
}polynomial;

// 8x^3 + 7x^1 + 1
// 10x^3 + 3x^2 + 1
// 하나의 다항식이 시작되고 끝나는 위치를 가라키는 인덱스 변수들을 관리해야함.
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };

int avail = 6;

// 두개의 정수를 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// 새로운 항을 다항식에 추가
// 배열 terms의 다음 빈 공간에 더하는 함수
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}

	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

// C = A + B
// As는 다항식 B의 처음 , Ae는 다항식 A의 마지막
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) 
{
	float tempCoef;
	*Cs = avail;

	while (As <= Ae && Bs <= Be) {

		switch (compare(terms[As].expon, terms[Bs].expon)) {
		// A의 차수 > B의 차수
		case '>':
			attach(terms[As].coef, terms[As].expon);
			As++; break;

		case '=':
			tempCoef = terms[As].coef + terms[Bs].coef;
			if (tempCoef) attach(tempCoef, terms[As].expon);
			As++; Bs++; break;

		case '<':
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++; break;
		}

		// A의 나머지 항들을 이동
		for (; As <= Ae; As++) 
			attach(terms[As].coef, terms[As].expon);
		
		// B의 나머지 항들을 이동
		for (; Bs <= Be; Bs++)
			attach(terms[Bs].coef, terms[Bs].expon);

		*Ce = avail - 1;
	}
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);

	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main() {

	int As = 0, Ae = 2;
	int Bs = 3, Be = 5;
	int Cs, Ce;

	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);

	print_poly(As, Ae);
	print_poly(Bs, Be);

	printf("------------------------------\n");

	print_poly(Cs, Ce);
	return 0;
}