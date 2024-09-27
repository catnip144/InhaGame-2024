#include "game_control.h"

vector<vector<bool>> occupied;
vector<vector<bool>> visited;
vector<POINT> remainingArea;

void CreateOccupiedGrid()
{
	occupied = vector<vector<bool>>
		(screenHeight, vector<bool>(screenWidth, false));

	int playerRadius = player.GetRadius();
	int rightX = screenWidth - playerRadius;

	for (int i = playerStartPos.x; i <= rightX; i++)
	{
		occupied[playerRadius][i] = true;
		occupied[playerStartPos.y][i] = true;
	}
	for (int i = playerRadius + 1; i <= playerStartPos.y - 1; i++)
	{
		occupied[i][playerRadius] = true;
		occupied[i][rightX] = true;
	}
	occupied[playerStartPos.y][playerStartPos.x] = true;

	remainingArea.push_back({ playerRadius, playerRadius });
	remainingArea.push_back({ playerRadius, rectView.bottom - playerRadius });
	remainingArea.push_back({ rectView.right - playerRadius, rectView.bottom - playerRadius });
	remainingArea.push_back({ rectView.right - playerRadius, playerRadius });
}

void CreateVisitedGrid()
{
	visited = vector<vector<bool>>
		(screenHeight, vector<bool>(screenWidth, false));
}

int GetUserInput()
{
	if (GetAsyncKeyState('W') & 0x8000) return 'W';
	if (GetAsyncKeyState('A') & 0x8000) return 'A';
	if (GetAsyncKeyState('S') & 0x8000) return 'S';
	if (GetAsyncKeyState('D') & 0x8000) return 'D';
	if (GetAsyncKeyState(VK_CONTROL) & 0x8000) return VK_CONTROL;
	return '\0';
}

pair<int, int> IsInsideRmnArea(POINT& inputPos)
{
	for (int i = 0; i < remainingArea.size(); i++)
	{
		int j = (i == 0) ? remainingArea.size() - 1 : i - 1;
		if (IsBetweenTwoPoints(inputPos, remainingArea[j], remainingArea[i]))
			return { min(i, j), max(i, j) };
	}
	return { -1, -1 };
}

void FillOccupiedArea(vector<POINT>& path, pair<int, int> endContextIdx)
{
	pair<int, int> startContextIdx = IsInsideRmnArea(path[0]);
	vector<POINT> dividingLine;

	dividingLine.push_back(path[0]);
	for (int i = 2; i < path.size(); i++)
	{
		if ((path[i].y != path[i - 2].y) && (path[i].x != path[i - 2].x))
			dividingLine.push_back(path[i - 1]);
	}
	dividingLine.push_back(path.back());

	vector<POINT> area1 = dividingLine;
	vector<POINT> area2 = dividingLine;

	bool canSearchLeft = !IsBetweenTwoPoints(dividingLine[0], dividingLine.back(), remainingArea[endContextIdx.first]);
	bool canSearchRight = !IsBetweenTwoPoints(dividingLine[0], dividingLine.back(), remainingArea[endContextIdx.second]);

	int idx = endContextIdx.first;
	while (canSearchLeft)
	{
		area1.push_back(remainingArea[idx]);
		--idx;

		if (idx == -1)
			idx = remainingArea.size() - 1;
		if (idx == startContextIdx.first || idx == startContextIdx.second)
		{
			area1.push_back(remainingArea[idx]);
			break;
		}
	}
	idx = endContextIdx.second;
	while (canSearchRight)
	{
		area2.push_back(remainingArea[idx]);
		++idx;

		if (idx == remainingArea.size())
			idx = 0;
		if (idx == startContextIdx.first || idx == startContextIdx.second)
		{
			area2.push_back(remainingArea[idx]);
			break;
		}
	}
	SetFillArea(area1, area2);
	remainingArea = area2;

	for (int i = 0; i < path.size(); i++)
		visited[path[i].y][path[i].x] = false;
}

void SetFillArea(vector<POINT>& area1, vector<POINT>& area2)
{
	uncoveredPolygon = area1;
}

bool IsBetweenTwoPoints(POINT inputPos, POINT a, POINT b)
{
	int x1 = a.x, y1 = a.y;
	int x2 = b.x, y2 = b.y;

	if (((min(x1, x2) <= inputPos.x && inputPos.x <= max(x1, x2)) && (inputPos.y == y1)) ||
		((min(y1, y2) <= inputPos.y && inputPos.y <= max(y1, y2)) && (inputPos.x == x1))) {
		return true;
	}
	return false;
}