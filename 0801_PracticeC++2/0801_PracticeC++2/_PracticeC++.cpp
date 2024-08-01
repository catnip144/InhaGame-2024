/*
Q3.	동전을 백만 번 던지는 것을 시뮬레이션 하고
	앞면과 뒷면이 나오는 수를 출력하는 프로그램을 작성하라.
	다음과 같이 각각 앞뒤가 몇 %씩 나오는지 계산해 출력하라.

	ex>
		100			번째일 때 .. 앞면 00% 뒷면 00%
		1000		번째일 때 .. 앞면 00% 뒷면 00%
		10000		번째일 때 .. 앞면 00% 뒷면 00%
		...
		1000000		번째일 때 .. 앞면 00% 뒷면 00%
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void SrandThrow(int throws)
{
	int n = throws;
	int heads = 0;
	int tails = 0;

	while (n--)
	{
		if (rand() % 2) heads++;
		else tails++;
	}
	double headsPercent = (double)heads / throws * 100;
	double tailsPercent = (double)tails / throws * 100;

	cout << "앞면: " << headsPercent << '%' << "  뒷면: " << tailsPercent << '%' << endl;
}

int main()
{
	int throws;
	cout << "던질 횟수: ";
	cin >> throws;

	srand((unsigned int)time(NULL));
	SrandThrow(throws);
	
	return 0;
}

