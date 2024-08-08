#include "rectangle2d.h";

Rectangle2D::Rectangle2D()
{
	x = y = 0;
	width = height = 1;
}

Rectangle2D::Rectangle2D(double posX, double posY, double rectWidth, double rectHeight)
{
	x = posX;
	y = posY;
	width = rectWidth;
	height = rectHeight;
}

double Rectangle2D::GetLeft() const
{
	return (x - width / 2.0);
}
double Rectangle2D::GetRight() const
{
	return (x + width / 2.0);
}
double Rectangle2D::GetUp() const
{
	return (y - width / 2.0);
}
double Rectangle2D::GetDown() const
{
	return (y + width / 2.0);
}

double Rectangle2D::GetArea()
{
	return width * height;
}

double Rectangle2D::GetPerimeter()
{
	return width * 2 + height * 2;
}

bool Rectangle2D::Contains(double x, double y)
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
	os << "Áß½É : (" << r.x << ", " << r.y << "), "
	   << "width : " << r.width << ", "
	   << "height : " << r.height << endl;
	return os;
}
