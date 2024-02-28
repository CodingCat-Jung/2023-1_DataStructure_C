#include <stdio.h>
// data[] : �˻� ��� ���� �迭
// n : ���� �迭 ������ ����
// target : �˻��ϰ��� �ϴ� ����

int binarySearch(int data[], int n, int target) {
	if (n <= 0)
		return -1;
	else if (target == data[n - 1])
		return (n - 1);
	else
		return binarySearch(data, n - 1, target);
}

int main() {
	int data[] = { 1,2,3,7,5,4 };

	binarySearch(data, 6, 3);

	printf("�迭 �ε��� : %d\n", binarySearch(data, 6, 3));

	return 0;
}