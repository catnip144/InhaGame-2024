#pragma once
#include "framework.h"

#define PI 3.141592
#define MIN_RADIUS 10
#define MAX_RADIUS 60
#define MIN_SPEED 5
#define MAX_SPEED 6
#define ROTATION_AMOUNT 3
#define MAX_OBJECT_TYPE 3
#define MIN_OBJECT_SIZE 5

using std::vector;
using std::pair;
using std::swap;

enum CObjectType
{
	OBJECT_CIRCLE,
	OBJECT_RECT,
	OBJECT_STAR
};

class CObject
{
protected:
	double x, y;
	CObjectType type;

	double moveSpeed;
	double radius;
	double theta;
	double dirX;
	double dirY;
	bool hasCollided;

	double Distance(double x1, double y1, double x2, double y2);

public:
	CObject(double posX, double posY, CObjectType objectType);

	void AdjustPosition(RECT rectView);
	void Move();
	void MoveBackwards();
	void Rotate();
	void SetHasCollided(bool state);
	void CollisionEvent(int modeNum, int i, int j, std::vector<CObject*>& objectList);
	pair<double, double> GetDirectionFromAngle(double angle);

	bool Collision(const CObject& cObject);
	bool HasCollided() { return hasCollided; }

	virtual void Draw(HDC hdc);
};

class Circle2D : public CObject
{
public:
	Circle2D(double x, double y, CObjectType objectType);
	void Draw(HDC hdc);
};

class Rectangle2D : public CObject
{
public:
	Rectangle2D(double x, double y, CObjectType objectType);
	void Draw(HDC hdc);
};

class Star2D : public CObject
{
public:
	Star2D(double x, double y, CObjectType objectType);
	void Draw(HDC hdc);
};