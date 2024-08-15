#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "stopwatch.h"

using namespace std;

int n;
int swpCount = 0;
int cmpCount = 0;

void PrintNums(int left, int right, vector<int>& nums, bool flag)
{
	for (int i = 0; i < left; i++)
		cout << nums[i] << "   ";
	
	cout << nums[left];
	if (flag) cout << " + ";
	else cout << " - ";
	cout << nums[right];

	for (int i = 0; i < n - 1 - right; i++)
		cout << "   " << nums[right + 1 + i];
	cout << endl;
}

void BubbleSort1(vector<int>& nums)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		//cout << endl << "패스" << i + 1 << ":" << endl;

		for (int j = 0; j < n - 1 - i; j++)
		{
			//bool flag = false;
			//++cmpCount;

			if (nums[j] > nums[j + 1])
			{
				//flag = true;
				//++swpCount;

				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
			//PrintNums(j, j + 1, nums, flag);
		}
	}
	//cout << endl;
}

void BubbleSort2(vector<int>& nums)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		//cout << endl << "패스" << i + 1 << ":" << endl;
		bool hasExchanged = false;

		for (int j = 0; j < n - 1 - i; j++)
		{
			//bool flag = false;
			//++cmpCount;

			if (nums[j] > nums[j + 1])
			{
				//flag = true;
				//++swpCount;

				hasExchanged = true;

				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
			//PrintNums(j, j + 1, nums, flag);
		}
		if (!hasExchanged)
			break;
	}
	//cout << endl;
}

void BubbleSort3(vector<int>& nums)
{
	int temp;
	int limit = n - 1;

	for (int i = 0; i < limit; i++)
	{
		//cout << endl << "패스" << i + 1 << ":" << endl;
		int lastExchanged = -1;

		for (int j = 0; j < limit; j++)
		{
			//bool flag = false;
			//++cmpCount;

			if (nums[j] > nums[j + 1])
			{
				//flag = true;
				//++swpCount;
				lastExchanged = j;

				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
			//PrintNums(j, j + 1, nums, flag);
		}
		limit = lastExchanged;
	}
	//cout << endl;
}

void Shuffle(vector<int>& nums)
{
	int repeat = 10;
	int maxSize = nums.size();
	srand(time(NULL));

	while (repeat--)
	{
		for (int i = 0; i < maxSize; i++)
		{
			int index = rand() % maxSize;
			int temp = nums[i];
			nums[i] = nums[index];
			nums[index] = temp;
		}
	}
}

int main()
{
	//vector<int> nums = { 1, 3, 9, 4, 7, 8, 6 };
	//n = nums.size();

	vector<int> nums;
	StopWatch watch;

	cout << "배열의 크기: ";
	cin >> n;

	for (int i = 0; i < n; i++)
		nums.push_back(i);
	Shuffle(nums);

	vector<int> copied = nums;

	watch.Start();
	BubbleSort1(copied);
	watch.Stop();

	cout << "Bubble Sort 1 걸린 시간: " << watch.GetElapsedTime() << " ms" << endl;

	copied = nums;

	watch.Start();
	BubbleSort2(copied);
	watch.Stop();

	cout << "Bubble Sort 2 걸린 시간: " << watch.GetElapsedTime() << " ms" << endl;

	copied = nums;

	watch.Start();
	BubbleSort3(copied);
	watch.Stop();

	cout << "Bubble Sort 3 걸린 시간: " << watch.GetElapsedTime() << " ms" << endl;

	return 0;
}

