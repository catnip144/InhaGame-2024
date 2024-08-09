#include "mypoint.h"

MyPoint::MyPoint()
{
	x = 0;
	y = 0;
}

MyPoint::MyPoint(double posX, double posY)
{
	x = posX;
	y = posY;
}

double MyPoint::Distance(const MyPoint& a)
{
	return sqrt(pow((x - a.x), 2) + pow((y - a.y), 2));
}

bool Contains(const MyPoint& point, const Circle2D& circle)
{
	return circle.Contains(point.x, point.y);
}

bool Contains(const MyPoint& point, const Rectangle2D& rect)
{
	return rect.Contains(point.x, point.y);
}

std::ostream& operator<<(std::ostream& os, const MyPoint& point)
{
	os << "(" << point.x << ", " << point.y << "), ";
	return os;
}