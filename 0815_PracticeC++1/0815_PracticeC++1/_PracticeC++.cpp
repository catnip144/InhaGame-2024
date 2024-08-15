/*
	Q1. StopWatch class 설계
	다음의 내용을 포함하는 클래스를 설계하라.

	- get 함수를 갖는 데이터 필드 startTime과 endTime
	- startTime을 현재 시간으로 초기화하는 인수 없는 생성자
	- startTime을 현재 시간으로 재설정하는 start() 함수
	- endTIme을 현재 시간으로 재설정하는 start() 함수
	- endTime을 현재 시간으로 설정하는 stop() 함수
	- 스톱워치의 경과 시간을 밀리초(milliseconds)로 반환하는 getElapsedTime() 함수

	- UML 클래스 다이어그램 작성
	- 하노이, 8퀸 시간 측정 결과 포함.
*/
#include "stopwatch.h"

vector<vector<int>> towers(3);
int totalDisks = 0;
int totalCount = 0;

int n = 0;
vector<bool> checkCol;
vector<bool> checkLeftDiag;
vector<bool> checkRightDiag;
vector<vector<bool>> board;

void HanoiTower(int n, vector<int>& start, vector<int>& mid, vector<int>& to)
{
	if (n == 1)
	{
		to.push_back(start.back());
		start.pop_back();
		++totalCount;
		return;
	}
	HanoiTower(n - 1, start, to, mid);
	HanoiTower(1, start, mid, to);
	HanoiTower(n - 1, mid, start, to);
}

bool CanBePlaced(int x, int y)
{
	if (checkCol[x] || checkLeftDiag[x + y] || checkRightDiag[x - y + n - 1])
		return false;
	return true;
}

void NQueen(int y)
{
	if (y == n)
	{
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
	cout << "원판 개수: ";
	cin >> totalDisks;

	StopWatch hanoiWatch;

	for (int i = totalDisks; i >= 1; i--)
		towers[0].push_back(i);

	HanoiTower(totalDisks, towers[0], towers[1], towers[2]);
	hanoiWatch.Stop();

	cout << "총 옮긴 횟수 : " << totalCount << endl;
	cout << "걸린 시간: " << hanoiWatch.GetElapsedTime() << "ms" << endl << endl;

	cout << "퀸 개수: ";
	cin >> n;

	StopWatch queenWatch;

	totalCount = 0;
	checkCol = vector<bool>(n, false);
	checkLeftDiag = vector<bool>(2 * n + 1, false);
	checkRightDiag = vector<bool>(2 * n + 1, false);
	board = vector<vector<bool>>(n, vector<bool>(n, false));

	NQueen(0);
	queenWatch.Stop();

	cout << "가능한 종류 수: " << totalCount << endl;
	cout << "걸린 시간: " << queenWatch.GetElapsedTime() << "ms" << endl << endl;

	return 0;
}

