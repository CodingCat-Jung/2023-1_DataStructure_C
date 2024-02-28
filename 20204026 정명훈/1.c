#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

typedef struct {
	int x;
	int y;
}dot;

int check(dot *d)
{
	if (d->x > 0) {
		if (d->y > 0)
			return 1;
		else
			return 4;
	}
	if (d->x < 0) {
		if (d->y > 0)
			return 2;
		else
			return 3;
	}
}

int main() {
	// 1. 파일 오픈
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("파일 읽기 실패\n");
		return;
	}

	int x, y;
	int arr[1024];
	int a = 0;
	// 2. 동적 할당
	int count;
	while (!feof(fp)) {
		fscanf(fp, "%d", &arr[a]);
		a++;
		count++;
	}

	dot* d1;
	d1 = (dot*)malloc(sizeof(dot));
	


	// 3. 좌표 읽어서 저장
	int j = 0;
	for (int i = 0; i < count; i++) {
		d1->x = arr[i++];
		d1->y = arr[j++];
	}

	// 4. 사분면 확인
	for (int i = 0; i < count; i++) {
		printf("%d %d는 %d사분면입니다.\n", d1->x, d1->y, check(d1));
	}

	// 5. 메모리 반납 및 파일포인터 종료
	free(d1);
	fclose(fp);
	return 0;

}

