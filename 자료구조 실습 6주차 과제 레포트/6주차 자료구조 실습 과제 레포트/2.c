/*
20204026 정명훈
2. 두 개의 행렬 데이터를 data02.txt 파일에서 입력받아 두 행렬의 +,-,*,/ 연산을 수행하는 프로그램 작성
단 동적 할당으로 2차원 배열을 생성하여 작성
*/

#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996) // 경고 제거 구문

// 두 행렬 더하는 함수
void add(int r1, int c1, int r2, int c2, int** p1, int** p2)
{
	int i, j;
	int** add; // 행렬 더한 값 저장 할 이중포인터 정의

	// 두 행렬의 크기가 다른 경우
	if ((r1 != r2) || (c1 != c2)) {
		printf("행렬의 크기가 서로 같지 않아서 연산 불가능\n");
	}
	else {
		printf("----------A + B----------\n");
		// 이중 포인터 sum에 동적 할당 (행)
		add = (int**)malloc(sizeof(int*) * r1);
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복해서
			// 열에 동적 메모리 할당
			add[i] = (int*)malloc(sizeof(int) * c1);
		}
		// add에 두 행렬 더한 값 저장
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				add[i][j] = p1[i][j] + p2[i][j];  //add의 i행과 j열에 행렬A와 행렬B의 i행과 j열값을 각각 더해서 저장
			}
		}
		// add 안에 저장된 내용 출력
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				printf("%d\t", add[i][j]);
			}
			printf("\n");
		}
		// 메모리 해제
		for (i = 0; i < r1; i++) {
			free(add[i]); // 열의 메모리 헤제
		}
		free(add); // 행의 메모리 해제
		printf("\n");
	}
}

// 두 행렬 빼는 함수
void sub(int r1, int c1, int r2, int c2, int** p1, int** p2)
{
	int i, j;
	int** sub; // 행렬 뺀 값 저장 할 이중포인터 정의

	// 두 행렬의 크기가 다른 경우
	if ((r1 != r2) || (c1 != c2)) {
		printf("행렬의 크기가 서로 같지 않아서 연산 불가능\n");
	}
	else {
		printf("----------A - B----------\n");
		// 이중 포인터 sub에 동적 할당 (행)
		sub = (int**)malloc(sizeof(int*) * r1);
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복해서
			// 열에 동적 메모리 할당
			sub[i] = (int*)malloc(sizeof(int) * c1);
		}
		// sub에 두 행렬 뺀 값 저장
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				sub[i][j] = p1[i][j] - p2[i][j];  //sub의 i행과 j열에 행렬A와 행렬B의 i행과 j열값을 각각 빼서 저장
			}
		}
		// sub 안에 저장된 내용 출력
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				printf("%d\t", sub[i][j]);
			}
			printf("\n");
		}
		// 메모리 해제
		for (i = 0; i < r1; i++) {
			free(sub[i]); // 열의 메모리 헤제
		}
		free(sub); // 행의 메모리 해제
		printf("\n");
	}
}

// 두 행렬 곱하는 함수
void mul(int r1, int c1, int r2, int c2, int** p1, int** p2)
{
	int i, j;
	int** mul; // 행렬 곱한 값 저장 할 이중포인터 정의

	// 두 행렬의 크기가 다른 경우
	if ((r1 != r2) || (c1 != c2)) {
		printf("행렬의 크기가 서로 같지 않아서 연산 불가능\n");
	}
	else {
		printf("----------A * B----------\n");
		// 이중 포인터 mul에 동적 할당 (행)
		mul = (int**)malloc(sizeof(int*) * r1);
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복해서
			// 열에 동적 메모리 할당
			mul[i] = (int*)malloc(sizeof(int) * c1);
		}
		// mul에 두 행렬 곱한 값 저장
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				mul[i][j] = p1[i][j] * p2[i][j];  //mul의 i행과 j열에 행렬A와 행렬B의 i행과 j열값을 각각 곱해서 저장
			}
		}
		// mul 안에 저장된 내용 출력
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				printf("%d\t", mul[i][j]);
			}
			printf("\n");
		}
		// 메모리 해제
		for (i = 0; i < r1; i++) {
			free(mul[i]); // 열의 메모리 헤제
		}
		free(mul); // 행의 메모리 해제
		printf("\n");
	}
}

