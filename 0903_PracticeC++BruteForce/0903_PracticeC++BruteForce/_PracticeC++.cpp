/*
	Q1. 브루트 포스법을 이용하여 문자열 검색 프로그램을 작성하라.
		검색과정을 p306 문제 9처럼 표현
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

void PrintProgress(string& text, string& pattern, int i, int j, bool isMatch)
{
	char c = isMatch ? '+' : '|';

	if (j == 0) cout << " ";
	else cout << "  ";

	cout << text << endl << "  ";

	for (int k = 0; k < i; k++)
		cout << " ";

	for (int k = 0; k < j; k++)
		cout << " ";

	cout << c << endl << "  ";

	for (int k = 0; k < i; k++)
		cout << " ";

	cout << pattern << endl << endl;
}

int main()
{
	cout << "=== Brute Force ===\n";

	string text;
	cout << "텍스트: ";
	cin >> text;

	string pattern;
	cout << "패턴: ";
	cin >> pattern;

	int cmpCount = 0;
	int match = -1;

	for (int i = 0; i <= text.size() - pattern.size(); i++)
	{
		bool isMatch = true;
		cout << i;

		for (int j = 0; j < pattern.size(); j++)
		{
			cmpCount++;
			if (pattern[j] != text[i + j])
			{
				isMatch = false;
				PrintProgress(text, pattern, i, j, false);
				break;
			}
			PrintProgress(text, pattern, i, j, true);
		}
		if (isMatch)
		{
			match = i + 1;
			break;
		}
	}
	cout << "비교를 " << cmpCount << "회 시도합니다.\n";

	if (match != -1)
		cout << match << "번째에 일치합니다.\n";
	else
		cout << "패턴이 존재하지 않습니다.\n";

	return 0;
}

