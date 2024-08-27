#pragma once
#include <cmath>;
#include "framework.h"

class CObject
{
	public:
		double x, y;
		double radius;
		double moveSpeed;
		double dirX;
		double dirY;
		double theta;

		CObject(double posX, double posY);

	//	�̵� ����, Ÿ��(��, ��, �簢��)

		//virtual void Update();
		//virtual void Draw();
		//virtual bool Collision();
};

class Circle2D : public CObject
{
public:
	Circle2D(double x, double y);
	void Draw(HDC hdc);
};

class Rectangle2D : public CObject
{
public:
	Rectangle2D(double posX, double posY);
	void Draw(HDC hdc);
};