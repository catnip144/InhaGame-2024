#include "objects.h"

Block::Block(RECT position)
{
	pos = position;
}

void Block::Draw(HDC& hdc, HBRUSH& hBrush)
{
	if (hasTakenDamage)
	{
		hasTakenDamage = false;

		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);

		Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);

		hBrush = CreateSolidBrush(RGB(62, 180, 137));
		SelectObject(hdc, hBrush);
		return;
	}
	Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);
}

void Block::TakeDamage()
{
	hp -= 1;
	hasTakenDamage = true;
}

Ball::Ball(int posX, int posY)
{
	x = posX;
	y = posY;
}

void Ball::Draw(HDC& hdc)
{
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}

void Ball::Move()
{
	x += dirX * moveSpeed;
	y += dirY * moveSpeed;
}

void Ball::CheckWall(RECT& rectView)
{
	if (x > rectView.right - radius)
	{
		x = rectView.right - radius;
		dirX = -dirX;
	}
	else if (x < rectView.left + radius)
	{
		x = rectView.left + radius;
		dirX = -dirX;
	}
	else if (y < rectView.top + radius)
	{
		y = rectView.top + radius;
		dirY = -dirY;
	}
	else if (y > rectView.bottom - radius)
	{
		y = rectView.bottom - radius;
		dirY = -dirY;
	}
}

bool Ball::Collision(RECT& rect)
{
	if (x < rect.left - radius)
		return false;

	if (x > rect.right + radius)
		return false;

	if (y < rect.top - radius)
		return false;

	if (y > rect.bottom + radius)
		return false;

	if (((y + radius >= rect.top) && (y - radius <= rect.top)) && (x >= rect.left && x <= rect.right))
	{
		y = rect.top - radius;
		dirY = -dirY;
	}
	else if (((y - radius <= rect.bottom) && (y + radius >= rect.bottom)) && (x >= rect.left && x <= rect.right))
	{
		y = rect.bottom + radius;
		dirY = -dirY;
	}
	else if (((x + radius >= rect.left) && (x - radius <= rect.left)) && (y >= rect.top && y <= rect.bottom))
	{
		x = rect.left - radius;
		dirX = -dirX;
	}
	else if (((x - radius <= rect.right) && (x + radius >= rect.right)) && (y >= rect.top && y <= rect.bottom))
	{
		x = rect.right + radius;
		dirX = -dirX;
	}
	return true;
}

bool Ball::Contains(int posX, int posY)
{
	return pow((x - posX), 2) + pow((y - posY), 2) <= pow(radius, 2);
}
