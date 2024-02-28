// ���׽��� 0�� �ƴ� �׵��� (���, ����)�� �������� ����ü �迭�� ����
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
// �ϳ��� ���׽��� ���۵ǰ� ������ ��ġ�� ����Ű�� �ε��� �������� �����ؾ���.
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };

int avail = 6;

// �ΰ��� ������ ��
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// ���ο� ���� ���׽Ŀ� �߰�
// �迭 terms�� ���� �� ������ ���ϴ� �Լ�
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}

	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

// C = A + B
// As�� ���׽� B�� ó�� , Ae�� ���׽� A�� ������
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) 
{
	float tempCoef;
	*Cs = avail;

	while (As <= Ae && Bs <= Be) {

		switch (compare(terms[As].expon, terms[Bs].expon)) {
		// A�� ���� > B�� ����
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

		// A�� ������ �׵��� �̵�
		for (; As <= Ae; As++) 
			attach(terms[As].coef, terms[As].expon);
		
		// B�� ������ �׵��� �̵�
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