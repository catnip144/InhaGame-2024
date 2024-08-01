/*
Q1. 두 개의 원에 대해 중심점 좌표와 반지름을 입력 받아
	두 번째 원이 첫 번째 원의 내부에 있는지
	첫 번째 원과 겹치는지를 결정하는 프로그램을 작성하라.

	ex>
	첫 번째 원 x, y, r : 0.5 5.1 13
	두 번째 원 x, y, r : 1	 1.7 4.5
	두 번째 원은 첫 번째 원의 내부에 있다.

Q2.	두 직사각형에 대해 중심점이 (x, y), 폭 w, 높이 h
	를 입력받아 두 번째 직사각형이 첫 번째 직사각형의
	내부에 있는지, 첫 번째 직사각형과 겹치는지를 결정하는 프로그램을 작성하라.

	ex>
	첫 번째 사각형 x, y, w, h : 1 2  3    5.5
	두 번째 사각형 x, y, w, h : 3 4  4.5  5

	>> 두 번째 사각형은 첫 번째 사각형과 겹쳤다.
	>> 내부에 있다.
	>> 겹치지 않는다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void DetermineCirclePos();
template <typename T> void Swap(T& a, T& b);

struct Rect {
	double x;
	double y;
	double width;
	double height;

	double GetLeft() { return (x - width / 2.0); }
	double GetRight() { return (x + width / 2.0); }
	double GetUp() { return (y - width / 2.0); }
	double GetDown() { return (y + width / 2.0); }
};

bool IsRectOverlap(Rect& rect1, Rect& rect2)
{
	if (rect1.GetRight() < rect2.GetLeft())
		return false;
	
	if (rect1.GetLeft() > rect2.GetRight())
		return false;

	if (rect1.GetUp() > rect2.GetDown())
		return false;
	
	if (rect1.GetDown() < rect2.GetUp())
		return false;

	return true;
}

bool IsWithinSquare(Rect& rect1, Rect& rect2)
{
	if (rect1.GetLeft() > rect2.GetLeft())
		return false;

	if (rect1.GetRight() < rect2.GetRight())
		return false;

	if (rect1.GetUp() > rect2.GetUp())
		return false;

	if (rect1.GetDown() < rect2.GetDown())
		return false;

	return true;
}

int main()
{
	Rect rect1, rect2;

	cout << "첫 번째 사각형 x, y, w, h : ";
	cin >> rect1.x >> rect1.y >> rect1.width >> rect1.height;

	cout << "두 번째 사각형 x, y, w, h : ";
	cin >> rect2.x >> rect2.y >> rect2.width >> rect2.height;

	if (IsRectOverlap(rect1, rect2))
	{
		if (IsWithinSquare(rect1, rect2))
			cout << "두 번째 사각형은 첫 번째 사각형 내부에 있습니다." << endl;

		else if (IsWithinSquare(rect2, rect1))
			cout << "첫 번째 사각형은 두 번째 사각형 내부에 있습니다." << endl;

		else
			cout << "두 번째 사각형은 첫 번째 사각형과 접하거나 겹칩니다." << endl;
	}
	else
		cout << "두 사각형은 겹치지 않습니다." << endl;

	return 0;
}

void DetermineCirclePos()
{
	double x1, y1, r1, x2, y2, r2;

	cout << "첫 번째 원 x, y, r : ";
	cin >> x1 >> y1 >> r1;

	cout << "두 번째 원 x, y, r : ";
	cin >> x2 >> y2 >> r2;

	bool isSwapped = false;

	if (r1 > r2)
	{
		isSwapped = true;
		Swap(x1, x2);
		Swap(y1, y2);
		Swap(r1, r2);
	}
	double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	bool isOverlap = distance <= (r1 + r2);

	if (!isOverlap)
	{
		cout << "두 원은 겹치지 않습니다.";
		return;
	}
	bool isWithin = (r2 - distance) >= r1;
	if (isWithin)
	{
		if (isSwapped)
			cout << "두 번째 원은 첫 번째 원의 내부에 있습니다." << endl;
		else
			cout << "첫 번째 원은 두 번째 원의 내부에 있습니다." << endl;
	}
	else
		cout << "두 원은 겹칩니다." << endl;
}

template <typename T> void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}