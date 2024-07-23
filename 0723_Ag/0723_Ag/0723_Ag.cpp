#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cmath>

#define STRSIZE 50

using namespace std;

/*
Q1. 비행기의 가속도 a와 이륙속도 v가 주어졌을 떄
비행기가 이륙하기 위한 최소 활주 길이를 계산하는 프로그램을 작성하라.

길이 = v^2 / 2a
사용자에게 (m/s 단위로 v)와 (m/s^2 단위로 a)를 입력 받도록 알려주고,
최소 활주 길이를 출력하는 프로그램을 작성

ex > Speed and Acceleration : 60 3.5
	 Minimum runway length : 514.286

Q2.
두점 (x1, y1), (x2, y2)를 입력받아 이 두 점 사이의 거리를 출력하는 프로그램을 작성

거리 계산 공식 : SQUARE ROOT ( (x2 - x1)^2 + (y2 - y1)^2 )

ex> x1, y1 : 1.5	-3.4
	x2, y2 : 4		5

	Distance : 8.7641

Q3. c++ 기초 플러스 p368 4번
+a. 회원등록 -> 파일 저장
b. 실명으로 열람
...
e. 회원이 지정한 것으로 열람
q. 종료

*/

void RunwayLengthCalculator()
{
	double speed, acceleration;
	cout << "Speed and Acceleration : ";
	cin >> speed >> acceleration;

	double runwayLength = pow(speed, 2) / (acceleration * 2);
	cout << "Minimum runway length : " << runwayLength;
}

void DistanceCalculator()
{
	double x1, y1, x2, y2;
	cout << "x1, y1 : ";
	cin >> x1 >> y1;

	cout << "x2, y2 : ";
	cin >> x2 >> y2;

	double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	cout << "Distance : " << distance;
}

int main()
{
	DistanceCalculator();
}
