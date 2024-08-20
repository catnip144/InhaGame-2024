/*
	Shell Sort 구현
	비교횟수와 교환횟수 출력
	1. 단순 삽입 정렬과 횟수 비교
	2. 단순 삽입 정렬과 속도 비교
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include "stopwatch.h"

using namespace std;

int cmpCount = 0;
int swpCount = 0;

void Swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void ShellSort(vector<int>& nums, int n)
{
	int distance = n / 3 + 1;
	while (1)
	{
		for (int i = distance; i < n; i++)
		{
			for (int j = i; j >= distance; j -= distance)
			{
				++cmpCount;
				if (nums[j - distance] > nums[j])
				{
					++swpCount;
					Swap(nums[j - distance], nums[j]);
				}
				else
					break;
			}
		}
		if (distance == 1) break;
		distance = distance / 3 + 1;
	}
}

void InsertionSort(vector<int>& nums, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = nums[i];
		int j;
		for (j = i; j >= 1; j--)
		{
			++cmpCount;
			if (nums[j - 1] > temp)
				nums[j] = nums[j - 1];
			else
				break;
		}
		++swpCount;
		nums[j] = temp;
	}
}

int main()
{
	int n;
	vector<int> nums;

	StopWatch watch;
	srand(time(NULL));

	cout << "배열의 크기: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
		nums.push_back(i);
	random_shuffle(nums.begin(), nums.end());
	cout << endl;

	vector<int> temp = nums;
	watch.Start();
	ShellSort(temp, n);
	watch.Stop();

	cout << "쉘 정렬 비교 횟수: " << cmpCount << endl;
	cout << "쉘 정렬 교환 횟수: " << swpCount << endl;
	cout << "걸린 시간: " << watch.GetElapsedTime() << "ms" << endl << endl;

	temp = nums;
	cmpCount = swpCount = 0;
	watch.Start();
	InsertionSort(temp, n);
	watch.Stop();

	cout << "삽입 정렬 비교 횟수: " << cmpCount << endl;
	cout << "삽입 정렬 교환 횟수: " << swpCount << endl;
	cout << "걸린 시간: " << watch.GetElapsedTime() << "ms" << endl << endl;

	return 0;
}

