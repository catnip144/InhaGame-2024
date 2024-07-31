/*
	자료구조, 알고리즘 122p Q4
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

int BinarySearch(vector<int>& nums, int target);
int SentinelLinearSearch(vector<int>& nums, int target);
void PrintGuideline(vector<int>& nums, int left, int right, int mid, bool isHeadLine = false);

int main()
{
	int n;
	cout << "배열 크기 : ";
	cin >> n;

	vector<int> nums(n + 1);
	clock_t startTime, endTime;

	for (int i = 0; i < n; i++)
		nums[i] = i;

	int targetIndex;
	float executionTime;
	
	//PrintGuideline(nums, 0, 0, 0, true);

	executionTime = 0;
	for (int target = 0; target < n; target++)
	{
		startTime = clock();
		targetIndex = BinarySearch(nums, target);
		endTime = clock();

		executionTime += (float)(endTime - startTime) / CLOCKS_PER_SEC;
	}
	cout << "0 ~ n-1 까지 각 숫자의 이진 탐색 실행 시간 합 : " << executionTime << endl << endl;

	executionTime = 0;
	for (int target = 0; target < n; target++)
	{
		startTime = clock();
		targetIndex = SentinelLinearSearch(nums, target);
		endTime = clock();

		executionTime += (float)(endTime - startTime) / CLOCKS_PER_SEC;
	}
	cout << "0 ~ n-1 까지 각 숫자의 보초법 실행 시간 합 : " << executionTime << endl << endl;

	return 0;
}

int BinarySearch(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		//PrintGuideline(nums, left, right, mid);

		if (nums[mid] == target)
			return mid;
		
		if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int SentinelLinearSearch(vector<int>& nums, int target)
{
	int n = nums.size() - 1;
	nums[n] = target;

	for (int i = 0; ; i++)
	{
		if (nums[i] == target)
		{
			if (i == n)
				return -1;
			else
				return i;
		}
	}
}


void PrintGuideline(vector<int>& nums, int left, int right, int mid, bool isHeadLine)
{
	if (isHeadLine)
	{
		cout << "   |";
		for (int i = 0; i < nums.size(); i++)
			cout << "   " << i;
		cout << "\n---+----";

		for (int i = 1; i < nums.size(); i++)
			cout << "----";
		cout << endl;
		return;
	}
	cout << "   |";

	int k = 2;
	if (left == right) k = 3;

	for (int i = 0; i < (left + 1) * 4 - k; i++)
		cout << " ";
	cout << "<-";

	for (int i = 0; i < (mid - left) * 4 - 1; i++)
		cout << " ";
	cout << "+";

	for (int i = 0; i < (right - mid) * 4 - 1; i++)
		cout << " ";
	cout << "->";

	cout << endl << "  " << mid << "|";

	for (int i = 0; i < nums.size(); i++)
		cout << "   " << nums[i];

	cout << endl << "   |" << endl;
}