#include "game_control.h"

HWND	g_hWnd = NULL;
HDC		g_hdc, g_backMemDC;

Player	player;
POINT	playerStartPos;
POINT	entryPos;

vector<vector<bool>> visited;
vector<MaskPolygon*> masks;

void CreateVisitedGrid()
{
	visited = vector<vector<bool>>
		(screenHeight, vector<bool>(screenWidth, false));

	int playerRadius = player.GetRadius();
	int rightX = screenWidth - playerRadius;

	for (int i = playerStartPos.x; i <= rightX; i++)
	{
		visited[playerRadius][i] = true;
		visited[playerStartPos.y][i] = true;
	}
	for (int i = playerRadius + 1; i <= playerStartPos.y - 1; i++)
	{
		visited[i][playerRadius] = true;
		visited[i][rightX] = true;
	}
	visited[playerStartPos.y][playerStartPos.x] = true;
}

void DrawMasks(HDC& hdc)
{
	for (MaskPolygon* mask : masks)
		mask->Draw(hdc);
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

void Player::Init()
{
	radius = PLAYER_SIZE;
	speed = PLAYER_SPEED;

	playerStartPos = { radius, screenHeight - radius };
	pos = playerStartPos;
}

void Player::Draw(HDC& hdc)
{
	hPen = CreatePen(PS_SOLID, 3, RGB(92, 150, 255));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	hBrush = CreateSolidBrush(RGB(183, 253, 255));
	SelectObject(hdc, hBrush);

	Ellipse(hdc, pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);

	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
	DeleteObject(hBrush);
}

void Player::DrawLine(HDC& hdc)
{
	hPen = CreatePen(PS_SOLID, 2, RGB(92, 150, 255));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	for (int i = 0; i < path.size(); i++)
	{
		if (i == 0) MoveToEx(hdc, path[0].x, path[0].y, NULL);
		LineTo(hdc, path[i].x, path[i].y);
	}
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

bool Player::IsDrawing()
{
	return (GetAsyncKeyState(VK_CONTROL) & 0x8000);
}

void Player::Move(int inputType)
{
	POINT prevPos = pos;
	int moveX = 0, moveY = 0;

	switch (inputType)
	{
	case 'W':	moveY = -speed; break;
	case 'A':	moveX = -speed; break;
	case 'S':	moveY = speed;  break;
	case 'D':	moveX = speed;  break;
	default:	return;
	}
	pos.x += moveX;
	pos.y += moveY;

	AdjustPosition();

	if (IsDrawing() && !visited[pos.y][pos.x])
	{
		if (path.empty())
			entryPos = prevPos;

		visited[pos.y][pos.x] = true;
		path.push_back(pos);
	}
	else if (!IsDrawing() && !visited[pos.y][pos.x])
	{
		pos = prevPos;
		
		// if new area is connected to borders
			// expand area

		/// if not
		//pos = prevPos;
	}
	//else if (IsDrawing)
	//{
	//	MaskPolygon* newMask = new MaskPolygon();
	//	newMask->Init(path, visited[pos.y][pos.x].second, pathIndex);
	//	masks.push_back(newMask);
	//	IsDrawing = false;
	//}
}

void Player::Rollback()
{
	if (path.size() >= 1)
	{
		visited[path.back().y][path.back().x] = false;
		path.pop_back();
		pos = path.empty() ? entryPos : path.back();
	}
}

void Player::AdjustPosition()
{
	if (pos.x < rectView.left + radius)
		pos.x = rectView.left + radius;

	else if (pos.x > rectView.right - radius)
		pos.x = rectView.right - radius;

	if (pos.y < rectView.top + radius)
		pos.y = rectView.top + radius;

	else if (pos.y > rectView.bottom - radius)
		pos.y = rectView.bottom - radius;
}

void DrawMap(HDC& hdc)
{
	hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(
		hdc,
		player.GetRadius(),
		player.GetRadius(),
		rectView.right - player.GetRadius(),
		rectView.bottom - player.GetRadius()
	);
	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}
 