//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <vector>
//#include "stopwatch.h"
//
//using namespace std;
//
//#define TABLE_SIZE 128
//
//void PrintProgress(string& text, string& pattern, int i, int j, bool isMatch)
//{
//	char c = isMatch ? '+' : '|';
//	cout << text << endl;
//
//	for (int k = 0; k < i; k++)
//		cout << " ";
//	cout << c << endl;
//
//	for (int k = 0; k < j; k++)
//		cout << " ";
//	cout << pattern << endl << endl;
//}
//
//void CreateTable_BM(string& pattern, vector<int>& table)
//{
//	int length = pattern.size();
//
//	for (int i = 0; i < length - 1; i++)
//		table[pattern[i]] = length - i - 1;
//}
//
//int BoyerMoore(string& text, string& pattern, vector<int>& table)
//{
//	int ptrnSize = pattern.size();
//	int i = ptrnSize - 1;
//
//	while (i < text.size())
//	{
//		bool isMatch = true;
//
//		for (int j = ptrnSize - 1; j >= 0; j--)
//		{
//			if (text[i - (ptrnSize - 1 - j)] != pattern[j])
//			{
//				//PrintProgress(text, pattern, i - (ptrnSize - 1 - j), i - ptrnSize + 1, false);
//				i += table[text[j]];
//				j = ptrnSize - 1;
//				isMatch = false;
//				break;
//			}
//			//PrintProgress(text, pattern, i - (ptrnSize - 1 - j), i - ptrnSize + 1, true);
//		}
//		if (isMatch)
//			return i - ptrnSize + 1;
//	}
//	return -1;
//}
//
//int KMP(vector<int>& table, string& text, string& pattern)
//{
//	int i = 0, j = 0;
//	while (i < text.size() && j < pattern.size())
//	{
//		if (text[i] == pattern[j])
//		{
//			//PrintProgress(text, pattern, i, j, true);
//			++j;
//			++i;
//		}
//		else if (j == 0)
//		{
//			//PrintProgress(text, pattern, i, j, false);
//			++i;
//		}
//		else
//		{
//			//PrintProgress(text, pattern, i, j, false);
//			j = table[j - 1];
//		}
//	}
//	if (j == pattern.size())
//		return i - j;
//	return -1;
//}
//
//void CreateTable_KMP(vector<int>& table, string& pattern)
//{
//	int i = 0;
//	while (i < pattern.size())
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			++i;
//			if (pattern[i] == pattern[j])
//				table[i] = table[i - 1] + 1;
//			else
//				break;
//		}
//	}
//}
//
//int BruteForce(string& text, string& pattern)
//{
//	for (int i = 0; i <= text.size() - pattern.size(); i++)
//	{
//		bool isMatch = true;
//
//		for (int j = 0; j < pattern.size(); j++)
//		{
//			if (pattern[j] != text[i + j])
//			{
//				isMatch = false;
//				break;
//			}
//		}
//		if (isMatch)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	string text, pattern;
//	cout << "문자열 입력: ";
//	cin >> text;
//
//	cout << "패턴 입력: ";
//	cin >> pattern;
//
//	StopWatch watch;
//	watch.Start();
//
//	vector<int> table1(TABLE_SIZE, pattern.size());
//	CreateTable_BM(pattern, table1);
//
//	//cout << "=== Table ===" << endl;
//	//for (char& p : pattern)
//	//	cout << p << " : " << table[p] << endl;
//	//cout << "Other : " << pattern.size() << endl;
//	//cout << endl;
//
//	int matchIdx = BoyerMoore(text, pattern, table1);
//	watch.Stop();
//
//	cout  << "Boyer Moore :\t" << matchIdx + 1 << "에서 발견,\t" << watch.GetElapsedTime() << "ms" << endl;
//
//	//if (matchIdx != -1)
//	//	cout << matchIdx + 1 << "번째에서 발견" << endl;
//	//else
//	//	cout << "찾지 못했습니다." << endl;
//
//	watch.Start();
//	vector<int> table2(pattern.size(), 0);
//	CreateTable_KMP(table2, pattern);
//	matchIdx = KMP(table2, text, pattern);
//	watch.Stop();
//	cout << "KMP :\t\t" << matchIdx + 1 << "에서 발견,\t" << watch.GetElapsedTime() << "ms" << endl;
//
//	watch.Start();
//	matchIdx = BruteForce(text, pattern);
//	watch.Stop();
//	cout << "Brute Force :\t" << matchIdx + 1 << "에서 발견,\t" << watch.GetElapsedTime() << "ms" << endl;
//
//
//	return 0;
//}
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define TABLE_SIZE 128

void PrintProgress(string& text, string& pattern, int i, int j, bool isMatch)
{
	char c = isMatch ? '+' : '|';
	cout << text << endl;

	for (int k = 0; k < i; k++)
		cout << " ";
	cout << c << endl;

	for (int k = 0; k < j; k++)
		cout << " ";
	cout << pattern << endl << endl;
}

void CreateTable(string& pattern, vector<int>& table)
{
	int length = pattern.size();

	for (int i = 0; i < length - 1; i++)
		table[pattern[i]] = length - i - 1;
}

int BoyerMoore(string& text, string& pattern, vector<int>& table)
{
	int ptrnSize = pattern.size();
	int i = ptrnSize - 1;

	while (i < text.size())
	{
		bool isMatch = true;

		for (int j = ptrnSize - 1; j >= 0; j--)
		{
			if (text[i + j - (ptrnSize - 1)] != pattern[j])
			{
				PrintProgress(text, pattern, i - (ptrnSize - 1 - j), i - ptrnSize + 1, false);
				i += table[text[i + j - (ptrnSize - 1)]];
				j = ptrnSize - 1;
				isMatch = false;
				break;
			}
			PrintProgress(text, pattern, i - (ptrnSize - 1 - j), i - ptrnSize + 1, true);
		}
		if (isMatch)
			return i - ptrnSize + 1;
	}
	return -1;
}

int main()
{
	string text, pattern;
	cout << "문자열 입력: ";
	getline(cin, text);

	cout << "패턴 입력: ";
	cin >> pattern;

	vector<int> table(TABLE_SIZE, pattern.size());
	CreateTable(pattern, table);

	cout << "=== Table ===" << endl;
	for (char& p : pattern)
		cout << p << " : " << table[p] << endl;
	cout << "Other : " << pattern.size() << endl;
	cout << endl;

	int matchIdx = BoyerMoore(text, pattern, table);

	if (matchIdx != -1)
		cout << matchIdx + 1 << "번째에서 발견" << endl;
	else
		cout << "찾지 못했습니다." << endl;

	return 0;
}