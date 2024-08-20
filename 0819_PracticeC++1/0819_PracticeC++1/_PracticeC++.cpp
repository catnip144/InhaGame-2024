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
			cout << ' ';

		cout << '*';
		int plusCount = max(0, i - 1);

		for (int p = 0; p < plusCount; p++)
			cout << '+';

		if (i != 0 && i != k - 1)
			cout << '*';
		cout << endl;
	}

	return 0;
}

