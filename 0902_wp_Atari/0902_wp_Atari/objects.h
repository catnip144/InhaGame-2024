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

#define ITEM_MAX_TYPE 4

enum ItemType
{
	ITEM_NONE,
	ITEM_MULTIPLY,
	ITEM_STICKY,
	ITEM_STRETCH
};

class Item
{
protected:
	ItemType type = ITEM_NONE;
	POINT pos;

public:
	Item(int x, int y);
	//void CheckCollision();
	//void Destroy();
	virtual void Draw(HDC& hdc);
	//virtual void ItemEffect();
};

class MultiplierItem : public Item
{
public:
	MultiplierItem(int x, int y);
	void Draw(HDC& hdc) override;
	//void ItemEffect() override;
};

class StickyItem : public Item
{
public:
	StickyItem(int x, int y);
	void Draw(HDC& hdc) override;
	//void ItemEffect() override;
};

class StretchItem : public Item
{
public:
	StretchItem(int x, int y);
	void Draw(HDC& hdc) override;
	//void ItemEffect() override;
};

class Block
{
private:
	RECT pos;
	int hp = 3;
	int rewardScore = 100;
	bool hasTakenDamage = false;

	void DropItem(std::vector<Item*>& items);

public:
	Block(RECT position);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	void TakeDamage(std::vector<Block*>& blocks, std::vector<Item*>& items, int index);
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
	bool isStuck = false;

	bool Contains(int posX, int posY);

public:
	Ball(int posX, int posY);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	void Move();
	void CheckWall(RECT& rectView);
	void SetMoveSpeed(int speed);
	void SetDirection(double dx, double dy);
	void SetPosition(double posX, double posY);
	void SetIsStuck(bool state);
	int GetX() { return x; }
	int GetY() { return y; }
	bool Collision(RECT& rect);
	bool IsDead() { return isDead; }
	bool IsStuck() { return isStuck; }
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
	void Move(WPARAM& wParam, RECT rectView);
	void AdjustPosition(RECT& rectView);
	void Stretch();
	void SetIsSticky(bool state);
	void CollectBalls(Ball* ball);
	void MoveStuckBalls(int moveAmount);
	void ReleaseStuckBalls();
	bool IsSticky() { return isSticky; }
	RECT& GetPos() { return pos; }
};