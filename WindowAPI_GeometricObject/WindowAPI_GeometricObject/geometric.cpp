#include "geometric.h"

GeometricObject::GeometricObject()
{
	x = 0;
	y = 0;
}

GeometricObject::GeometricObject(double posX, double posY)
{
	x = posX;
	y = posY;
}

double GeometricObject::Distance(double x1, double y1, double x2, double y2) const
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

//////////////////////////////////////////  Circle2D  /////////////////////////////////////////////////

Circle2D::Circle2D() : GeometricObject()
{
	radius = 1;
}

Circle2D::Circle2D(double x, double y, double radius) : GeometricObject(x, y)
{
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

bool Circle2D::Contains(double posX, double posY) const
{
	return GeometricObject::Distance(GetX(), GetY(), posX, posY) <= radius;
}

bool Circle2D::Contains(const Circle2D& circle)
{
	return (radius - GeometricObject::Distance(GetX(), GetY(), circle.GetX(), circle.GetY())) >= circle.radius;
}

bool Circle2D::Overlaps(const Circle2D& circle)
{
	return GeometricObject::Distance(GetX(), GetY(), circle.GetX(), circle.GetY()) <= (radius + circle.radius);
}

std::ostream& operator<<(std::ostream& os, const Circle2D& circle)
{
	os << "(" << circle.GetX() << ',' << circle.GetY() << ") 반지름: " << circle.radius << endl;
	return os;
}

//////////////////////////////////////////  Rectangle2D  //////////////////////////////////////////////

Rectangle2D::Rectangle2D() : GeometricObject()
{
	width = height = 1;
}

Rectangle2D::Rectangle2D(double posX, double posY, double rectWidth, double rectHeight) : GeometricObject(posX, posY)
{
	width = rectWidth;
	height = rectHeight;
}

double Rectangle2D::GetLeft() const
{
	return (GetX() - width / 2.0);
}
double Rectangle2D::GetRight() const
{
	return (GetX() + width / 2.0);
}
double Rectangle2D::GetUp() const
{
	return (GetY() - width / 2.0);
}
double Rectangle2D::GetDown() const
{
	return (GetY() + width / 2.0);
}

double Rectangle2D::GetArea()
{
	return width * height;
}

double Rectangle2D::GetPerimeter()
{
	return width * 2 + height * 2;
}

bool Rectangle2D::Contains(double x, double y) const
{
	if (GetLeft() > x)
		return false;

	if (GetRight() < x)
		return false;

	if (GetUp() > y)
		return false;

	if (GetDown() < y)
		return false;

	return true;
}

bool Rectangle2D::Contains(const Rectangle2D& r)
{
	if (GetLeft() > r.GetLeft())
		return false;

	if (GetRight() < r.GetRight())
		return false;

	if (GetUp() > r.GetUp())
		return false;

	if (GetDown() < r.GetDown())
		return false;

	return true;
}

bool Rectangle2D::Overlaps(const Rectangle2D& r)
{
	if (GetRight() < r.GetLeft())
		return false;

	if (GetLeft() > r.GetRight())
		return false;

	if (GetUp() > r.GetDown())
		return false;

	if (GetDown() < r.GetUp())
		return false;

	return true;
}

std::ostream& operator<<(std::ostream& os, const Rectangle2D& r)
{
	os << "중심 : (" << r.GetX() << ", " << r.GetY() << "), "
	   << "width : " << r.width << ", "
	   << "height : " << r.height << endl;
	return os;
}

//////////////////////////////////////////  MyPoint  /////////////////////////////////////////////////

MyPoint::MyPoint() : GeometricObject() {}

MyPoint::MyPoint(double posX, double posY) : GeometricObject(posX, posY) {}

double MyPoint::Distance(const MyPoint& a)
{
	return GeometricObject::Distance(GetX(), GetY(), a.GetX(), a.GetY());
}

bool Contains(const MyPoint& point, const Circle2D& circle)
{
	return circle.Contains(point.GetX(), point.GetY());
}

bool Contains(const MyPoint& point, const Rectangle2D& rect)
{
	return rect.Contains(point.GetX(), point.GetY());
}

std::ostream& operator<<(std::ostream& os, const MyPoint& point)
{
	os << "(" << point.GetX() << ", " << point.GetY() << "), ";
	return os;
}