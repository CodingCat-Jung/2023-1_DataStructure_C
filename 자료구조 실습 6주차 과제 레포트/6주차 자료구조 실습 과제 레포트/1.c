/*
20204026 정명훈
1. data01.txt 파일에 저장되어 있는 x,y 값을 배열에 저장하고, 각 점들 사이의 거리를 소수점 5자리까지 계산하고 아래와 같이 출력
*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

// 구조체 정의 x,y의 값을 저장하기 위한
typedef struct {
	double x;
	double y;
}dot;

// 각 점들 사이의 거리를 계산하는 함수 정의
double DISTANCE(double x_dis, double y_dis)
{
	return sqrt(pow(x_dis, 2) + pow(y_dis, 2));
}

int main() {
	// 1. data01.txt 파일 오픈
	FILE* fp = fopen("data01.txt", "r"); // data01.txt 파일을 읽기 모드로 열어 생성된 파일 구조체를 fp에 할당
	if (fp == NULL) { // 만약 fp가 NULL일 경우 파일 오픈 실패
		printf("파일 읽기 실패\n");
		return 0; // 프로그램 종료
	}

	int x, y;

	// 2. 포인터 정의 후 동적할당
	// 파일에 있는 자료의 개수를 읽어들여서 동적 할당에 이용
	int count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y); // 값을 하나씩 읽어서 x,y 저장
		count++; // 파일 안의 정보의 개수의 수만큼 카운트
	}

	// 배열에 x,y 값을 저장하기 위한 2중 배열을 위해서 더블 포인터 정의 후 동적 할당
	// 2차원 배열을 동적할당을 하기 위해서는 1차원 배열의 갯수만큼 동적할당

	// 이중포인터 정의
	dot** p;
	// 행들의 배열을 할당 : 포인터의 배열을 할당해 줌.
	p = (dot**)malloc(sizeof(dot*) * count); // 파일 안의 정보의 개수 저장해 둔 count를 이용함.
	for (int i = 0; i < count; i++) { // count만큼 반복
		// 각 1차원 배열들을 할당
		*(p + i) = malloc(sizeof(dot));
	}

	rewind(fp); // fp를 시작 위치로 다시 옮김

	// 3. 파일에서 읽어들여 배열에 x,y 값을 저장
	for (int i = 0; i < count; i++) { // count만큼 반복
		fscanf(fp, "%d", &x);
		fscanf(fp, "%d", &y);

		p[i]->x = x;
		p[i]->y = y;
	}

	// 4. 각 점들 사이의 거리를 소수점 5자리까지 계산하고 출력
	int nCount = 0; // 출력할 때 번호 매기기 위한 변수
	
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {

			// p[i]의 x 값과 p[j]의 x 값의 차이 , p[i]의 y 값과 p[j]의 y 값의 차이를 구한다
			double x_dis = p[i]->x - p[j]->x;
			double y_dis = p[i]->y - p[j]->y;

			// 점들 사이의 거리를 출력함과 동시에 거리 계산하는 함수 호출
			printf("%d. (%.0f, %.0f)와 (%.0f, %.0f)의 사이의 거리는 %.5f 입니다.\n", nCount + 1, p[i]->x, p[i]->y, p[j]->x, p[j]->y, DISTANCE(x_dis, y_dis));
			nCount++; // 다음 출력을 위해 번호 매기는 변수 하나 증가
		}
	}
	
	return 0;
}