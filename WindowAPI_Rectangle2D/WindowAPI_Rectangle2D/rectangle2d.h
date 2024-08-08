#pragma once
#include <iostream>
#include <string>

using namespace std;

class Rectangle2D
{
private:
	double x, y;
	double width, height;

	double GetLeft() const;
	double GetRight() const;
	double GetUp() const;
	double GetDown() const;

public:
	Rectangle2D();
	Rectangle2D(double posX, double posY, double rectWidth, double rectHeight);

	double GetX() { return x; }
	double SetX(double posX) { x = posX; }

	double GetY() { return y; }
	double SetY(double posY) { y = posY; }

	double GetWidth() { return width; }
	double SetWidth(double rectWidth) { width = rectWidth; }

	double GetHeight() { return height; }
	double SetHeight(double rectHeight) { height = rectHeight; }

	double GetArea();
	double GetPerimeter();

	bool Contains(double x, double y);
	bool Contains(const Rectangle2D& r);
	bool Overlaps(const Rectangle2D& r);

	friend std::ostream& operator<<(std::ostream& os, const Rectangle2D& r);
};