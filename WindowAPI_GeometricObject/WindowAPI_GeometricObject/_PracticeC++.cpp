/*
	Q1. GeometricObject를 베이스 클래스로 해서
		다음 클래스들을 설계하라
		Circle2D, Rectangle2D, MyPoint 클래스를
		추상 클래스 상속 개념을 적용하여 다시 작성하라.
*/
using namespace std;

#include "geometric.h"

int main()
{
	MyPoint a(0, 0);
	MyPoint b(10, 30.5);

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	cout << "두 점 사이의 거리: " << a.Distance(b) << endl << endl;

	Circle2D c(0, 0, 3);
	Rectangle2D r(0, 0, 3, 3);

	cout << "원 c : " << c;
	cout << "점 a가 원 c 내부에 있는가: " << Contains(a, c) << endl << endl;

	cout << "사각형 r : " << r;
	cout << "점 b가 사각형 r 내부에 있는가: " << Contains(b, r) << endl;

	return 0;
}

