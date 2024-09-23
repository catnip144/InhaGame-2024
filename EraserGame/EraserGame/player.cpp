#include "game_control.h"

Player	player;
POINT	playerStartPos;
POINT	entryPos;

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

void Player::SetIsDrawing(bool state)
{
	isDrawing = state;
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

	if (IsPressing())
	{
		pos = prevPos;
	}
	else if (IsPressing())
	{
		if (path.empty())
		{
			entryPos = prevPos;
			path.push_back(prevPos);
		}
		path.push_back(pos);
	}
	else if (IsPressing() && !path.empty())
	{
		path.push_back(pos);
		FillOccupiedArea(path);
		path.clear();
	}
	else if (!IsPressing())
	{
		pos = prevPos;
	}
}

void Player::Rollback()
{
	if (path.size() > 1)
	{
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
	if (pos.x < rectView.left + radius)
		pos.x = rectView.left + radius;

	else if (pos.x > rectView.right - radius)
		pos.x = rectView.right - radius;

	if (pos.y < rectView.top + radius)
		pos.y = rectView.top + radius;

	else if (pos.y > rectView.bottom - radius)
		pos.y = rectView.bottom - radius;
}