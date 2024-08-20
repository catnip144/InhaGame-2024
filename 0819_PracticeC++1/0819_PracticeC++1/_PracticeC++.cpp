/*
	삼각형 찍기
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "3 ~ 99 사이 홀수 입력: ";
	int k;
	cin >> k;

	int half = k / 2;

	for (int i = 0; i <= half; i++)
	{
		for (int j = half - i; j > 0; j--)
			cout << "  ";

		cout << "* ";
		for (int j = 0; j < i + 1 - 2; j++)
			cout << "+ ";

		if (i != 0)
			cout << "* ";
		cout << endl;
	}
	for (int i = 0; i < half; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cout << "  ";

		cout << "* ";
		for (int j = 0; j < half - i - 2; j++)
			cout << "+ ";

		if (i != half - 1)
			cout << "* ";
		cout << endl;
	}

	return 0;
}

