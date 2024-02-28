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
	// 1. ���� ����
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("���� �б� ����\n");
		return;
	}

	int x, y;
	int arr[1024];
	int a = 0;
	// 2. ���� �Ҵ�
	int count;
	while (!feof(fp)) {
		fscanf(fp, "%d", &arr[a]);
		a++;
		count++;
	}

	dot* d1;
	d1 = (dot*)malloc(sizeof(dot));
	


	// 3. ��ǥ �о ����
	int j = 0;
	for (int i = 0; i < count; i++) {
		d1->x = arr[i++];
		d1->y = arr[j++];
	}

	// 4. ��и� Ȯ��
	for (int i = 0; i < count; i++) {
		printf("%d %d�� %d��и��Դϴ�.\n", d1->x, d1->y, check(d1));
	}

	// 5. �޸� �ݳ� �� ���������� ����
	free(d1);
	fclose(fp);
	return 0;

}

