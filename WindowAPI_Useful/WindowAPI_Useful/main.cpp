/*
Q1.	x와 y축의 점을 표시하는 MyPoint 클래스를 설계하라.
	- 좌표를 나타내는 두 개의 x, y 데이터 필드
	- 점 (0, 0)을 생성하는 인수 없는 생성자
	- 지정 좌표의 점을 생성하는 생성자
	- x, y 데이터 필드를 위한 각각의 두 개의 get 함수
	- MyPoint 유형의 한 점에서 다른 점까지의 거리를 반환하는 distance 함수
	- 클래스에 대한 UML 다이어그램
	- 두 개의 점(0, 0)과 (10, 30.5)를 생성하고 두 점 사이의 거리를 표시하는 프로그램을 작성

	- 생성된 좌표의 점이 circle2D 클래스 객체나 Rectangle2D 객체의 내부에 있는지 여부를 판단하는
	  contains 함수를 MyPoint 객체를 인자로 하는 friend 함수를 구현하라.
*/
#include "mypoint.h"

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

