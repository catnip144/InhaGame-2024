#pragma once
#include "framework.h"
#include "game_control.h"

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
	int width;
	int height;
	bool isSticky = false;
	vector<Ball*> stuckBalls;

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
	RECT pos;
	int curFrame = 0;

public:
	Item(int x, int y, ItemType itemType);

	RECT GetPos() { return pos; }
	ItemType GetType() { return type; }
	int GetCurrentFrame() { return curFrame; }
	void UpdateFrame();
	bool Move(RECT& rectView);
	bool Collision(RECT& paddle);
	virtual void ItemEffect(vector<Ball*>& balls, Paddle& paddle);
};

class MultiplierItem : public Item
{
public:
	MultiplierItem(int x, int y);
	virtual void ItemEffect(vector<Ball*>& balls, Paddle& paddle) override;
};

class StickyItem : public Item
{
public:
	StickyItem(int x, int y);
	virtual void ItemEffect(vector<Ball*>& balls, Paddle& paddle) override;
};

class StretchItem : public Item
{
public:
	StretchItem(int x, int y);
	virtual void ItemEffect(vector<Ball*>& balls, Paddle& paddle) override;
};

class Block
{
private:
	RECT pos;
	int hp = MAX_BLOCK_HP;
	int rewardScore = 100;
	bool hasTakenDamage = false;

	void DropItem(vector<Item*>& items);

public:
	Block(RECT position);

	void SetHp(int amount);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	void TakeDamage(vector<Block*>& blocks, vector<Item*>& items, int index);
	RECT& GetPos() { return pos; }
};


void ShootBall(RECT& paddlePos, vector<Ball*>& balls);