#include<stdio.h>

// ��ȯ recursion �̶� � �˰����̳� �Լ��� �ڱ� �ڽ��� ȣ���Ͽ� ������ �ذ��ϴ� ���α׷�

int factorial(int n) {
	if (n <= 1) return (1);
	else return (n * factorial(n - 1));
}

// �ŵ����� ��� ���α׷� x^n
int power(int x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) // n�� ¦���� ���
		return power(x * x, n / 2);
	else // n�� Ȧ���� ���
		return x * power(x * x, (n - 1) / 2);
}

int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 2) + fib(n - 1));

}

int lenght = 0;

int str_lenght(char* str) {
	for (int i = 0; str[i] != 0; i++)
		lenght += 1;
}

void str_print(char* str) {
	if (*str == '\0') return 0;
	else
		printf("%c ", *str);
	return str_print(str + 1);
}

void str_reverse(char* str) {
	if (*str == '\0') return 0;
	else {
		str_reverse(str + 1);
		printf("%c ", *str);
	}
}

// ���� �˻� , n�� �迭�� ũ�� �ڿ������� target�� ���غ��� -1�ذ��鼭 �� ���� �տ� �ִ� ��Ҷ� ��
int binarySearch(int data[], int n, int target) {
	if (n <= 0)
		return -1;
	else if (target == data[n - 1])
		return (n - 1);
	else
		return binarySearch(data, n - 1, target);
}

int main() {

	int n;
	printf("1.Factorial\n");
	printf("n�� ���� �Է��ϼ���: ");
	scanf("%d", &n);
	printf("factorial(%d): %d\n", n, factorial(n));
	printf("\n");

	int x, y;
	printf("2.Power\n");
	printf("x^n�� ����ϱ� ���� x�� y�� �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);
	printf("%d^%d�� ����� %d �Դϴ�.\n", x, y, power(x, y));
	printf("\n");

	int m;
	printf("3.Fibonacci\n");
	printf("m�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &m);
	printf("%d�� �Ǻ���ġ ����� %d\n", n, fib(n));
	printf("\n");

	printf("4.���ڿ� ���� ���\n");
	int result = 0;
	char str[] = "Hello World";
	result = str_lenght(str);
	printf("str�� ���̴� %d�Դϴ�.\n", lenght);
	printf("\n");


	printf("5.���ڿ� ���� �� ���� ���\n");
	str_print(str);
	printf("\n\n");

	printf("6.���ڿ� ���� �Ųٷ� �� ���� ���\n");
	str_reverse(str);
	printf("\n\n");

	printf("7.���� �˻�\n");
	int data[] = { 1,2,3,7,5,4 };
	binarySearch(data, 6, 3);
	printf("�迭 �ε��� : %d\n", binarySearch(data, 6, 3));
	printf("\n");

	return 0;
}