#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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

void CreateTable(unordered_map<char, int>& charMap, string& pattern)
{
	int ptrnLength = pattern.size();
	for (int i = 0; i < ptrnLength - 1; i++)
		charMap[pattern[i]] = (ptrnLength - 1) - i;
}

int BoyerMoore(unordered_map<char, int>& charMap, string& text, string& pattern)
{
	int textLength = text.size();
	int ptrnLength = pattern.size();
	int i = ptrnLength - 1;

	while (i < textLength)
	{
		int pivot = i;
		int j = ptrnLength - 1;

		while (j >= 0)
		{
			if (text[i] != pattern[j])
			{
				PrintProgress(text, pattern, i, i - j, false);
				i = charMap.count(text[i]) ? pivot + charMap[text[i]] : pivot + ptrnLength;
				break;
			}
			PrintProgress(text, pattern, i, i - j, true);
			i--;
			j--;
		}
		if (j < 0)
			return i + 1;
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

	unordered_map<char, int> charMap;

	CreateTable(charMap, pattern);

	cout << "=== Table ===" << endl;
	for (char& p : pattern)
	{
		cout << p << " : ";
		if (charMap[p])
			cout << charMap[p] << endl;
		else
			cout << pattern.size() << endl;
	}
	cout << "Other : " << pattern.size() << endl;
	cout << endl;

	int matchIdx = BoyerMoore(charMap, text, pattern);

	if (matchIdx != -1)
		cout << matchIdx + 1 << "번째에서 발견" << endl;
	else
		cout << "찾지 못했습니다." << endl;

	return 0;
}