// 두 행렬 나누는 함수
void div(int r1, int c1, int r2, int c2, int** p1, int** p2)
{
	int i, j;
	int** div; // 행렬 나눈 값 저장 할 이중포인터 정의

	// 두 행렬의 크기가 다른 경우
	if ((r1 != r2) || (c1 != c2)) {
		printf("행렬의 크기가 서로 같지 않아서 연산 불가능\n");
	}
	else {
		printf("----------A / B----------\n");
		// 이중 포인터 div에 동적 할당 (행)
		div = (int**)malloc(sizeof(int*) * r1);
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복해서
			// 열에 동적 메모리 할당
			div[i] = (int*)malloc(sizeof(int) * c1);
		}
		// div에 두 행렬 나눈 값 저장
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				div[i][j] = p1[i][j] / p2[i][j];  //mul의 i행과 j열에 행렬A와 행렬B의 i행과 j열값을 각각 나눠서 저장
			}
		}
		// div 안에 저장된 내용 출력
		for (i = 0; i < r1; i++) { // 행의 크기만큼 반복
			for (j = 0; j < c1; j++) { // 열의 크기만큼 반복
				printf("%d\t", div[i][j]);
			}
			printf("\n");
		}
		// 메모리 해제
		for (i = 0; i < r1; i++) {
			free(div[i]); // 열의 메모리 헤제
		}
		free(div); // 행의 메모리 해제
		printf("\n");
	}
}

int main() {
	// 1. 데이터 파일 읽기
	FILE* fp = fopen("data02.txt", "r"); // data02.txt 파일을 읽기 모드로 열어 생성된 파일 구조체를 fp에 할당
	if (fp == NULL) { // 만약 fp가 NULL일 경우 파일 오픈 실패
		printf("파일 읽기 실패\n");
		return 0; // 프로그램 종료
	}

	int r1, c1; // 첫번째 행렬 행과 열을 저장하기 위한 변수
	int r2, c2; // 두번째 행렬 행과 열을 저장하기 위한 변수

	// 2. 행렬을 저장할 이중포인터 정의 후 동적할당 
	// 3. 2차원 배열에 파일에서 정보 읽어들여 저장

	// 첫번째 행렬 저장
	printf("---------- A ----------\n");
	fscanf(fp, "%d %d", &r1, &c1); // 파일에 있는 배열의 행과 열을 읽어서 첫번째 행렬의 행과 열을 저장하는 변수에 저장

	int** p1 = (int**)malloc(sizeof(int*) * r1); // 이중 포인터 동적 메모리 할당
	for (int i = 0; i < r1; i++) { // 행의 크기만큼
		p1[i] = (int*)malloc(sizeof(int) * c1); // 열에 동적 할당
	}
	// A 행렬 출력
	for (int i = 0; i < r1; i++) { 
		for (int j = 0; j < c1; j++) { 
			fscanf(fp, "%d", &p1[i][j]); // 행렬의 값을 하나씩 읽여들어 저장
			printf("%d\t", p1[i][j]); // 행렬 출력
		}
		printf("\n");
	}

	printf("\n");
	printf("---------- B ----------\n");

	// 두번째 행렬 저장
	fscanf(fp, "%d %d", &r2, &c2); // 파일에 있는 배열의 행과 열을 읽어서 첫번째 행렬의 행과 열을 저장하는 변수에 저장

	int** p2 = (int**)malloc(sizeof(int*) * r2);// 이중 포인터 동적 메모리 할당
	for (int i = 0; i < r2; i++) { // 행의 크기만큼
		p2[i] = (int*)malloc(sizeof(int) * c2); // 열에 동적 할당
	}
	// B 행렬 출력
	for (int i = 0; i < r2; i++) {
		for (int j = 0; j < c2; j++) {
			fscanf(fp, "%d", &p2[i][j]); // 행렬의 값을 하나씩 읽여들어 저장
			printf("%d\t", p2[i][j]); // 행렬 출력
		}
		printf("\n");
	}
	printf("\n");
	
	// 4. 연산 수행 함수 호출
	add(r1, c1, r2, c2, p1, p2);
	sub(r1, c1, r2, c2, p1, p2);
	mul(r1, c1, r2, c2, p1, p2);
	div(r1, c1, r2, c2, p1, p2);

	for (int i = 0; i < r1; i++) {
		free(p1[i]); // 열의 메모리 헤제
	}
	free(p1); // 행의 메모리 해제

	for (int i = 0; i < r2; i++) {
		free(p2[i]); // 열의 메모리 헤제
	}
	free(p2); // 행의 메모리 해제

	fclose(fp);

	return 0;
}