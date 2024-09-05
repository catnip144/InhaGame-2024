#pragma once
#include "framework.h"

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
void Block::TakeDamage(std::vector<Block*>& blocks, std::vector<Item*>& items, int index)
{
	hp -= 1;
	hasTakenDamage = true;

	if (hp == 0)
	{
		EarnScore(rewardScore);
		blocks.erase(blocks.begin() + index);
		DropItem(items);
	}
}
void Block::DropItem(vector<Item*>& items)
{
	int posX = (pos.right - pos.left) / 2;
	int posY = (pos.bottom - pos.top) / 2;
	int chance = rand() % 100 + 1;

	if (chance <= 20)
		items.push_back(new MultiplierItem(posX, posY));

	else if (chance <= 40)
		items.push_back(new StickyItem(posX, posY));

	else if (chance <= 60)
		items.push_back(new StretchItem(posX, posY));
}

Ball::Ball(int posX, int posY)
{
	SetPosition(posX, posY);
}

void Ball::Draw(HDC& hdc, HBRUSH& hBrush)
{
	HPEN ballPen = CreatePen(PS_SOLID, 3, RGB(92, 150, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, ballPen);

	hBrush = CreateSolidBrush(RGB(183, 253, 255));
	SelectObject(hdc, hBrush);

	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

	SelectObject(hdc, oldPen);
	DeleteObject(ballPen);
	DeleteObject(hBrush);
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

void Ball::SetMoveSpeed(int speed)
{
	moveSpeed = speed;
}

void Ball::SetDirection(double dx, double dy)
{
	dirX = dx;
	dirY = dy;
}

void Ball::SetPosition(double posX, double posY)
{
	x = posX;
	y = posY;
}

void Ball::SetIsStuck(bool state)
{
	isStuck = state;
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

void Paddle::Move(WPARAM& wParam, RECT rectView)
{
	int moveAmount;
	RECT prevPos = pos;

	switch (wParam)
	{
	case VK_LEFT:
		moveAmount = -PADDLE_SPEED;
		break;

	case VK_RIGHT:
		moveAmount = PADDLE_SPEED;
		break;

	default:
		return;
	}
	pos.left += moveAmount;
	pos.right += moveAmount;

	AdjustPosition(rectView);
	MoveStuckBalls(pos.left - prevPos.left);
}

void Paddle::AdjustPosition(RECT& rectView)
{
	if (pos.left < rectView.left)
	{
		pos.left = rectView.left;
		pos.right = pos.left + width;
	}
	else if (pos.right > rectView.right)
	{
		pos.right = rectView.right;
		pos.left = pos.right - width;
	}
}

void Paddle::Stretch()
{
	width += PADDLE_STRETCH * 2;
	pos.left -= PADDLE_STRETCH;
	pos.right += PADDLE_STRETCH;
}

void Paddle::SetIsSticky(bool state)
{
	isSticky = state;
}

void Paddle::CollectBalls(Ball* ball)
{
	ball->SetIsStuck(true);
	ball->SetMoveSpeed(0);
	stuckBalls.push_back(ball);
}

void Paddle::MoveStuckBalls(int moveAmount)
{
	for (Ball* ball : stuckBalls)
		ball->SetPosition(ball->GetX() + moveAmount, ball->GetY());
}

void Paddle::ReleaseStuckBalls()
{
	for (int i = stuckBalls.size() - 1; i >= 0; i--)
	{
		stuckBalls[i]->SetMoveSpeed(BALL_SPEED);
		stuckBalls[i]->SetIsStuck(false);
		stuckBalls.pop_back();
	}
}

Item::Item(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void Item::Draw(HDC& hdc)
{
}

MultiplierItem::MultiplierItem(int x, int y) : Item(x, y)
{
	type = ITEM_MULTIPLY;
}

void MultiplierItem::Draw(HDC& hdc)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, hBrush);
	Ellipse(hdc, pos.x - 3, pos.y - 3, pos.x + 3, pos.y + 3);
	DeleteObject(hBrush);
}

StickyItem::StickyItem(int x, int y) : Item(x, y)
{
	type = ITEM_STICKY;
}

void StickyItem::Draw(HDC& hdc)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(hdc, hBrush);
	Ellipse(hdc, pos.x - 3, pos.y - 3, pos.x + 3, pos.y + 3);
	DeleteObject(hBrush);
}

StretchItem::StretchItem(int x, int y) : Item(x, y)
{
	type = ITEM_STRETCH;
}

void StretchItem::Draw(HDC& hdc)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, hBrush);
	Ellipse(hdc, pos.x - 3, pos.y - 3, pos.x + 3, pos.y + 3);
	DeleteObject(hBrush);
}
