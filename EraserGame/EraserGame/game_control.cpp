#include "game_control.h"

HWND	g_hWnd = NULL;
HDC		g_hdc, g_backMemDC;

Player	player;
POINT	playerStartPos;

vector<vector<pair<bool, int>>> visited;
vector<MaskPolygon*> masks;

void CreateVisitedGrid()
{
	visited = vector<vector<pair<bool, int>>>
		(screenHeight, vector<pair<bool, int>>(screenWidth, {false, 0}));
}

void DrawMasks(HDC& hdc)
{
	//for (MaskPolygon* mask : masks)
	//	mask->Draw(hdc);
}

void Player::Init()
{
	radius = PLAYER_SIZE;
	speed = PLAYER_SPEED;

	playerStartPos = { radius, screenHeight - radius };
	pos = playerStartPos;
	path.push_back(pos);

	visited[pos.y][pos.x] = { true, pathIndex++ };
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

	MoveToEx(hdc, playerStartPos.x, playerStartPos.y, NULL);

	for (POINT& point : path)
	{
		LineTo(hdc, point.x, point.y);
		MoveToEx(hdc, point.x, point.y, NULL);
	}
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

void Player::Move(WPARAM& wParam)
{
	int moveX = 0, moveY = 0;

	switch (wParam)
	{
	case 'A':	moveX = -speed; break;
	case 'D':	moveX = speed;  break;
	case 'W':	moveY = -speed; break;
	case 'S':	moveY = speed;  break;
	default:		return;
	}
	pos.x += moveX;
	pos.y += moveY;

	AdjustPosition();

	if (!visited[pos.y][pos.x].first)
	{
		visited[pos.y][pos.x] = { true, pathIndex++ };
		path.push_back(pos);
	}
	else
	{
		
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
