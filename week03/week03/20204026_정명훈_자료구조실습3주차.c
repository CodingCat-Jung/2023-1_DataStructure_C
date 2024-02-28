#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable :4996)

// 배열은 동일한 타입의 데이터를 한 번에 여러 개 만들 때 사용
// 연속적인 메모리 공간이 할당되고, 인덱스 번호를 사용해서 쉽게 접근 가능

// 구조체는 다양한 타입의 데이터들을 묶는 방법
// struct 구조체이름 구조체변수;
// struct studentTag s; 에서 struct 키워드 다음에 오는 structTag는 구조체를 구별할 수 있게 하는 식별자로서 구조체 태그라고 함 (구조체 형식만 정의, 실제로 구조체가 만들어진 것은 아님)
// 구조체 안에 멤버를 사용하려면 구조체 변수 뒤에 .(멤버연산자)을 사용 , ex) s.age  
// typedef studentTag {} student; , 새로운 타입 student만을 사용해서 변수 선언 student s;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101

#define ROWS 3
#define COLS 4

#define SIZE 100

// 다항식 구조체 
typedef struct {
	int degree; // 다항식 차수
	float coef[MAX_DEGREE]; // 다항식의 계수(상수 숫자)
}polynomial;

// C = A + B , 구조체가 반환되는 함수
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C; // 결과 다항식

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
		// 차수를 줄여가면서 출력
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
	// 마지막에 공백을 남겨줘야 그 빈칸에 오류가 생기지 않음
	// 모든 string의 끝은 공백이어야함
	// 뒤집을 때 그냥 뒤집고 끝내면 종료 위치를 파악할 수 없기 때문이다.
	*(reverse + j + 1) = '\0';
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
	printf("\n");


	printf("2. 2중 배열 사용하기\n");
	int nAr[SIZE][SIZE];
	int TransAr[SIZE][SIZE];
	char chTemp = '0';
	int nTemp;
	int nCount = 0, nRow = 0; // 행과 열의 개수 카운트

	FILE* fp;
	// 1.데이터파일 오픈
	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("오류\n");
		return 0;
	}

	// 2. 행렬 데이터 초기화
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			nAr[i][j] = -1;
			TransAr[i][j] = -1;
		}
	}

	// 3. 행의 개수 확인
	while (!feof(fp)) {
		if (chTemp == '\n')
			break;
		fscanf(fp, "%d%c", &nTemp, &chTemp);
		nCount++;
	}
	rewind(fp);

	// 4. 원본 행렬 읽기
	while (!feof(fp)) {
		for (int i = 0; i < nCount; i++)
			fscanf(fp, "%d", &nAr[nRow][i]);
		nRow++;
	}

	// 5. 원본 행렬 출력
	printf("Original Matrix\n");
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCount; j++) {
			printf("%d\t", nAr[i][j]);
		}
		printf("\n");
	}

	// 6. 전치 행렬
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCount; j++) {
			TransAr[j][i] = nAr[i][j];
		}
	}

	// 7. 전치 행렬 출력
	printf("Translate Matrix\n");
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < nRow; j++) {
			printf("%d\t", TransAr[i][j]);
		}
		printf("\n");
	}

	fclose(fp);
	printf("\n");


	printf("3. 1차원 배열 활용 \n");
	int ISBN[13];
	int nCou = 0;
	int nResult = 0;

	// 1. 배열에서 데이터 읽어들여 1차원 배열에 저장
	FILE* fp1 = fopen("data01.txt", "r");
	if (fp == NULL) {
		printf("오류\n");
		return 0;
	}
	while (!feof(fp1)) {
		if (nCou > 13)
			printf("유효하지 않은 ISBN 번호 \n");
		fscanf(fp, "%d", &ISBN[nCou]);
		nCou++;
	}

	// 2. 1차원 배열을 인자값으로 ISBN 여부 확인
	nResult = is_ISBN(ISBN);

	// 3. 입력반은 ISBN과 유효성 여부 출력
	for (int i = 0; i < 13; i++)
		printf("%d", ISBN[i]);
	if (nResult == 1)
		printf("은 유효한 ISBN입니다.\n");
	else
		printf("은 유효하지 않는 ISBN입니다.\n");

	fclose(fp1);
	printf("\n");


	// 자신의 이름을 뒤집어서 출력
	printf("4. 포인터 연습\n");
	char name[50];
	char reverse[50] = { 0 };

	printf("이름을 입력하세요: ");
	scanf("%s", name);

	reverse_name(name, reverse);
	printf("뒤집은 이름 : %s\n", reverse);

	return 0;
}