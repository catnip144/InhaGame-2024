#include "cobject.h"
#define PI 3.141592

CObject::CObject(double posX, double posY)
{
	x = posX;
	y = posY;
	theta = rand() % 360;
}

Circle2D::Circle2D(double x, double y) : CObject(x, y)
{
	int min = 10;
	int max = 60;
	int range = max - min + 1;
	radius = rand() % range + min;

	min = 0;
	max = 360;
	range = max - min + 1;

	double angle = rand() % range + min;
	double rad = (angle * PI / 180.0);
	double dx = cos(rad);
	double dy = sin(rad);

	double length = sqrt(pow(dx, 2) + pow(dy, 2));
	dirX = (double)dx / length;
	dirY = (double)dy / length;

	min = 5;
	max = 15;
	range = max - min + 1;
	moveSpeed = rand() % range + min;
}

void Circle2D::Draw(HDC hdc)
{
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}

Rectangle2D::Rectangle2D(double posX, double posY) : CObject(posX, posY)
{
	int min = 10;
	int max = 60;
	int range = max - min + 1;
	radius = rand() % range + min;

	min = 0;
	max = 360;
	range = max - min + 1;

	double angle = rand() % range + min;
	double rad = (angle * PI / 180.0);
	double dx = cos(rad);
	double dy = sin(rad);

	double length = sqrt(pow(dx, 2) + pow(dy, 2));
	dirX = (double)dx / length;
	dirY = (double)dy / length;

	min = 5;
	max = 15;
	range = max - min + 1;
	moveSpeed = rand() % range + min;
}

void Rectangle2D::Draw(HDC hdc)
{
	POINT points[4];

	for (int i = 0; i < 4; i++)
	{
		double rad = ((theta + (90 * i)) * PI / 180.0);

		points[i].x = x + radius * cos(rad);
		points[i].y = y - radius * sin(rad);
	}
	Polygon(hdc, points, 4);
	theta = (theta - 10);
	if (theta <= 0)
		theta = 360;
}
