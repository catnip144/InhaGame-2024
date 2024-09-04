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

void Block::TakeDamage(vector<Block*>& blocks, int index)
{
	hp -= 1;
	hasTakenDamage = true;

	if (hp == 0)
	{
		EarnScore(rewardScore);
		blocks.erase(blocks.begin() + index);
	}
}

Ball::Ball(int posX, int posY)
{
	SetPosition(posX, posY);
}

void Ball::Draw(HDC& hdc, HBRUSH& hBrush)
{
	hBrush = CreateSolidBrush(RGB(183, 253, 255));
	SelectObject(hdc, hBrush);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
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

void Paddle::Move(WPARAM& wParam, RECT& rectView)
{
	int moveAmount;

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
	ball->SetMoveSpeed(0);
	//ball->SetDirection(cos((90 * PI / 180.0)), -sin((90 * PI / 180.0)));
	stuckBalls.push_back(ball);
}

void Paddle::MoveStuckBalls()
{
	//for (Ball* ball : stuckBalls)
	//	ball->SetPosition(ball->GetX(), ball->GetY());
}

void Paddle::ReleaseStuckBalls()
{
	for (int i = stuckBalls.size() - 1; i >= 0; i--)
	{
		stuckBalls[i]->SetMoveSpeed(BALL_SPEED);
		stuckBalls.pop_back();
	}
}
