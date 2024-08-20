#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintProgress(const vector<int>& nums, int start, int end)
{
	for (int num : nums)
		cout << num << " ";
	cout << endl;

	if (start == -1)
		return;
	
	for (int i = 0; i < start; i++)
		cout << "  ";

	if (start != end)
	{
		cout << "^-";
		for (int i = start; i < end - 1; i++)
			cout << "--";
	}
	cout << "+" << endl;
}

void InsertionSort(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); i++)
	{
		int temp = nums[i];
		int j;

		vector<int> previous = nums;
		for (j = i; j >= 1; j--)
		{
			if (nums[j - 1] > temp)
				nums[j] = nums[j - 1];
			else
				break;
		}
		nums[j] = temp;
		PrintProgress(previous, j, i);
	}
	PrintProgress(nums, -1, -1);
}

int main()
{
	vector<int> nums = { 6, 4, 8, 5, 2, 9, 7 };
	InsertionSort(nums);
}
