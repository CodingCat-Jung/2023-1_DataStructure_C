#include <stdio.h>

int power(int x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, (n - 1) / 2);
}

int main() {

	int x, n;

	printf("x^n�� ����ϱ� ���� x�� n�� �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &n);

	printf("%d^%d�� ����� %d �Դϴ�.\n", x, n, power(x, n));

	return 0;
}