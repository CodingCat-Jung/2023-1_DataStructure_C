#include <stdio.h>
// data[] : 검색 대상 정수 배열
// n : 정수 배열 데이터 개수
// target : 검색하고자 하는 정수

int binarySearch(int data[], int n, int target) {
	if (n <= 0)
		return -1;
	else if (target == data[n - 1])
		return (n - 1);
	else
		return binarySearch(data, n - 1, target);
}

int main() {
	int data[] = { 1,2,3,7,5,4 };

	binarySearch(data, 6, 3);

	printf("배열 인덱스 : %d\n", binarySearch(data, 6, 3));

	return 0;
}