/*
	C++ 책 1343쪽 문제 7번
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> Lotto(int maxNum, int totalNumbers)
{
	srand(time(NULL));

	vector<int> allNums, winners;
	for (int i = 1; i <= maxNum; i++)
		allNums.push_back(i);

	random_shuffle(allNums.begin(), allNums.end());

	for (int i = 0; i < 6; i++)
		winners.push_back(allNums[i]);

	sort(winners.begin(), winners.end());
	return winners;
}

int main()
{
	vector<int> winners = Lotto(45, 6);

	for (int i = 0; i < winners.size(); i++)
		cout << winners[i] << " ";
	cout << endl;
	return 0;
}

