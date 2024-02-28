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

int visited[8][10]; // 지나온 경로 마킹

void mazeExplorer(int i, int j) {

	// 이미 지나간 곳은 중복 피하기 위해
	visited[i][j] = 1;
	printf("%d, %d\n", i, j);

	// 동쪽으로 이동 하는 경우
	if (j + 1 < 10 && maze[i][j + 1] != 1 && visited[i][j + 1] == 0)
		mazeExplorer(i, j + 1);

	// 서쪽으로 이동 하는 경우
	if (j - 1 >= 0 && maze[i][j - 1] != 1 && visited[i][j - 1] == 0)
		mazeExplorer(i, j - 1);

	// 남쪽으로 이동 하는 경우
	if (i + 1 < 8 && maze[i + 1][j] != 1 && visited[i + 1][j] == 0)
		mazeExplorer(i + 1, j);

	// 북쪽으로 이동 하는 경우
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