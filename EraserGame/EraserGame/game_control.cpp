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

bool IsInsideRmnArea(POINT& inputPos)
{
	for (int i = 0; i < remainingArea.size(); i++)
	{
		int x1 = i == 0 ? remainingArea.back().x : remainingArea[i - 1].x;
		int y1 = i == 0 ? remainingArea.back().y : remainingArea[i - 1].y;
		int x2 = remainingArea[i].x;
		int y2 = remainingArea[i].y;

		if (((min(x1, x2) <= inputPos.x && inputPos.x <= max(x1, x2)) && (inputPos.y == y1)) ||
			((min(y1, y2) <= inputPos.y && inputPos.y <= max(y1, y2)) && (inputPos.x == x1))) {
			return true;
		}
	}
	return false;
}

void FillOccupiedArea(vector<POINT>& path)
{
	POINT start = path[0];
	POINT end = path.back();
	vector<POINT> dividingLine;
	
	for (int i = 2; i < path.size(); i++)
	{
		if ((path[i].y != path[i - 2].y) && (path[i].x != path[i - 2].x))
			dividingLine.push_back(path[i - 1]);
	}
	POINT* area1, area2;

	//for (int i = start;)

	for (int i = 0; i < path.size(); i++)
	{
		visited[path[i].y][path[i].x] = false;
	}
}