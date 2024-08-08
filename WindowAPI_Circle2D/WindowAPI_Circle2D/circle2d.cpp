#include "circle2d.h"

double Circle2D::GetDistance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Circle2D::Circle2D()
{
	x = 0;
	y = 0;
	radius = 1;
}

Circle2D::Circle2D(double x, double y, double radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
}

double Circle2D::GetArea()
{
	return radius * radius * PI;
}

double Circle2D::GetPerimeter()
{
	return radius * 2 * PI;
}

bool Circle2D::Contains(double posX, double posY)
{
	return GetDistance(x, y, posX, posY) <= radius;
}

bool Circle2D::Contains(const Circle2D& circle)
{
	return (radius - GetDistance(x, y, circle.x, circle.y)) >= circle.radius;
}

bool Circle2D::Overlaps(const Circle2D& circle)
{
	return GetDistance(x, y, circle.x, circle.y) <= (radius + circle.radius);
}

std::ostream& operator<<(std::ostream& os, const Circle2D& circle)
{
	os << "(" << circle.x << ',' << circle.y << ") ¹ÝÁö¸§: " << circle.radius << endl;
	return os;
}
