/*
	Q1.	다음과 같은 형태로 출력하는 프로그램을 작성하라.
		n을 입력받아 다음과 같이 2^n 형태의 값들을 출력하도록 프로그램을 작성하라.
		ex> n = 3
					1
				1	2	1
			1	2	4	2	1
		1	2	4	8	4	2	1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++)
			cout << '\t';
		
		for (int j = 0; j <= i; j++)
			cout << pow(2, j) << '\t';

		for (int j = 0; j < i; j++)
			cout << pow(2, i - j - 1) << '\t';

		cout << endl;
	}

	return 0;
}

