#include <stdio.h>

// void������ ���ᰡ exit(), return 0�� main�Լ������� �������� (void)�Լ������� ��ǻ� �ǹ� ����.
// ��ȯ������ �Լ��� �ٽ� ȣ��Ǿ����Ƿ� �Լ� ó�� �κ����� �ٽ� ���� �� �������� ���� ��� ����
// ��ȯ�� ���Լ���
// str�� �� ���� ����Ű�� �ֱ� ������ ���ÿ��� �� �պκ��� %c�� ��� �� �� ������ ����� �� ���� ��������
// �Լ� ȣ��� ������ ���ÿ� �Լ� ��ü�� ���� ���� ���ʴ��
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