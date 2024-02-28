#include <stdio.h>
#define SIZE 6

void get_integers(int list[]) // int list[] = int *list
{
	printf("6개의 정수를 입력하세요: ");

	for (int i = 0; i < SIZE; ++i)
		scanf("%d", &list[i]); // &list[i] = *(list+i)
}

int cal_sum(int list[]) 
{
	int sum = 0;

	for (int i = 0; i < SIZE; ++i)
		sum += *(list + i);

	return sum;
}

int main() {
	int list[SIZE];

	get_integers(list);
	printf("합 = %d\n", cal_sum(list));
	return 0;
}

/*

배열의 이름이 포인터
따라서 배열이 매개변수로 전달될때 사실 포인터가 전달된다

*/