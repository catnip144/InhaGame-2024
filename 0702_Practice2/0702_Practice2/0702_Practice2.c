/*
N x N 의 2차원 배열에 숫자가 다음과 같이 시계 방향으로 채워지도록 프로그램을 작성하라.

ex	N = 3
	1 2 3
	8 9 4
	7 6 5

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int n;
	int arr[100][100] = { 0, };

	printf("N의 크기를 입력하세요 : ");
	scanf("%d", &n);

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	int totalCount = n * n;
	int currentCount = 1;
	int currentDir = 0;
	int x = 0, y = 0;

	while (1)
	{
		arr[y][x] = currentCount;

		int nx = x + dx[currentDir];
		int ny = y + dy[currentDir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[ny][nx] > 0)
		{
			if (currentCount == totalCount)
				break;

			currentDir = (currentDir + 1) % 4;
			continue;
		}
		x = nx, y = ny;
		currentCount++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}