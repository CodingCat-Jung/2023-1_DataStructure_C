/*
20204026 ������
1. data01.txt ���Ͽ� ����Ǿ� �ִ� x,y ���� �迭�� �����ϰ�, �� ���� ������ �Ÿ��� �Ҽ��� 5�ڸ����� ����ϰ� �Ʒ��� ���� ���
*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

// ����ü ���� x,y�� ���� �����ϱ� ����
typedef struct {
	double x;
	double y;
}dot;

// �� ���� ������ �Ÿ��� ����ϴ� �Լ� ����
double DISTANCE(double x_dis, double y_dis)
{
	return sqrt(pow(x_dis, 2) + pow(y_dis, 2));
}

int main() {
	// 1. data01.txt ���� ����
	FILE* fp = fopen("data01.txt", "r"); // data01.txt ������ �б� ���� ���� ������ ���� ����ü�� fp�� �Ҵ�
	if (fp == NULL) { // ���� fp�� NULL�� ��� ���� ���� ����
		printf("���� �б� ����\n");
		return 0; // ���α׷� ����
	}

	int x, y;

	// 2. ������ ���� �� �����Ҵ�
	// ���Ͽ� �ִ� �ڷ��� ������ �о�鿩�� ���� �Ҵ翡 �̿�
	int count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y); // ���� �ϳ��� �о x,y ����
		count++; // ���� ���� ������ ������ ����ŭ ī��Ʈ
	}

	// �迭�� x,y ���� �����ϱ� ���� 2�� �迭�� ���ؼ� ���� ������ ���� �� ���� �Ҵ�
	// 2���� �迭�� �����Ҵ��� �ϱ� ���ؼ��� 1���� �迭�� ������ŭ �����Ҵ�

	// ���������� ����
	dot** p;
	// ����� �迭�� �Ҵ� : �������� �迭�� �Ҵ��� ��.
	p = (dot**)malloc(sizeof(dot*) * count); // ���� ���� ������ ���� ������ �� count�� �̿���.
	for (int i = 0; i < count; i++) { // count��ŭ �ݺ�
		// �� 1���� �迭���� �Ҵ�
		*(p + i) = malloc(sizeof(dot));
	}

	rewind(fp); // fp�� ���� ��ġ�� �ٽ� �ű�

	// 3. ���Ͽ��� �о�鿩 �迭�� x,y ���� ����
	for (int i = 0; i < count; i++) { // count��ŭ �ݺ�
		fscanf(fp, "%d", &x);
		fscanf(fp, "%d", &y);

		p[i]->x = x;
		p[i]->y = y;
	}

	// 4. �� ���� ������ �Ÿ��� �Ҽ��� 5�ڸ����� ����ϰ� ���
	int nCount = 0; // ����� �� ��ȣ �ű�� ���� ����
	
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {

			// p[i]�� x ���� p[j]�� x ���� ���� , p[i]�� y ���� p[j]�� y ���� ���̸� ���Ѵ�
			double x_dis = p[i]->x - p[j]->x;
			double y_dis = p[i]->y - p[j]->y;

			// ���� ������ �Ÿ��� ����԰� ���ÿ� �Ÿ� ����ϴ� �Լ� ȣ��
			printf("%d. (%.0f, %.0f)�� (%.0f, %.0f)�� ������ �Ÿ��� %.5f �Դϴ�.\n", nCount + 1, p[i]->x, p[i]->y, p[j]->x, p[j]->y, DISTANCE(x_dis, y_dis));
			nCount++; // ���� ����� ���� ��ȣ �ű�� ���� �ϳ� ����
		}
	}
	
	return 0;
}