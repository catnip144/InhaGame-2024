/*
	하노이 타워
	원반 최대 크기(0:exit) : 3

   [3] [ ] [ ]
   [2] [ ] [ ]
   [1] [ ] [ ]
	A	B	C

	A -> B
	A -> C
	B -> C
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> towers(3);
int totalDisks;
int totalCount = 0;

void PrintTowers(vector<vector<int>>& towers)
{
	for (int i = totalDisks - 1; i >= 0; i--)
	{
		for (int t = 0; t < towers.size(); t++)
		{
			if (towers[t].size() > i)
				cout << "[" << towers[t][i] << "]";
			else
				cout << "[ ]";
			cout << " ";
		}
		cout << '\n';
	}
	cout << " A   B   C" << "\n\n";
}

void HanoiTower(int n, vector<int>& start, vector<int>& mid, vector<int>& to)
{
	if (n == 1)
	{
		to.push_back(start.back());
		start.pop_back();

		PrintTowers(towers);
		++totalCount;
		return;
	}
	HanoiTower(n - 1, start, to, mid);
	HanoiTower(1, start, mid, to);
	HanoiTower(n - 1, mid, start, to);
}

int main()
{
	cout << "원판 개수: ";
	cin >> totalDisks;

	for (int i = totalDisks; i >= 1; i--)
		towers[0].push_back(i);

	PrintTowers(towers);
	HanoiTower(totalDisks, towers[0], towers[1], towers[2]);

	cout << "총 옮긴 횟수 : " << totalCount << '\n';
	return 0;
}

