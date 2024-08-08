#pragma once
#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Circle2D
{
private:
	double x, y;
	double radius;
	double GetDistance(double x1, double y1, double x2, double y2);

public:
	Circle2D();
	Circle2D(double x, double y, double radius);

	double GetX() { return x; }
	double GetY() { return y; }
	double GetRadius() { return radius; }
	double GetArea();
	double GetPerimeter();

	bool Contains(double posX, double posY);
	bool Contains(const Circle2D& circle);
	bool Overlaps(const Circle2D& circle);

	friend std::ostream& operator<<(std::ostream& os, const Circle2D& circle);
};