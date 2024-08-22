/*
	Quick Sort를 구현
	비교횟수, 교환 횟수, 이전 알고리즘 비교
	속도 측정 .. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

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
	cout << "배열 크기 입력: ";
	int n;
	cin >> n;

	vector<int> nums;
	for (int i = 1; i <= n; i++)
		nums.push_back(i);

	srand(time(NULL));
	random_shuffle(nums.begin(), nums.end());

	for (auto num : nums)
		cout << num << " ";
	cout << endl;
	
	QuickSort(nums, 0, n - 1);

	for (auto num : nums)
		cout << num << " ";
	cout << endl;

	return 0;
}

