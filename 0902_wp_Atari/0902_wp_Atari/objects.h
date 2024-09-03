#pragma once
#include "framework.h"

#define BLOCK_ROW 3
#define BLOCK_COL 10
#define OFFSET_X 10
#define OFFSET_Y 8

#define BALL_SIZE 10
#define BALL_SPEED 5
#define PI 3.141592

#define DIR_X cos((45 * PI / 180.0));
#define DIR_Y -sin((45 * PI / 180.0));

class Block
{
protected:
	int hp = 3;
	RECT pos;
	// type 

public:
	Block(RECT position);
	void Draw(HDC& hdc);
	void TakeDamage();
};

class Ball
{
private:
	int x, y;
	double moveSpeed = BALL_SPEED;
	double radius = BALL_SIZE;
	double dirX = DIR_X;
	double dirY = DIR_Y;

public:
	Ball(int posX, int posY);
	void Draw(HDC& hdc);
	void Move();
	void CheckWall(RECT& rectView);
};

class Paddle
{
private:

public:

};