#include "game_control.h"

Player	player;
POINT	playerStartPos;
POINT	entryPos;

void Player::Init()
{
	radius = PLAYER_SIZE;
	speed = PLAYER_SPEED;

	playerStartPos = { radius, rectView.bottom - radius };
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

bool Player::IsPressing()
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
	pair<int, int> contextIndex = IsRmnBorders(pos);
	bool isRmnBorders = (contextIndex.first != -1);

	if (IsPressing())
	{
		if (!isRmnBorders)
		{
			if (IsInsideOccupied(pos))
			{
				pos = prevPos;
				return;
			}
			else if (path.empty())
			{
				entryPos = prevPos;
				path.push_back(prevPos);
				visited[prevPos.y][prevPos.x] = true;
			}
			else if (visited[pos.y][pos.x])
			{
				pos = prevPos;
				return;
			}
			path.push_back(pos);
			visited[pos.y][pos.x] = true;
		}
		else if (!path.empty() && isRmnBorders)
		{
			path.push_back(pos);
			visited[pos.y][pos.x] = true;
			FillOccupiedArea(path, contextIndex);
			path.clear();
		}
	}
	else if (!isRmnBorders && !IsGameBorders(pos))
	{
		pos = prevPos;
	}
}

void Player::Rollback()
{
	if (path.size() > 1)
	{
		visited[path.back().y][path.back().x] = false;
		path.pop_back();
		pos = path.back();
	}
	else if (path.size() == 1)
	{
		pos = path.back();
		path.pop_back();
	}
}

void Player::AdjustPosition()
{
	if (pos.x < gameBorders.left)
		pos.x = gameBorders.left;

	else if (pos.x > gameBorders.right)
		pos.x = gameBorders.right;

	if (pos.y < gameBorders.top)
		pos.y = gameBorders.top;

	else if (pos.y > gameBorders.bottom)
		pos.y = gameBorders.bottom;
}