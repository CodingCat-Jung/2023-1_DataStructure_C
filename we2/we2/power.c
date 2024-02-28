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

	printf("x^n을 계산하기 위해 x와 n을 입력하시오: ");
	scanf("%d %d", &x, &n);

	printf("%d^%d의 결과는 %d 입니다.\n", x, n, power(x, n));

	return 0;
}