#include "cobject.h"

CObject::CObject(double posX, double posY, CObjectType objectType)
{
	x = posX;
	y = posY;
	type = objectType;
	hasCollided = false;
	theta = rand() % 360;

	int min = MIN_RADIUS;
	int max = MAX_RADIUS;
	int range = max - min + 1;
	radius = rand() % range + min;

	min = 0;
	max = 360;
	range = max - min + 1;
	pair<double, double> direction = GetDirectionFromAngle(rand() % range + min);

	dirX = direction.first;
	dirY = direction.second;

	min = MIN_SPEED;
	max = MAX_SPEED;
	range = max - min + 1;
	moveSpeed = rand() % range + min;
}

pair<double, double> CObject::GetDirectionFromAngle(double angle)
{
	double rad = (angle * PI / 180.0);
	return { cos(rad), sin(rad) };
}

double CObject::Distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void CObject::Move()
{
	x += dirX * moveSpeed;
	y += dirY * moveSpeed;
}

void CObject::MoveBackwards()
{
	x -= dirX * moveSpeed;
	y -= dirY * moveSpeed;
}

void CObject::Rotate()
{
	theta = (theta - ROTATION_AMOUNT);
	if (theta <= 0) theta = 360;
}

void CObject::SetHasCollided(bool state)
{
	hasCollided = state;
}

void CObject::CollisionEvent(int modeNum, int i, int j, vector<CObject*>& objectList, RECT& rectView)
{
	CObject& obj1 = *objectList[i];
	CObject& obj2 = *objectList[j];
	CObjectType strongerType = (CObjectType)((obj2.type + 1) % MAX_OBJECT_TYPE);

	obj1.SetHasCollided(true);
	obj2.SetHasCollided(true);

	bool activateNormalCollision = (modeNum == 1 || (obj1.type == obj2.type));

	switch (modeNum)
	{
	case 2:
		if (strongerType == obj1.type)
		{
			obj1.radius += obj2.radius;
			objectList.erase(objectList.begin() + j);
			activateNormalCollision = true;
		}
		break;

	case 3:
		if (strongerType == obj1.type)
		{
			double h = obj2.radius / sqrt(8);
			double angle = 45;

			POINT splitPos[4] =
			{
				{obj2.x - h, obj2.y - h},
				{obj2.x + h, obj2.y - h},
				{obj2.x - h, obj2.y + h},
				{obj2.x + h, obj2.y + h}
			};
			for (int i = 0; i < 4; i++)
			{
				switch (obj2.type)
				{
				case OBJECT_CIRCLE:
					objectList.push_back(new Circle2D(splitPos[i].x, splitPos[i].y, obj2.type));
					break;

				case OBJECT_RECT:
					objectList.push_back(new Rectangle2D(splitPos[i].x, splitPos[i].y, obj2.type));
					break;

				case OBJECT_STAR:
					objectList.push_back(new Star2D(splitPos[i].x, splitPos[i].y, obj2.type));
					break;
				}
				pair<double, double> direction = GetDirectionFromAngle(angle + 90 * i);

				objectList.back()->moveSpeed = obj2.moveSpeed;
				objectList.back()->radius = obj2.radius / 4.0;
				objectList.back()->theta = obj2.theta;
				objectList.back()->dirX = direction.first;
				objectList.back()->dirY = direction.second;
				objectList.back()->AdjustPosition(rectView);
			}
			objectList.erase(objectList.begin() + j);
			activateNormalCollision = true;
		}
		break;

	default:
		break;
	}
	if (activateNormalCollision)
	{
		double direction = atan2(y - obj2.y, x - obj2.x);
		dirX = cos(direction);
		dirY = sin(direction);
	}
}

void CObject::Draw(HDC hdc) {}

void CObject::AdjustPosition(RECT& rectView)
{
	if (x > rectView.right - radius)
	{
		x = rectView.right - radius;
		dirX *= -1;
	}
	if (x < rectView.left + radius)
	{
		x = rectView.left + radius;
		dirX *= -1;
	}
	if (y < rectView.top + radius)
	{
		dirY *= -1;
		y = rectView.top + radius;
	}
	if (y > rectView.bottom - radius)
	{
		dirY *= -1;
		y = rectView.bottom - radius;
	}
}

bool CObject::Collision(const CObject& cObject)
{
	return (Distance(x, y, cObject.x, cObject.y) <= radius + cObject.radius);
}

Circle2D::Circle2D(double x, double y, CObjectType objectType) : CObject(x, y, objectType) {}

void Circle2D::Draw(HDC hdc)
{
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}

Rectangle2D::Rectangle2D(double x, double y, CObjectType objectType) : CObject(x, y, objectType) {}

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
}

Star2D::Star2D(double x, double y, CObjectType objectType) : CObject(x, y, objectType) {}

void Star2D::Draw(HDC hdc)
{
	POINT points[10];
	for (int i = 0; i < 5; i++)
	{
		POINT point;
		double rad = ((theta + (72 * i)) * PI / 180.0);

		point.x = x + radius * cos(rad);
		point.y = y - radius * sin(rad);
		points[2 * i] = point;
	}
	for (int i = 1; i < 10; i += 2)
	{
		POINT point;
		double x1 = points[i - 1].x;
		double y1 = points[i - 1].y;
		double x2 = points[(i + 3) % 10].x;
		double y2 = points[(i + 3) % 10].y;
		double x3 = points[(i + 1) % 10].x;
		double y3 = points[(i + 1) % 10].y;
		double x4 = points[(i + 7) % 10].x;
		double y4 = points[(i + 7) % 10].y;

		point.x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
		point.y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
		points[i] = point;
	}
	Polygon(hdc, points, 10);
}
