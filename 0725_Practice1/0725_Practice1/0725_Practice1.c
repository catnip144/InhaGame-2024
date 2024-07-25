/*
Q1. 삼각형의 3개의 점 (x1, y1), (x2, y2), (x3, y3)를 알고 있을 때
이 삼각형의 면적을 구하는 프로그램을 작성하라.
ex> 세 점 입력: 1.5 -3.4 4.6 5 9.5 -3.4
	삼각형의 면적 : 33.6

	헤론의 공식 적용
	
Q2. 게임에서 비밀번호에 어떤 규칙을 요구하는 경우가 있다.
	다음과 같이 비밀번호를 만들어야 한다고 하자.
	1. 비밀번호는 적어도 8개의 문자여야 한다.
	2. 비밀번호는 적어도 두 개의 숫자가 포함되어야 한다.
	사용자가 비밀번호를 입력했을 때

	위 규칙에 맞으면 "Valid Password" 를 출력하고
	그렇지 않으면 "Invalid Password" 를 출력하라.

	c++로 작성
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double GetDistance(double x1, double y1, double x2, double y2);
void GetTriangleArea();


void CreatePassword()
{
	
}


void main()
{
	
}

double GetDistance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void GetTriangleArea()
{
	double x1, y1, x2, y2, x3, y3;

	printf("세 점 입력: ");
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

	double side1 = GetDistance(x1, y1, x2, y2);
	double side2 = GetDistance(x2, y2, x3, y3);
	double side3 = GetDistance(x1, y1, x3, y3);

	printf("%lf %lf %lf\n", side1, side2, side3);

	double s = (side1 + side2 + side3) / 2.0f;
	double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

	printf("삼각형의 면적: %lf", area);
}