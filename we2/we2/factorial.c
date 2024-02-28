#include<stdio.h>

int factorial(int n) {
	if (n <= 1) return (1);
	else return (n * factorial(n - 1));
}

int main() {

	int n;

	printf("n의 값을 입력하세요: ");
	scanf("%d", &n);
	printf("factorial(%d): %d\n", n, factorial(n));
	return 0;
}