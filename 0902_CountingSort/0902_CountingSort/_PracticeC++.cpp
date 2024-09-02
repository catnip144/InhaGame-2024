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

void QuickSort(vector<int>& nums, int start, int end)
{
	if (end <= start)
		return;

	int pivot = start;
	int pl = start + 1;
	int pr = end;

	// 엇갈리기 전까지 반복
	while (pl <= pr)
	{
		while (pl < end && nums[pl] <= nums[pivot])
			++pl;

		while (pr > start && nums[pr] >= nums[pivot])
			--pr;

		// 같은 위치 혹은 엇갈렸을 때
		if (pl >= pr)
			break;

		int temp = nums[pl];
		nums[pl] = nums[pr];
		nums[pr] = temp;
	}
	int temp = nums[pivot];
	nums[pivot] = nums[pr];
	nums[pr] = temp;

	QuickSort(nums, start, pr - 1);
	QuickSort(nums, pr + 1, end);
}


int main()
{
	int n;
	cout << "배열 크기 입력: ";
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		nums[i] = i + 1;

	srand(time(NULL));
	random_shuffle(nums.begin(), nums.end());

	for (int num : nums)
		cout << num << " ";
	cout << endl;

	CountingSort(nums);

	for (int num : nums)
		cout << num << " ";
	cout << endl;

	return 0;
}

