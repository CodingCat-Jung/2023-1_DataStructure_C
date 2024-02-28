#include <stdio.h>

// �Լ��� ȣ�� �ߴ� ������ �̵��ϴµ� ��ȯ �Լ��� �ڱ� �ڽ��� ȣ���ϹǷ� �ڽ��� �Լ��� ���ư��ٰ� �� ������ main�Լ��� ���ư���
void hanoi_tower(int n, char from, char tmp, char to) {

	if (n == 1) printf("���� 1�� %c ���� %c�� �ű��.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp); // ���⼭ �Լ��� ȣ�������� �Լ� ÷���� n-1�� ������ �̵�
		printf("���� %d�� %c ���� %c�� �ű��.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	} // ȣ��� �������� �Ѿ��
}

int main() {
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}