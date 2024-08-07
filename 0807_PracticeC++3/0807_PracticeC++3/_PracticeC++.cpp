/*
	다음 함수를 사용하여 값을 역으로 출력하는 코드를 작성하라.
	재귀호출을 이용하라.

	void reverseDisplay(int value);
	void reverseDisplay(const string &s);

	ex>
		> 12345
		>> 54321

	ex>
		> abcd
		>> dcba
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void reverseDisplay(int value);
void reverseDisplay(const string& s);

int main()
{
	string userInput;
	cout << ">";
	cin >> userInput;

	if (isdigit(userInput[0]))
		reverseDisplay(stoi(userInput));
	else
		reverseDisplay(userInput);

	return 0;
}

void reverseDisplay(int value)
{
	if (value == 0)
		return;

	cout << value % 10;
	reverseDisplay(value / 10);
}

void reverseDisplay(const string& s)
{
	if (s.size() == 0)
		return;

	cout << s.back();
	reverseDisplay(s.substr(0, s.size() - 1));
}

