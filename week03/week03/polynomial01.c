#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable :4996)

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree; // ���׽� ����
	float coef[MAX_DEGREE]; // ���׽��� ���(��� ����)
}polynomial;

// C = A + B , ����ü�� ��ȯ�Ǵ� �Լ�
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C; // ��� ���׽�

	// ex) A.coef[Apos] -> Apos �迭 �ε��� 
	int Apos = 0, Bpos = 0, Cpos = 0; // �迭 �ε��� ����

	int degree_a = A.degree; // A ����
	int degree_b = B.degree; // B ����

	C.degree = MAX(A.degree, B.degree); // �� ���� ���׽� �� �ְ�����

	while (Apos <= A.degree && Bpos <= B.degree) {

		// ��� �� ���� ������ ũ�� ������ ū ���� ����ü C�� �̵���Ű�� ������ ����
		if (degree_a > degree_b) {
			// A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A�� == B��
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

// degree = ���� , coef = ���
void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		// ������ �ٿ����鼭 ���, p.degrr�� ����
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

int main() {
	printf("1. �迭�� �̿��� ���׽� \n");
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;

	// 1. ���׽��� ���� ���·� ȭ�鿡 ���
	print_poly(a);
	print_poly(b);
	// 2. ���׽� ���ϱ�
	c = poly_add1(a, b);
	printf("----------------------------------\n");
	// 3. ���׽� �հ� ���
	print_poly(c);
}