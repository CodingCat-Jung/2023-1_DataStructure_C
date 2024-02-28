#include <stdio.h>

int maze[8][10] = 
{
	1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,1,1,1,1,1,
	1,1,1,1,0,1,1,1,1,1,
	1,1,1,1,0,1,1,1,1,1,	
	1,1,1,1,0,0,0,0,1,1,
	1,1,1,1,1,1,1,0,1,1,
	1,1,1,1,1,1,1,0,1,1,
	1,1,1,1,1,1,1,0,1,1
};

int visited[8][10]; // ������ ��� ��ŷ

void mazeExplorer(int i, int j) {

	// �̹� ������ ���� �ߺ� ���ϱ� ����
	visited[i][j] = 1;
	printf("%d, %d\n", i, j);

	// �������� �̵� �ϴ� ���
	if (j + 1 < 10 && maze[i][j + 1] != 1 && visited[i][j + 1] == 0)
		mazeExplorer(i, j + 1);

	// �������� �̵� �ϴ� ���
	if (j - 1 >= 0 && maze[i][j - 1] != 1 && visited[i][j - 1] == 0)
		mazeExplorer(i, j - 1);

	// �������� �̵� �ϴ� ���
	if (i + 1 < 8 && maze[i + 1][j] != 1 && visited[i + 1][j] == 0)
		mazeExplorer(i + 1, j);

	// �������� �̵� �ϴ� ���
	if (i - 1 >= 0 && maze[i - 1][j] != 1 && visited[i - 1][j] == 0)
		mazeExplorer(i - 1, j);
}

int main() {

	int i, j;

	printf("Maze Exploring Start. \n");
	mazeExplorer(1, 0);
	printf("Maze Exploring Finish. \n");

	return 0;
}