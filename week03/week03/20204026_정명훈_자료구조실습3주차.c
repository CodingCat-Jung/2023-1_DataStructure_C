#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable :4996)

// �迭�� ������ Ÿ���� �����͸� �� ���� ���� �� ���� �� ���
// �������� �޸� ������ �Ҵ�ǰ�, �ε��� ��ȣ�� ����ؼ� ���� ���� ����

// ����ü�� �پ��� Ÿ���� �����͵��� ���� ���
// struct ����ü�̸� ����ü����;
// struct studentTag s; ���� struct Ű���� ������ ���� structTag�� ����ü�� ������ �� �ְ� �ϴ� �ĺ��ڷμ� ����ü �±׶�� �� (����ü ���ĸ� ����, ������ ����ü�� ������� ���� �ƴ�)
// ����ü �ȿ� ����� ����Ϸ��� ����ü ���� �ڿ� .(���������)�� ��� , ex) s.age  
// typedef studentTag {} student; , ���ο� Ÿ�� student���� ����ؼ� ���� ���� student s;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101

#define ROWS 3
#define COLS 4

#define SIZE 100

// ���׽� ����ü 
typedef struct {
	int degree; // ���׽� ����
	float coef[MAX_DEGREE]; // ���׽��� ���(��� ����)
}polynomial;

// C = A + B , ����ü�� ��ȯ�Ǵ� �Լ�
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C; // ��� ���׽�

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
		// ������ �ٿ����鼭 ���
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) {
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			B[c][r] = A[r][c];
}

void matrix_print(int A[ROWS][COLS]) {
	printf("==============================\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++)
			printf("%d ", A[r][c]);
		printf("\n");
	}
	printf("==============================\n");
}

int is_ISBN(int ar[]) {
	int nSum = 0;

	// a + 3b + c + 3d ...
	for (int i = 0; i < 13; i++) {
		if ((i % 2) == 1)
			nSum += ar[i] * 3;
		else
			nSum += ar[i];
	}
	if ((nSum % 10) == 0)
		return 1;
	else
		return 0;
}

void reverse_name(char* name, char* reverse) {
	int cnt = strlen(name);
	int i, j;
	for (i = cnt - 1, j = 0; i >= 0; i--, j++) {
		*(reverse + j) = *(name + i);
	}
	// �������� ������ ������� �� ��ĭ�� ������ ������ ����
	// ��� string�� ���� �����̾����
	// ������ �� �׳� ������ ������ ���� ��ġ�� �ľ��� �� ���� �����̴�.
	*(reverse + j + 1) = '\0';
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
	printf("\n");


	printf("2. 2�� �迭 ����ϱ�\n");
	int nAr[SIZE][SIZE];
	int TransAr[SIZE][SIZE];
	char chTemp = '0';
	int nTemp;
	int nCount = 0, nRow = 0; // ��� ���� ���� ī��Ʈ

	FILE* fp;
	// 1.���������� ����
	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("����\n");
		return 0;
	}

	// 2. ��� ������ �ʱ�ȭ
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			nAr[i][j] = -1;
			TransAr[i][j] = -1;
		}
	}

	// 3. ���� ���� Ȯ��
	while (!feof(fp)) {
		if (chTemp == '\n')
			break;
		fscanf(fp, "%d%c", &nTemp, &chTemp);
		nCount++;
	}
	rewind(fp);

	// 4. ���� ��� �б�
	while (!feof(fp)) {
		for (int i = 0; i < nCount; i++)
			fscanf(fp, "%d", &nAr[nRow][i]);
		nRow++;
	}

	// 5. ���� ��� ���
	printf("Original Matrix\n");
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCount; j++) {
			printf("%d\t", nAr[i][j]);
		}
		printf("\n");
	}

	// 6. ��ġ ���
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCount; j++) {
			TransAr[j][i] = nAr[i][j];
		}
	}

	// 7. ��ġ ��� ���
	printf("Translate Matrix\n");
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < nRow; j++) {
			printf("%d\t", TransAr[i][j]);
		}
		printf("\n");
	}

	fclose(fp);
	printf("\n");


	printf("3. 1���� �迭 Ȱ�� \n");
	int ISBN[13];
	int nCou = 0;
	int nResult = 0;

	// 1. �迭���� ������ �о�鿩 1���� �迭�� ����
	FILE* fp1 = fopen("data01.txt", "r");
	if (fp == NULL) {
		printf("����\n");
		return 0;
	}
	while (!feof(fp1)) {
		if (nCou > 13)
			printf("��ȿ���� ���� ISBN ��ȣ \n");
		fscanf(fp, "%d", &ISBN[nCou]);
		nCou++;
	}

	// 2. 1���� �迭�� ���ڰ����� ISBN ���� Ȯ��
	nResult = is_ISBN(ISBN);

	// 3. �Է¹��� ISBN�� ��ȿ�� ���� ���
	for (int i = 0; i < 13; i++)
		printf("%d", ISBN[i]);
	if (nResult == 1)
		printf("�� ��ȿ�� ISBN�Դϴ�.\n");
	else
		printf("�� ��ȿ���� �ʴ� ISBN�Դϴ�.\n");

	fclose(fp1);
	printf("\n");


	// �ڽ��� �̸��� ����� ���
	printf("4. ������ ����\n");
	char name[50];
	char reverse[50] = { 0 };

	printf("�̸��� �Է��ϼ���: ");
	scanf("%s", name);

	reverse_name(name, reverse);
	printf("������ �̸� : %s\n", reverse);

	return 0;
}