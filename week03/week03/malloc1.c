/* 
���� �޸� �Ҵ� : �ʿ��� ��ŭ �޸𸮸� �ü���κ��� �Ҵ�޾Ƽ� ����ϰ�, ����� ������ �ý��ۿ� �޸� �ݳ�
(���� ���߿� �޸𸮸� �Ҵ� , �����϶� x)
�ʿ��� ��ŭ�� �Ҵ�ް� �ʿ��� ���� ����ϰ� �ݳ��ϱ⿡ �޸𸮸� ȿ�������� ��� ����

int *p;

p = (int *)malloc(sizeof(int));
malloc�Լ��� size ����Ʈ ��ŭ�� �޸� ������ �Ҵ�, ���� �޸� ������ ���� �ּҸ� ��ȯ -> ��ȯ�Ǵ� �ּ��� Ÿ���� void�̹Ƿ� ������ �����ͷ� ����ȯ���������

*p = 1000;
���� �޸𸮴� �����ͷθ� ��� ���� , *p�� p�� ����Ű�� ����̴�.
p�� ����Ű�� ��ҿ� 1000�� ����ȴ�.

free(p);
���� �޸� �ݳ�
�޸� ������ �ü���� ��ȯ
*/


// malloc�� �̿��� ���� 10�� ������ �� �ִ� ���� �޸𸮸� �Ҵ��ϰ� free�� �̿��� �޸� �ݳ�

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main()
{
	int* p;

	p = (int*)malloc(SIZE * sizeof(int));

	if (p == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� ����\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;

	for (int i = 0; i < SIZE; i++)
		printf("%d ", p[i]);

	free(p);
	return 0;
}