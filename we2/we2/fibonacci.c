#include <stdio.h>

int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 2) + fib(n - 1));

}

int main() {

	int n;

	printf("n�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &n);

	printf("%d�� �Ǻ���ġ ����� %d\n", n, fib(n));

	return 0;
}