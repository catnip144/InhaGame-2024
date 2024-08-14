#pragma once
#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159265

using namespace std;

class GeometricObject
{
private:
	double x, y;

public:
	GeometricObject();
	GeometricObject(double posX, double posY);

	double GetX() const { return x; }
	double SetX(double posX) { x = posX; }

	double GetY() const { return y; }
	double SetY(double posY) { y = posY; }

	virtual double Distance(double x1, double y1, double x2, double y2) const;
};

class Circle2D : public GeometricObject
{
private:
	double radius;

public:
	Circle2D();
	Circle2D(double x, double y, double radius);

	double GetRadius() { return radius; }
	double GetArea();
	double GetPerimeter();

	bool Contains(double posX, double posY) const;
	bool Contains(const Circle2D& circle);
	bool Overlaps(const Circle2D& circle);

	friend std::ostream& operator<<(std::ostream& os, const Circle2D& circle);
};

class Rectangle2D : public GeometricObject
{
private:
	double width, height;

	double GetLeft() const;
	double GetRight() const;
	double GetUp() const;
	double GetDown() const;

public:
	Rectangle2D();
	Rectangle2D(double posX, double posY, double rectWidth, double rectHeight);

	double GetWidth() { return width; }
	double SetWidth(double rectWidth) { width = rectWidth; }

	double GetHeight() { return height; }
	double SetHeight(double rectHeight) { height = rectHeight; }

	double GetArea();
	double GetPerimeter();

	bool Contains(double x, double y) const;
	bool Contains(const Rectangle2D& r);
	bool Overlaps(const Rectangle2D& r);

	friend std::ostream& operator<<(std::ostream& os, const Rectangle2D& r);
};

class MyPoint : public GeometricObject
{
public:
	MyPoint();
	MyPoint(double posX, double posY);

	virtual double Distance(const MyPoint& a);

	friend bool Contains(const MyPoint& point, const Circle2D& circle);
	friend bool Contains(const MyPoint& point, const Rectangle2D& rect);

	friend std::ostream& operator<<(std::ostream& os, const MyPoint& point);
};

