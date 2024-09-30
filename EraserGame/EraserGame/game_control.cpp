#include "game_control.h"

vector<POINT> borders;
vector<vector<bool>> visited;
vector<POINT> remainingArea;

void CreateOccupiedGrid()
{
	int playerRadius = player.GetRadius();

	gameBorders = { playerRadius, playerRadius, rectView.right - playerRadius, rectView.bottom - playerRadius };

	remainingArea.push_back({ gameBorders.left, gameBorders.top });
	remainingArea.push_back({ gameBorders.left, gameBorders.bottom });
	remainingArea.push_back({ gameBorders.right, gameBorders.bottom });
	remainingArea.push_back({ gameBorders.right, gameBorders.top });

	borders.push_back({ gameBorders.left, gameBorders.top });
	borders.push_back({ gameBorders.left, gameBorders.bottom });
	borders.push_back({ gameBorders.right, gameBorders.bottom });
	borders.push_back({ gameBorders.right, gameBorders.top });
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

bool IsGameBorders(POINT& inputPos)
{
	for (int i = 0; i < borders.size(); i++)
	{
		int j = (i == 0) ? borders.size() - 1 : i - 1;
		if (IsBetweenTwoPoints(inputPos, borders[j], borders[i]))
			return true;
	}
	return false;
}

pair<int, int> IsRmnBorders(POINT& inputPos)
{
	for (int i = 0; i < remainingArea.size(); i++)
	{
		int j = (i == 0) ? remainingArea.size() - 1 : i - 1;
		if (IsBetweenTwoPoints(inputPos, remainingArea[j], remainingArea[i]))
			return { min(i, j), max(i, j) };
	}
	return { -1, -1 };
}

bool IsInsideOccupied(POINT& inputPos)
{
	POINT leftEnd = { gameBorders.left, inputPos.y };
	POINT rightEnd = { gameBorders.right, inputPos.y };

	for (const auto& polygon : uncovered)
	{
		int count = 0;
		for (const auto& point : polygon)
		{
			if (IsBetweenTwoPoints(point, leftEnd, rightEnd))
				++count;
		}
		if (count % 2 != 0)
			return true;
	}
	return false;
}

void FillOccupiedArea(vector<POINT>& path, pair<int, int> endContextIdx)
{
	pair<int, int> startContextIdx = IsRmnBorders(path[0]);
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
	int move = endContextIdx.first - endContextIdx.second;
	if (abs(move) > 1)
		move /= -abs(move);

	while (canSearchLeft)
	{
		area1.push_back(remainingArea[idx]);
		idx += move;

		if (idx == -1)
			idx = remainingArea.size() - 1;
		else if (idx == remainingArea.size())
			idx = 0;

		if (idx == startContextIdx.first || idx == startContextIdx.second)
		{
			area1.push_back(remainingArea[idx]);
			break;
		}
	}
	idx = endContextIdx.second;
	move = endContextIdx.second - endContextIdx.first;
	if (abs(move) > 1)
		move /= -abs(move);

	while (canSearchRight)
	{
		area2.push_back(remainingArea[idx]);
		idx += move;

		if (idx == -1)
			idx = remainingArea.size() - 1;
		else if (idx == remainingArea.size())
			idx = 0;

		if (idx == startContextIdx.first || idx == startContextIdx.second)
		{
			area2.push_back(remainingArea[idx]);
			break;
		}
	}
	SetFillArea(area1);
	remainingArea = area2;

	for (int i = 0; i < path.size(); i++)
		visited[path[i].y][path[i].x] = false;
}

void SetFillArea(vector<POINT> area1)
{
	uncovered.push_back(area1);
}

bool IsBetweenTwoPoints(POINT inputPos, POINT a, POINT b)
{
	int x1 = a.x, y1 = a.y;
	int x2 = b.x, y2 = b.y;

	if ((min(x1, x2) <= inputPos.x && inputPos.x <= max(x1, x2)) &&
		(min(y1, y2) <= inputPos.y && inputPos.y <= max(y1, y2))) {
		return true;
	}
	return false;
}