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

class Block
{
private:
	RECT pos;
	int hp = 3;
	bool hasTakenDamage = false;
	// type

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
	double moveSpeed = BALL_SPEED;
	double radius = BALL_SIZE;
	double dirX = DIR_X;
	double dirY = DIR_Y;
	bool isDead = false;

	bool Contains(int posX, int posY);

public:
	Ball(int posX, int posY);
	void Draw(HDC& hdc);
	void Move();
	void CheckWall(RECT& rectView);
	bool Collision(RECT& rect);
	bool IsDead() { return isDead; }
};

class Paddle
{
private:
	RECT pos;
	int width;
	int height;

public:
	void Init(RECT& rectView);
	void Draw(HDC& hdc, HBRUSH& hBrush);
	void Move(WPARAM& wParam, RECT& rectView);
	RECT& GetPos() { return pos; }
};