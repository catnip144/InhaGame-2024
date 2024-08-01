/*
등급	아이템		확률		아이템		확률
----------------------------------------------------
5star	A-Item		1%
----------------------------------------------------
4star	B-Item		3%			C-Item		3%
----------------------------------------------------
3star	D-Item		5%			E-Item		5%
		F-Item		5%
----------------------------------------------------
2star	G-Item		10%			H-Item		10%
		I-Item		10%			J-Item		10%
----------------------------------------------------
1star	K-Item		38%
----------------------------------------------------

각 아이템이 지정된 확률에 맞게 정확히 나올 수 있도록 프로그램을 작성하시오.

ex> 횟수 ? 100		A : 1,	B : 3,	C : 3,	D : 5 ...............
	횟수 ? 1000		A : 10,	B : 30,	C : 30,	D : 50 ..............

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

struct Item
{
	string name;
	int count = 0;
	double percent;
};

int main()
{
	Item items[11] = {
		{"A", 0, 1},
		{"B", 0, 3},  {"C", 0, 3},
		{"D", 0, 5},  {"E", 0, 5},  {"F", 0, 5},
		{"G", 0, 10}, {"H", 0, 10}, {"I", 0, 10}, {"J", 0, 10},
		{"K", 0, 38}
	};
	int n;

	cout << "횟수 ? ";
	cin >> n;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		vector<int> candidates;
		bool hasFoundCandidate = false;
		int index = -1;

		while (!hasFoundCandidate)
		{
			int randPercent = rand() % 100 + 1; // 1 ~ 100

			for (int j = 0; j < 11; j++)
			{
				if (!hasFoundCandidate && (randPercent <= items[j].percent))
				{
					hasFoundCandidate = true;
					candidates.push_back(j);
				}
				else if (hasFoundCandidate)
				{
					if (items[candidates[0]].percent == items[j].percent)
						candidates.push_back(j);
					else
						break;
				}
			}
		}
		// 동일한 확률의 아이템들 중 하나를 뽑아야 할 경우 랜덤으로 선택
		index = candidates[rand() % candidates.size()];

		int maxCount = ceil(items[index].percent / 100.0 * n);

		if (items[index].count < maxCount)
		{
			cout << items[index].name << " ";
			items[index].count++;
		}
		else
			i--;
	}
	cout << endl;
	int totalItems = 0;
	for (int i = 0; i < 11; i++)
	{
		totalItems += items[i].count;
		cout << items[i].name << " : " << items[i].count << endl;
	}
	cout << "총 뽑은 아이템 수 : " << totalItems << endl;
	return 0;
}

