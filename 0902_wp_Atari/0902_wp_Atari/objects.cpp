#pragma once
#include "objects.h"

Block::Block(RECT position)
{
	pos = position;
}

void Block::SetHp(int amount)
{
	hp = amount;
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
		break;
	}
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	if (hasTakenDamage)
	{
		hasTakenDamage = false;

		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);

		Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);
		SelectObject(hdc, oldBrush);
		DeleteObject(hBrush);
		return;
	}
	Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom);
	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}
void Block::TakeDamage(std::vector<Block*>& blocks, std::vector<Item*>& items, int index)
{
	hp -= 1;
	hasTakenDamage = true;

	if (hp == 0)
	{
		EarnScore(rewardScore);
		DropItem(items);

		blocks.erase(blocks.begin() + index);
	}
}
void Block::DropItem(vector<Item*>& items)
{
	int posX = pos.left + (pos.right - pos.left) / 2;
	int posY = pos.top + (pos.bottom - pos.top) / 2;
	int chance = rand() % 100 + 1;

	if (chance <= 30)
		items.push_back(new MultiplierItem(posX, posY));

	else if (chance <= 50)
		items.push_back(new StickyItem(posX, posY));

	else if (chance <= 80)
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
	isSticky = false;
	width = PADDLE_WIDTH;
	height = PADDLE_HEIGHT;

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
	if (isSticky)
		hBrush = CreateSolidBrush(RGB(219, 252, 3));
	else
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

Item::Item(int x, int y, ItemType itemType)
{
	int bx = 0, by = 0;
	type = itemType;

	switch (itemType)
	{
	case ITEM_MULTIPLY:
		bx = bitMultiplierItem.bmWidth;
		by = bitMultiplierItem.bmHeight;
		break;

	case ITEM_STICKY:
		bx = bitStickyItem.bmWidth;
		by = bitStickyItem.bmHeight;
		break;

	case ITEM_STRETCH:
		bx = bitStretchItem.bmWidth;
		by = bitStretchItem.bmHeight;
		break;

	default:
		return;
	}
	int itemWidth  = bx / ITEM_SPRITE_COL * ITEM_IMAGE_SIZE;
	int itemHeight = by * ITEM_IMAGE_SIZE;

	pos.left   = x - (itemWidth / 2);
	pos.top    = y - (itemHeight / 2);
	pos.right  = x + (itemWidth / 2);
	pos.bottom = y + (itemHeight / 2);
}

void Item::UpdateFrame()
{
	curFrame = (curFrame + 1) % ITEM_SPRITE_COL;
}

bool Item::Move(RECT& rectView)
{
	pos.top += ITEM_FALL_SPEED;
	pos.bottom += ITEM_FALL_SPEED;

	if (pos.top > rectView.bottom)
		return false;
	return true;
}

bool Item::Collision(RECT& paddle)
{
	if (pos.right < paddle.left)
		return false;

	if (pos.left > paddle.right)
		return false;

	if (pos.top > paddle.bottom)
		return false;

	if (pos.bottom < paddle.top)
		return false;
	return true;
}

void Item::ItemEffect(vector<Ball*>& balls, Paddle& paddle) {}

MultiplierItem::MultiplierItem(int x, int y) : Item(x, y, ITEM_MULTIPLY) {}

void MultiplierItem::ItemEffect(vector<Ball*>& balls, Paddle& paddle)
{
	ShootBall(paddle.GetPos(), balls);
}

StickyItem::StickyItem(int x, int y) : Item(x, y, ITEM_STICKY) {}

void StickyItem::ItemEffect(vector<Ball*>& balls, Paddle& paddle)
{
	paddle.SetIsSticky(true);
}

StretchItem::StretchItem(int x, int y) : Item(x, y, ITEM_STRETCH) {}

void StretchItem::ItemEffect(vector<Ball*>& balls, Paddle& paddle)
{
	paddle.Stretch();
}
