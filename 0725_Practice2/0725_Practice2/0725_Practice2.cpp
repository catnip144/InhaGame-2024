/*
Q2. 게임에서 비밀번호에 어떤 규칙을 요구하는 경우가 있다.
	다음과 같이 비밀번호를 만들어야 한다고 하자.
	1. 비밀번호는 적어도 8개의 문자여야 한다.
	2. 비밀번호는 적어도 두 개의 숫자가 포함되어야 한다.
	사용자가 비밀번호를 입력했을 때

	위 규칙에 맞으면 "Valid Password" 를 출력하고
	그렇지 않으면 "Invalid Password" 를 출력하라.

	c++로 작성
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void CreatePassword()
{
	bool hasCreatedPassword = false;

	while (!hasCreatedPassword)
	{
		int numCount = 0;
		string password;
		bool invalidPassword = false;
		bool isNotAlnum = false;

		cout << "생성할 비밀번호 입력: ";
		cin >> password;

		for (const auto& c : password)
		{
			if (!isNotAlnum && !isalnum(c))
				isNotAlnum = true;
			
			if (isdigit(c))
				++numCount;
		}
		if (password.size() < 8)
		{
			invalidPassword = true;
			cout << "적어도 8개의 문자로 구성해주세요\n";
		}
		if (numCount < 2)
		{
			invalidPassword = true;
			cout << "적어도 2개의 숫자를 포함시켜주세요\n";
		}
		if (isNotAlnum)
		{
			invalidPassword = true;
			cout << "특수 문자가 있습니다.\n";
		}
		if (invalidPassword)
			cout << "Invalid Password\n\n";
		else
		{
			hasCreatedPassword = true;
			cout << "Valid Password\n\n";
		}
	}
}

int main()
{
	CreatePassword();
	return 0;
}

