/*
다음과 같이 배열에 숫자가 채워지도록 프로그램을 작성하라.
N x N 인 경우만 해당

ex)	N = 4
	1   2   6   7		0,0 0,1 0,2 0,3
	3   5   8   13		1,0 1,1 1,2 1,3
	4   9   12  14		2,0 2,1 2,2 2,3
	10  11  15  16		3,0 3,1 3,2 3,3

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CanGo(int nx, int ny, int n)
{
	return (nx >= 0 && nx < n && ny >= 0 && ny < n);
}
void Turn(int* nx, int* ny, int n)
{
	if (*nx < n && *ny < 0)
		*ny += 1;
	else if (*nx < 0 && *ny < n)
		*nx += 1;
	else if (*nx >= n)
	{
		*nx += 2;
		*ny -= 1;
	}
	else if (*ny < 0)
	{
		*ny += 2;
		*nx -= 1;
	}
}
void main()
{
	int dx[] = { 1,-1 };
	int dy[] = { -1, 1 };
	int arr[100][100] = { 0, };
	int n;

	printf("N의 크기를 입력하세요: ");
	scanf("%d", &n);

	int totalCount = n * n;
	int count = 0;
	int dir = 0, x = -1, y = 1;
	int nx, ny;

	while (1)
	{
		nx = x + dx[dir];
		ny = y + dy[dir];

		if (!CanGo(nx, ny, n))
		{
			Turn(nx, ny, n);
			dir = (dir + 1) % 2;
		}
		count++;
		arr[ny][nx] = count;
		x = nx;
		y = ny;

		if (count == totalCount)
			break;
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