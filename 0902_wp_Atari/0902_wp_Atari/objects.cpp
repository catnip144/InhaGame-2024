#include "objects.h"

Block::Block(RECT position)
{
	pos = position;
}

void Block::Draw(HDC& hdc, HBRUSH& hBrush)
{
	switch (hp)
	{
	case 1:
		hBrush = CreateSolidBrush(RGB(195, 75, 75));
		break;
	case 2:
		hBrush = CreateSolidBrush(RGB(234, 160, 57));
		break;
	case 3:
		hBrush = CreateSolidBrush(RGB(62, 180, 137));
		break;
	default:
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		break;
	}
	SelectObject(hdc, hBrush);

	if (hasTakenDamage)
	{
		hasTakenDamage = false;

		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);

		Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);
		DeleteObject(hBrush);
		return;
	}
	Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);
	DeleteObject(hBrush);
}

void Block::TakeDamage(vector<Block*>& blocks, int index)
{
	hp -= 1;
	hasTakenDamage = true;

	if (hp == 0)
		blocks.erase(blocks.begin() + index);
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
		isDead = true;
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

void Paddle::Init(RECT& rectView)
{
	int posX = (rectView.right - rectView.left) / 2;
	int posY = (rectView.bottom - rectView.top) * PADDLE_START_Y / 10;

	width = PADDLE_WIDTH;
	height = PADDLE_HEIGHT;

	pos = {
		posX - width / 2,
		posY - height / 2,
		posX + width / 2,
		posY + height / 2
	};
}

void Paddle::Draw(HDC& hdc, HBRUSH& hBrush)
{
	hBrush = CreateSolidBrush(RGB(170, 200, 200));
	SelectObject(hdc, hBrush);
	Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);
	DeleteObject(hBrush);
}

void Paddle::Move(WPARAM& wParam, RECT& rectView)
{
	int moveAmount = PADDLE_SPEED;

	switch (wParam)
	{
	case VK_LEFT:
		if (pos.left - PADDLE_SPEED <= rectView.left)
			moveAmount = (pos.left - rectView.left);
		moveAmount = -moveAmount;
		break;

	case VK_RIGHT:
		if (pos.right + PADDLE_SPEED >= rectView.right)
			moveAmount = rectView.right - pos.right;
		break;

	default:
		return;
	}
	pos.left += moveAmount;
	pos.right += moveAmount;
}
