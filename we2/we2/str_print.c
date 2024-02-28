#include <stdio.h>

void str_print(char* str) {
	if (*str == '\0') return 0;
	else
		printf("%c\n", *str);
		return str_print(str + 1);
}

int main() {

	char str[] = "Hello World";

	str_print(str);

	return 0;
}