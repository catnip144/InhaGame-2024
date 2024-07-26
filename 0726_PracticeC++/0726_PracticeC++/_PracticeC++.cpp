/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

#define SIZE 200000000

int nums[SIZE + 1];

void LinearSearch(int nums[], int find_num);
void SentinelLinearSearch(int nums[], int find_num);

int main()
{
	int find_num;
	clock_t start, end;
	float res;

	for (int i = 0; i < SIZE; i++)
	{
		nums[i] = i;	// 그냥 0부터 99'999까지 넣는다 
	}

	while (1)
	{
		cout << "검색 데이터 > ";
		cin >> find_num;

		// 1. 일반 선형 검색 
		start = clock();
		LinearSearch(nums, find_num);
		end = clock();
		res = (float)(end - start) / CLOCKS_PER_SEC;
		printf("선형 검색 소요 시간: %.7f\n", res);


		// 2. 보초법
		nums[SIZE] = find_num;	// 보초법

		start = clock();
		SentinelLinearSearch(nums, find_num);
		end = clock();
		res = (float)(end - start) / CLOCKS_PER_SEC;
		printf("보초법 소요 시간: %.7f\n", res);

		cout << "\n\n";
	}
}

void LinearSearch(int nums[], int find_num)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (nums[i] == find_num)
		{
			cout << "> 자료 중에 " << find_num << "이(가) 있습니다.\n";
			return;
		}

		if (i == SIZE - 1)
		{
			cout << "> 자료 중에 " << find_num << "은(는) 없습니다.\n";
			return;
		}
	}
}

void SentinelLinearSearch(int nums[], int find_num)
{
	int i = 0;
	for (i; i <= SIZE; i++)
	{
		if (nums[i] == find_num)
		{
			break;
		}
	}

	if (i == SIZE) cout << "> 자료 중에 " << find_num << "은(는) 없습니다.\n";
	else cout << "> 자료 중에 " << find_num << "이(가) 있습니다.\n";
}