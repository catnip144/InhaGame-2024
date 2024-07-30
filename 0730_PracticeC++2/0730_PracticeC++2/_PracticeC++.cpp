/*
Q2. 선1의 두점 (x1, y1)과 (x2, y2),
	선2의 두점 (x3, y3)과 (x4, y4)로 주어진 두 선의 교차점을 구하는 프로그램을 작성하라.

	ex	> 점 4개 입력: x1, y1, x2, y2, x3, y3, x4, y4

		> 2 2 5 -1.0 4.0 2.0 -1.0 -2.0
		>> 교차점은 (000, 000) 이다.

		> 2 2 7 6.0 4.0 2.0 -1.0 -2.0
		>> 두 직선은 평행이다.
*/

/*
	# 크래머 공식
	ax + by = e (x1, y1), (x2, y2)
	cx + dy = f (x3, y3), (x4, y4)

	ax1 - ax2 + by1 - by2 = 0
	a(x1 - x2) + b(y1 - y2) = 0
	
	a = y2 - y1; -(y1 - y2)
	b = x1 - x2;

	c = y4 - y3
	d = x3 - y4

	ax1 + by1 = e
	cx3 + dy3 = f

	유일한 해 x y

	    | e b |
	x = | f d |   =  (ed - bf) / (ad - bc)
	    -------
		| a b |
		| c d |
	
		| a e |
	y = | c f |   =  (af - ec) / (ad - bc)
	   ---------
	    | a b |
		| c d |
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

struct Position {
	double x;
	double y;
};

void Cramer(Position& pos1, Position& pos2, Position& pos3, Position& pos4)
{
	double a = pos2.y - pos1.y;
	double b = pos1.x - pos2.x;
	double c = pos4.y - pos3.y;
	double d = pos3.x - pos4.x;

	double e = a * pos1.x + b * pos1.y;
	double f = c * pos3.x + d * pos3.y;

	double parallel = a * d - b * c;
	if (!parallel)
	{
		cout << "두 직선은 평행하다.\n";
		return;
	}
	double x = (e * d - b * f) / parallel;
	double y = (a * f - e * c) / parallel;
	cout << "교차점은 (" << x << ", " << y << ") 이다.\n";
}


int main()
{
	Position pos1, pos2, pos3, pos4;

	cout << "점 4개 입력: ";
	cin >> pos1.x >> pos1.y
		>> pos2.x >> pos2.y
		>> pos3.x >> pos3.y
		>> pos4.x >> pos4.y;

	Cramer(pos1, pos2, pos3, pos4);
	return 0;
}

