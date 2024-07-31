/*
C++ 기초 플러스 5번, 6번
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

void Important()
{
	char* words[50];

	for (int i = 0; i < 5; i++)
	{
		words[i] = new char[100];
		cin >> words[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cout << words[i] << " ";
		delete words[i];
	}
}


template <typename T> T max5(vector<T>& nums)
{
	T maxNum = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (maxNum < nums[i])
			maxNum = nums[i];
	}
	return maxNum;
}

template <typename T> T maxn(vector<T>& elements)
{
	int maxIdx = 0;
	for (int i = 1; i < elements.size(); i++)
	{
		if (elements[maxIdx] < elements[i])
			maxIdx = i;
	}
	return elements[maxIdx];
}

//string& maxn(vector<string>& elements, int arrSize)
//{
//	int maxIdx = 0;
//	for (int i = 1; i < arrSize; i++)
//	{
//		if (elements[maxIdx].size() < elements[i].size())
//			maxIdx = i;
//	}
//	return elements[maxIdx];
//}

int main()
{
	//// 문제 5
	//cout << "=== 문제 5 ===\n";

	//vector<int> nums1(5, 0);
	//cout << "5개의 숫자 입력 (int) : ";

	//for (int i = 0; i < nums1.size(); i++)
	//	cin >> nums1[i];

	//int maxNum1 = max5(nums1);
	//cout << "int형 가장 큰 숫자 : " << maxNum1 << endl;

	//vector<double> nums2(5, 0);
	//cout << "5개의 숫자 입력 (double) : ";

	//for (int i = 0; i < nums2.size(); i++)
	//	cin >> nums2[i];

	//double maxNum2 = max5(nums2);
	//cout << "double형 가장 큰 숫자 : " << maxNum2 << endl;


	////// 문제 6
	cout << "\n=== 문제 6 ===\n";

	vector<int> nums3(6, 0);
	cout << "6개의 숫자 입력 (int) : ";

	for (int i = 0; i < nums3.size(); i++)
		cin >> nums3[i];

	int maxNum3 = maxn(nums3);
	cout << "int형 가장 큰 숫자 : " << maxNum3 << endl;

	vector<double> nums4(4, 0);
	cout << "4개의 숫자 입력 (double) : ";

	for (int i = 0; i < nums4.size(); i++)
		cin >> nums4[i];

	double maxNum4 = maxn(nums4);
	cout << "double형 가장 큰 숫자 : " << maxNum4 << endl;

	vector<string> words(5);
	cout << "5개의 단어 입력 : ";

	for (int i = 0; i < words.size(); i++)
		cin >> words[i];

	string maxLengthString = maxn(words, words.size());
	cout << "가장 긴 문자열 : " << maxLengthString << endl;
	

	return 0;
}

