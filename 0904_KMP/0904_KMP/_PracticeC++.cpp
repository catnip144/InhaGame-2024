/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void CreateChart(vector<int>& chart, string& text, string& pattern)
{
	for (int i = 0; i < text.size(); i++)
	{
		for (int j = 0; j < text.size(); j++)
		{

		}
	}
}

int main()
{
	string text;
	cout << "문자열 입력: ";
	cin >> text;

	string pattern;
	cout << "패턴 입력:";
	cin >> pattern;

	vector<int> chart;
	CreateChart(chart, text, pattern);



	return 0;
}

