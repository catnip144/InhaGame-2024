#include "objects.h"

pair<double, double> GetDirectionFromAngle(double angle);

Block::Block(RECT position)
{
	pos = position;
}

void Block::Draw(HDC& hdc)
{
	Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);
}

void Block::TakeDamage()
{
	hp -= 1;
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
		dirX *= -1;
	}
	if (x < rectView.left + radius)
	{
		x = rectView.left + radius;
		dirX *= -1;
	}
	if (y < rectView.top + radius)
	{
		dirY *= -1;
		y = rectView.top + radius;
	}
	if (y > rectView.bottom - radius)
	{
		dirY *= -1;
		y = rectView.bottom - radius;
	}
}
