/*
	Counting Sort 구현
	이전 알고리즘과 속도 비교
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stopwatch.h"

using namespace std;

void CountingSort(vector<int>& nums)
{
	int maxNum = *max_element(nums.begin(), nums.end());
	vector<int> count(maxNum + 1);

	for (const int& num : nums)
		++count[num];

	nums.clear();
	for (int i = 0; i <= maxNum; i++)
	{
		for (int j = 0; j < count[i]; j++)
			nums.push_back(i);
	}
}

void CountingSort2(vector<int>& nums)
{
	int maxNum = *max_element(nums.begin(), nums.end());
	vector<int> count(maxNum + 1);

	for (const int& num : nums)
		++count[num];

	for (int i = 1; i <= maxNum; i++)
		count[i] += count[i - 1];

	vector<int> sorted(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		int countSum = count[nums[i]]--;
		sorted[countSum - 1] = nums[i];
	}
	for (int i = 0; i < nums.size(); i++)
		nums[i] = sorted[i];
}

int main()
{
	int n;
	cout << "배열 크기 입력: ";
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	//srand(time(NULL));
	//random_shuffle(nums.begin(), nums.end());

	CountingSort2(nums);

	for (int num : nums)
		cout << num << " ";
	cout << endl;

	return 0;
}

