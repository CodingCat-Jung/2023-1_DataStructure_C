#include <stdio.h>
#include <string.h>

int lenght = 0;

int str_lenght(char* str) {
	for (int i = 0; str[i] != 0; i++)
		lenght += 1;
}
/*
int lenght(char *str) {

 if(*str == '\0') return 0;
 else return 1 + lenght(str + 1);

 }
*/

int main() {

	int result = 0;
	char str[] = "Hello World";

	result = str_lenght(str);

	printf("str의 길이는 %d입니다.\n", lenght);

	return 0;
}