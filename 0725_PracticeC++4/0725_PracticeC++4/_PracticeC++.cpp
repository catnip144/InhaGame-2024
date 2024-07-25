/*
Q3. p464 10번 add(), minus()
두 개의 함수를 이용한 결과를 출력하라.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

double add(double x, double y);
double subtract(double x, double y);
double calculate(double x, double y, double (*pf)(double, double));

void main()
{
	double a, b;

	cout << "2개 숫자 입력 (덧셈) : ";
	cin >> a >> b;
	cout << "합 : " << calculate(a, b, add) << '\n';

	cout << "2개 숫자 입력 (뺄셈) : ";
	cin >> a >> b;
	cout << "합 : " << calculate(a, b, subtract) << '\n';
}

double add(double x, double y)
{
	return x + y;
}

double subtract(double x, double y)
{
	return x - y;
}

double calculate(double x, double y, double (*pf)(double, double))
{
	return pf(x, y);
}

