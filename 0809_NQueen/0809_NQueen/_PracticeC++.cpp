#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, totalCount = 0;
vector<bool> checkCol;
vector<bool> checkLeftDiag;
vector<bool> checkRightDiag;
vector<vector<bool>> board;

bool CanBePlaced(int x, int y)
{
	if (checkCol[x] || checkLeftDiag[x + y] || checkRightDiag[x - y + n - 1])
		return false;

	return true;
}

void PrintBoard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j]) printf("■");
			else printf("□");
		}
		cout << '\n';
	}
	cout << '\n';
}

void NQueen(int y)
{
	if (y == n)
	{
		PrintBoard();
		++totalCount;
		return;
	}
	for (int x = 0; x < n; x++)
	{
		if (CanBePlaced(x, y))
		{
			board[y][x] = true;
			checkCol[x] = checkLeftDiag[x + y] = checkRightDiag[x - y + n - 1] = true;

			NQueen(y + 1);

			board[y][x] = false;
			checkCol[x] = checkLeftDiag[x + y] = checkRightDiag[x - y + n - 1] = false;
		}
	}
}

int main()
{
	cin >> n;

	checkCol = vector<bool>(n, false);
	checkLeftDiag = vector<bool>(2 * n + 1, false);
	checkRightDiag = vector<bool>(2 * n + 1, false);
	board = vector<vector<bool>>(n, vector<bool>(n, false));

	NQueen(0);
	cout << "가능한 종류 수: " << totalCount;

	return 0;
}

