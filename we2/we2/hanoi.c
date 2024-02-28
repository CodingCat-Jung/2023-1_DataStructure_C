#include <stdio.h>

// 함수는 호출 했던 곳으로 이동하는데 순환 함수는 자기 자신을 호출하므로 자신의 함수로 돌아갔다가 그 다음에 main함수로 돌아간다
void hanoi_tower(int n, char from, char tmp, char to) {

	if (n == 1) printf("원판 1을 %c 에서 %c로 옮긴다.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp); // 여기서 함수를 호출했으니 함수 첨으로 n-1을 가지고 이동
		printf("원판 %d을 %c 에서 %c로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	} // 호출된 시점으로 넘어간다
}

int main() {
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}