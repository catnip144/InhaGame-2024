#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintProgress(string& text, string& pattern, int i, int j, bool isMatch)
{
	char c = isMatch ? '+' : '|';
	cout << text << endl;

	for (int k = 0; k < i; k++)
		cout << " ";
	cout << c << endl;

	for (int k = 0; k < i - j; k++)
		cout << " ";
	cout << pattern << endl << endl;
}

void CreateTable(vector<int>& table, string& pattern)
{
	int i = 0;
	while (i < pattern.size())
	{
		for (int j = 0; j <= i; j++)
		{
			++i;
			if (pattern[i] == pattern[j])
				table[i] = table[i - 1] + 1;
			else
				break;
		}
	}
}

int KMP(vector<int>& table, string& pattern, string& text)
{
	int i = 0, j = 0;
	while (i < text.size() && j < pattern.size())
	{
		if (text[i] == pattern[j])
		{
			PrintProgress(text, pattern, i, j, true);
			++j;
			++i;
		}
		else if (j == 0)
		{
			PrintProgress(text, pattern, i, j, false);
			++i;
		}
		else
		{
			PrintProgress(text, pattern, i, j, false);
			j = table[j - 1];
		}
	}
	if (j == pattern.size())
		return i - j;
	return -1;
}

int main()
{
	string text;
	cout << "문자열 입력: ";
	cin >> text;

	string pattern;
	cout << "패턴 입력:";
	cin >> pattern;

	vector<int> table(pattern.size(), 0);
	CreateTable(table, pattern);

	cout << "=== Table ===" << endl;
	for (int& num : table)
		cout << num << " ";
	cout << endl << endl;

	int matchIdx = KMP(table, pattern, text);

	if (matchIdx != -1)
		cout << matchIdx + 1 << "번째에 일치합니다.\n";
	else
		cout << "패턴이 존재하지 않습니다.\n";

	return 0;
}

