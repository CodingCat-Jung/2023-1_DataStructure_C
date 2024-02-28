#include <stdio.h>

// void에서는 종료가 exit(), return 0은 main함수에서는 종료지만 (void)함수에서는 사실상 의미 없음.
// 순환적으로 함수가 다시 호출되었으므로 함수 처음 부분으로 다시 시작 후 마지막에 오면 출력 시작
// 순환은 후입선출
// str은 맨 앞을 가리키고 있기 때문에 스택에서 맨 앞부분을 %c로 출력 후 그 스택은 사라짐 그 다음 스택으로
// 함수 호출될 때마다 스택에 함수 자체를 집어 넣음 차례대로
void str_reverse(char* str) {
	if (*str == '\0') return 0;
	else {
		str_reverse(str + 1);
		printf("%c ", *str);
	}
	 
}

int main() {

	char str[] = "Hello World";

	str_reverse(str);

	return 0;
}