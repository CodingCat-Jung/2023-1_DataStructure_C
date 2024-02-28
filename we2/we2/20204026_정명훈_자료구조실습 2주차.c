#include<stdio.h>

// 순환 recursion 이란 어떤 알고리즘이나 함수가 자기 자신을 호출하여 문제를 해결하는 프로그램

int factorial(int n) {
	if (n <= 1) return (1);
	else return (n * factorial(n - 1));
}

// 거듭제곱 계산 프로그램 x^n
int power(int x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) // n이 짝수인 경우
		return power(x * x, n / 2);
	else // n이 홀수인 경우
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

// 이진 검색 , n은 배열의 크기 뒤에서부터 target을 비교해보고 -1해가면서 그 다음 앞에 있는 요소랑 비교
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
	printf("n의 값을 입력하세요: ");
	scanf("%d", &n);
	printf("factorial(%d): %d\n", n, factorial(n));
	printf("\n");

	int x, y;
	printf("2.Power\n");
	printf("x^n을 계산하기 위해 x와 y을 입력하시오: ");
	scanf("%d %d", &x, &y);
	printf("%d^%d의 결과는 %d 입니다.\n", x, y, power(x, y));
	printf("\n");

	int m;
	printf("3.Fibonacci\n");
	printf("m의 값을 입력하시오: ");
	scanf("%d", &m);
	printf("%d의 피보나치 결과는 %d\n", n, fib(n));
	printf("\n");

	printf("4.문자열 길이 출력\n");
	int result = 0;
	char str[] = "Hello World";
	result = str_lenght(str);
	printf("str의 길이는 %d입니다.\n", lenght);
	printf("\n");


	printf("5.문자열 문자 한 개씩 출력\n");
	str_print(str);
	printf("\n\n");

	printf("6.문자열 문자 거꾸로 한 개씩 출력\n");
	str_reverse(str);
	printf("\n\n");

	printf("7.이진 검색\n");
	int data[] = { 1,2,3,7,5,4 };
	binarySearch(data, 6, 3);
	printf("배열 인덱스 : %d\n", binarySearch(data, 6, 3));
	printf("\n");

	return 0;
}