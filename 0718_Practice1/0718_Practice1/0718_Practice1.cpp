#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

/*
Q2. 단어를 입력받아서 회문인지 여부를 판단해서 결과를 출력하는 프로그램을 작성하라.
	
	단어 입력 : level
	level은 회문입니다.

	단어 입력 : animal
	animal은 회문이 아닙니다.
*/

using namespace std;

int main()
{
	string word;

	cout << "단어 입력 : ";
	cin >> word;

	int left = 0;
	int right = word.size() - 1;
	bool isPalindrome = true;

	while (left < right)
	{
		if (word[left] != word[right])
		{
			isPalindrome = false;
			break;
		}
		left++;
		right--;
	}
	cout << word;

	if (isPalindrome)
		cout << "은 회문입니다.";
	else
		cout << "은 회문이 아닙니다.";
	cout << endl;
}
