/*
	Q1. 다음을 포함하는 Circle2D 클래스를 정의하라.
		- 원의 중심을 나타내는 x,y 라는 두 개의 double 데이터 필드와 get 상수 함수
		- double 데이터 필드의 radius와 get 상수 함수

		- (x, y) 가 (0, 0), radius가 1인 기본원을 생성하는 인수 없는 생성자
		- 지정된 x,y 와 radius로 원을 생성하는 생성자
		- 원의 면적을 반환하는 getArea() 상수 함수
		- 원의 둘레를 반환하는 getPerimeter() 상수 함수

		- 지정된 점 (x, y)가 생성된 원 내부에 있을 경우, true를 반환하는
			contains(double x, double y) 상수 함수
		- 지정된 원이 생성된 원 내부에 있을 경우 true를 반환하는 contains(Circle2D& circle) 상수 함수
		- 지정된 원이 생성된 원과 중첩되는 경우, true를 반환하는 overlaps(const Circle2D& circle) 상수 함수
		
		- 클래스에 대한 UML 다이어그램

		Circle2D 객체 c1(2, 2, 5.5), c2(2, 2, 5.5), c3(4, 5, 10.5)를 생성하고
		c1의 면적과 둘레,
		c1.contains(3, 3), c1.contains(c2), c1.overlaps(c3) 결과를 화면에 출력하라.

*/
#include "circle2d.h"

int main()
{
	Circle2D c1(2, 2, 5.5);
	Circle2D c2(2, 2, 5.5);
	Circle2D c3(4, 5, 10.5);

	cout << "원 c1 : " << c1;
	cout << "원 c2 : " << c2;
	cout << "원 c3 : " << c3;
	cout << endl;

	cout << "원 c1 면적 : ";
	cout << c1.GetArea() << endl << endl;

	cout << "원 c1 둘레 : ";
	cout << c1.GetPerimeter() << endl << endl;

	cout << "원 c1이 점 3, 3을 포함하는가? : ";
	cout << c1.Contains(3, 3) << endl << endl;

	cout << "원 c1이 원 c2를 포함하는가? : ";
	cout << c1.Contains(c2) << endl << endl;

	cout << "원 c1과 원 c3이 중첩되는가? : ";
	cout << c1.Overlaps(c3) << endl << endl;

	return 0;
}

