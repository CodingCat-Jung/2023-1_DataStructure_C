#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable :4996)

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree; // 다항식 차수
	float coef[MAX_DEGREE]; // 다항식의 계수(상수 숫자)
}polynomial;

// C = A + B , 구조체가 반환되는 함수
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C; // 결과 다항식

	// ex) A.coef[Apos] -> Apos 배열 인덱스 
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수

	int degree_a = A.degree; // A 차수
	int degree_b = B.degree; // B 차수

	C.degree = MAX(A.degree, B.degree); // 두 개의 다항식 중 최고차항

	while (Apos <= A.degree && Bpos <= B.degree) {

		// 어느 한 쪽이 차수가 크면 차수가 큰 항을 구조체 C로 이동시키고 차수를 낮춤
		if (degree_a > degree_b) {
			// A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

// degree = 차수 , coef = 계수
void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		// 차수를 줄여가면서 출력, p.degrr는 고정
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

int main() {
	printf("1. 배열을 이용한 다항식 \n");
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;

	// 1. 다항식을 수식 형태로 화면에 출력
	print_poly(a);
	print_poly(b);
	// 2. 다항식 더하기
	c = poly_add1(a, b);
	printf("----------------------------------\n");
	// 3. 다항식 합계 출력
	print_poly(c);
}