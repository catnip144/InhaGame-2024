#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include "stopwatch.h"

using namespace std;

int swpCount = 0;
int cmpCount = 0;

void DownHeap(vector<int>& nums, int n, int j)
{
	while (j < n)
	{
		int leftChild = j * 2 + 1;
		int rightChild = j * 2 + 2;
		int larger = -1;

		cmpCount += 4;
		if (leftChild < n)
			larger = leftChild;

		if (rightChild < n && nums[larger] < nums[rightChild])
			larger = rightChild;

		if (larger == -1)
			break;

		if (nums[j] < nums[larger])
		{
			++swpCount;
			swap(nums[j], nums[larger]);
			j = larger;
		}
		else
			break;
	}
}

void ConvertHeap(vector<int>& nums)
{
	int n = nums.size();
	for (int i = n - 1; i > 0; i--)
	{
		++cmpCount;
		int parent = (i - 1) / 2;
		if (nums[i] > nums[parent])
		{
			++swpCount;
			swap(nums[i], nums[parent]);
			DownHeap(nums, n, i);
		}
	}
}

void HeapSort(vector<int>& nums)
{
	int sortRange = nums.size() - 1;

	while (sortRange)
	{
		swap(nums[0], nums[sortRange]);
		--sortRange;
		DownHeap(nums, sortRange + 1, 0);
	}
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
	cout << "배열의 크기를 입력: ";
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		nums[i] = i + 1;

	srand(time(NULL));
	random_shuffle(nums.begin(), nums.end());

	vector<int> temp = nums;
	StopWatch watch;

	watch.Start();
	ConvertHeap(nums);
	HeapSort(nums);
	watch.Stop();

	cout << "=== Heap Sort === \n";
	cout << "비교 횟수: " << cmpCount << endl;
	cout << "교환 횟수: " << swpCount << endl;
	cout << "시간: " << watch.GetElapsedTime() << " ms" << endl << endl;

	temp = nums;
	cmpCount = swpCount = 0;
	watch.Start();
	MergeSort(nums, 0, n - 1);
	watch.Stop();

	cout << "=== Merge Sort === \n";
	cout << "비교 횟수: " << cmpCount << endl;
	cout << "교환 횟수: " << swpCount << endl;
	cout << "시간: " << watch.GetElapsedTime() << " ms" << endl << endl;

	return 0;
}

