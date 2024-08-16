#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stopwatch.h"

using namespace std;

int n;

void PrintProgress(vector<int>& nums, int startPos, int endPos)
{
	for (int i = 0; i < startPos; i++)
		cout << "  ";
	cout << "*";

	if (startPos != endPos)
	{
		for (int i = 0; i < endPos - startPos - 1; i++)
			cout << "  ";
		cout << " +";

		for (int i = 0; i < n - endPos; i++)
			cout << "  ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
	cout << endl;
}

void SelectionSort1(vector<int>& nums)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (nums[minIndex] > nums[j])
				minIndex = j;
		}
		//PrintProgress(nums, i, minIndex);
		int temp = nums[i];
		nums[i] = nums[minIndex];
		nums[minIndex] = temp;
	}
}

void SelectionSort2(vector<int>& nums)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nums[i] > nums[j])
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

void BubbleSort3(vector<int>& nums)
{
	int temp;
	int limit = n - 1;

	for (int i = 0; i < limit; i++)
	{
		int lastExchanged = -1;

		for (int j = 0; j < limit; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				lastExchanged = j;

				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
		limit = lastExchanged;
	}
}

void MeasureTime(vector<int>& nums)
{
	StopWatch watch;

	vector<int> temp = nums;
	watch.Start();
	SelectionSort1(temp);
	watch.Stop();

	cout << "Selection Sort 1 : " << watch.GetElapsedTime() << " ms" << endl;

	temp = nums;
	watch.Start();
	SelectionSort2(temp);
	watch.Stop();

	cout << "Selection Sort 2 : " << watch.GetElapsedTime() << " ms" << endl;

	temp = nums;
	watch.Start();
	BubbleSort3(temp);
	watch.Stop();

	cout << "Bubble Sort 3 : " << watch.GetElapsedTime() << " ms" << endl;
}

int main()
{
	vector<int> nums;

	cout << "배열의 크기: ";
	cin >> n;

	for (int i = 0; i < n; i++)
		nums.push_back(i);
	random_shuffle(nums.begin(), nums.end());

	//SelectionSort1(nums);
	MeasureTime(nums);

	return 0;
}