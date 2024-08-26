/*
Q2. Merge Sort 구현
	비교 횟수, 교환 횟수 출려해서 이전 알고리즘과 비교
	속도 비교할것.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "stopwatch.h"

int cmpCount = 0;
int swpCount = 0;

using namespace std;

void QuickSort(vector<int>& nums, int start, int end)
{
	if (end <= start)
		return;

	int pivot = start;
	int pl = start + 1;
	int pr = end;

	while (pl <= pr)
	{
		while (pl < end && nums[pl] <= nums[pivot])
		{
			++cmpCount;
			++pl;
		}
		while (pr > start && nums[pr] >= nums[pivot])
		{
			++cmpCount;
			--pr;
		}
		if (pl >= pr)
		{
			++cmpCount;
			break;
		}
		++swpCount;
		int temp = nums[pl];
		nums[pl] = nums[pr];
		nums[pr] = temp;
	}
	++swpCount;
	int temp = nums[pivot];
	nums[pivot] = nums[pr];
	nums[pr] = temp;

	QuickSort(nums, start, pr - 1);
	QuickSort(nums, pr + 1, end);
}

void MergeSort(vector<int>& nums, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);

	vector<int> temp;
	int leftIdx = left;
	int rightIdx = mid + 1;

	while (leftIdx <= mid && rightIdx <= right)
	{
		++cmpCount;
		++swpCount;
		if (nums[leftIdx] < nums[rightIdx])
			temp.push_back(nums[leftIdx++]);
		else
			temp.push_back(nums[rightIdx++]);
	}
	while (leftIdx <= mid)
	{
		++swpCount;
		temp.push_back(nums[leftIdx++]);
	}

	while (rightIdx <= right)
	{
		++swpCount;
		temp.push_back(nums[rightIdx++]);
	}
	for (int i = left; i <= right; i++)
		nums[i] = temp[i - left];
}

int main()
{
	int n;
	cout << "정수 배열 크기 입력: ";
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		nums[i] = i + 1;

	srand(time(NULL));
	random_shuffle(nums.begin(), nums.end());

	vector<int> temp = nums;
	StopWatch watch;

	watch.Start();
	QuickSort(nums, 0, n - 1);
	watch.Stop();

	cout << "=== Quick Sort === \n";
	cout << "비교 횟수: " << cmpCount << endl;
	cout << "대입 횟수: " << swpCount << endl;
	cout << "시간: " << watch.GetElapsedTime() << " ms" << endl << endl;

	temp = nums;
	cmpCount = swpCount = 0;
	watch.Start();
	MergeSort(nums, 0, n - 1);
	watch.Stop();

	cout << "=== Merge Sort === \n";
	cout << "비교 횟수: " << cmpCount << endl;
	cout << "대입 횟수: " << swpCount << endl;
	cout << "시간: " << watch.GetElapsedTime() << " ms" << endl << endl;

	return 0;
}

