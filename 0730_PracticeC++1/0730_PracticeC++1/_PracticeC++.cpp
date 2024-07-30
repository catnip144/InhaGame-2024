/*
Q1. 점 (x1, y1) 을 입력받아 그 점이 (x0, y0)을 중심으로 하고
	반지름 r인 원의 내부에 존재하는지 검사하는 프로그램을 작성하라.

	ex>
	input > r : 10, x0 = 0, y0 = 0, x1 = 4, y1 = 5
	output > 점 (4, 5)는 중점이 (0, 0)이고 반지름이 10인 원 안에 있습니다.

	점이 원 내부에 존재하는지 검사하는 함수를 만들고,
	점 (x1, y1), (x0, y0)를 인자로 넘겨줄 때 포인터 구조체를 이용해서 만들 것
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

struct Position {
	int x;
	int y;
};

bool isWithinCircle(Position& pos, double radius)
{
	double distance1 = sqrt(pow(pos.x, 2) + pow(pos.y, 2));
	return (radius >= distance1);
}

int main()
{
	double radius;
	cout << "원의 반지름 : ";
	cin >> radius;

	Position pos1;
	cout << "점의 위치 : ";
	cin >> pos1.x >> pos1.y;
	
	if (isWithinCircle(pos1, radius))
		cout << "점 (" << pos1.x << ", " << pos1.y << ")는 중점이 (0, 0)이고 반지름이 " << radius << "인 원 안에 있습니다.";
	else
		cout << "원 안에 존재하지 않습니다.";

	return 0;
}

