#pragma once
#include "framework.h"

#define BLOCK_ROW 3
#define BLOCK_COL 10
#define OFFSET_X 10
#define OFFSET_Y 8

#define BALL_SIZE 10
#define BALL_SPEED 10
#define PI 3.141592

#define DIR_X cos((45 * PI / 180.0));
#define DIR_Y -sin((45 * PI / 180.0));

#define PADDLE_START_Y 9
#define PADDLE_WIDTH 90
#define PADDLE_HEIGHT 10
#define PADDLE_SPEED 40
#define PADDLE_STRETCH 15

class Block
{
private:
	RECT pos;
	int hp = 3;
	int rewardScore = 100;
	bool hasTakenDamage = false;

public:
	Block(RECT position);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	void TakeDamage(std::vector<Block*>& blocks, int index);
	RECT& GetPos() { return pos; }
};

class Ball
{
private:
	int x, y;
	int moveSpeed = BALL_SPEED;
	double radius = BALL_SIZE;
	double dirX = DIR_X;
	double dirY = DIR_Y;
	bool isDead = false;

	bool Contains(int posX, int posY);

public:
	Ball(int posX, int posY);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	void Move();
	void CheckWall(RECT& rectView);
	void SetMoveSpeed(int speed);
	void SetDirection(double dx, double dy);
	void SetPosition(double posX, double posY);
	int GetX() { return x; }
	int GetY() { return y; }
	bool Collision(RECT& rect);
	bool IsDead() { return isDead; }
};

class Paddle
{
private:
	RECT pos;
	int width = PADDLE_WIDTH;
	int height = PADDLE_HEIGHT;
	bool isSticky = false;
	std::vector<Ball*> stuckBalls;

public:
	void Init(RECT& rectView);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	void Move(WPARAM& wParam, RECT& rectView);
	void AdjustPosition(RECT& rectView);
	void Stretch();
	void SetIsSticky(bool state);
	void CollectBalls(Ball* ball);
	void MoveStuckBalls();
	void ReleaseStuckBalls();
	bool IsSticky() { return isSticky; }
	RECT& GetPos() { return pos; }
};

enum ItemType
{
	ITEM_MULTIPLY,
	ITEM_STICKY,
	ITEM_STRETCH
};

class Item
{
protected:
	ItemType type;

public:
	void CheckCollision();
	void Destroy();
	virtual void Draw();
	virtual void ItemEffect();
};

class MultiplierItem : public Item
{
public:
	MultiplierItem() { type = ITEM_MULTIPLY; }
	void Draw() override;
	void ItemEffect() override;
};

class StickyItem : public Item
{
public:
	StickyItem() { type = ITEM_STICKY; }
	void Draw() override;
	void ItemEffect() override;
};

class StretchItem : public Item
{
public:
	StretchItem() { type = ITEM_STRETCH; }
	void Draw() override;
	void ItemEffect() override;
};