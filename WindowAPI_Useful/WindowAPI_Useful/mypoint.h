#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "circle2d.h"
#include "rectangle2d.h"

using namespace std;

class MyPoint
{
private:
	double x, y;

public:
	MyPoint();
	MyPoint(double posX, double posY);

	double GetX() const { return x; }
	void SetX(double posX) { x = posX; }

	double GetY() const { return y; }
	void SetY(double posY) { y = posY; }

	double Distance(const MyPoint& a);

	friend bool Contains(const MyPoint& point, const Circle2D& circle);
	friend bool Contains(const MyPoint& point, const Rectangle2D& rect);
	friend std::ostream& operator<<(std::ostream& os, const MyPoint& point);
};