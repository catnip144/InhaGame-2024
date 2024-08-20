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

int swpCount = 0;
int cmpCount = 0;

void ShellSort(vector<int>& nums, int n)
{
	int distance = n / 3 + 1;
	while (distance)
	{
		for (int k = 0; k < n; k++)
		{
			for (int i = k + distance; i < n; i += distance)
			{
				int temp = nums[i];

				// j는 최종적으로 i번째 요소와 교환될 위치를 가리키게 된다 
				int j;

				for (j = i; (j >= distance && temp < nums[j - distance]); j -= distance)
				{
					++cmpCount;
					cout << nums[j - distance] << " 와 " << temp << " 를 비교\n";
					nums[j] = nums[j - distance];
				}
				// 교환될 위치가 자기 자신이 아닐 경우
				if (i != j)
				{
					++swpCount;
					cout << nums[j] << " 와 " << temp << " 를 교환\n";
					nums[j] = temp;

					cout << ">> ";
					for (auto num : nums)
						cout << num << " ";
					cout << "\n\n";
				}
			}
		}
		if (distance == 1) break;
		distance = distance / 3 + 1;
	}
}

int main()
{
	int n;
	vector<int> nums;
	srand(time(NULL));

	cout << "배열의 크기: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
		nums.push_back(i);

	random_shuffle(nums.begin(), nums.end());

	for (auto num : nums)
		cout << num << " ";
	cout << endl << endl;

	ShellSort(nums, n);

	return 0;
}

