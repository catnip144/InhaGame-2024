#include "game_control.h"

vector<vector<bool>> occupied;
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
	for (int i = 1; i < remainingArea.size(); i++)
	{
		int x1 = remainingArea[i - 1].x;
		int y1 = remainingArea[i - 1].y;
		int x2 = remainingArea[i].x;
		int y2 = remainingArea[i].y;

		if (x1 > x2) swap(x1, x2);

		//if (inputPos.x >= x1 && inputPos.x <= x2) || (inputPos.y >= y1 && inputPos.y <= y2)
	}
}

void FillOccupiedArea(vector<POINT>& path)
{
	
}
